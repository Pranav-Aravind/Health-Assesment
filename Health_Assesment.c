/*
Pranav Aravind
23205030
*/

#include <stdio.h>
#include <stdbool.h>

//declaring functions 
void BMI_Calculation();
void Blood_Pressure_Assessment();
void Cardiac_Risk_Score_Assessment();

//function to clear input buffer
void Clear_Buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/*function to print risk category that takes an integer with numbers 1 to 6 as argument for printing the risk category based on the number. It is 
much easier to call the function each time with an integer from 1 to 6 as argument than to copy paste the print statement for each risk category*/
void print_ERICE_risk_category(int erice_category) {
	switch(erice_category) {
		case 1:
			printf("\nERICE risk score category: Low (<5 percent)");
			break;
		case 2:
			printf("\nERICE risk score category: Mild (5 to 9 percent)");
			break;
		case 3:
			printf("\nERICE risk score category: Moderate (10 to 14 percent)");
			break;
		case 4:
			printf("\nERICE risk score category: Moderate-high (15 to 19 percent)");
			break;
		case 5:
			printf("\nERICE risk score category: High (20 to 29 percent)");
			break;
		case 6:
			printf("\nERICE risk score category: Very high (>=30 percent)");
			break;
	}
}

int main(void) {
	int choice;

/*loop with menu for prompting user to choose between 3 options and carry out a function for each of the 3 option or to exit the program (loops
until user chooses to exit the program). Inner loop to loop the menu prompt until user enters input only from the choices given (loops until user
enters an integer between 0 and 3). If user enters anything other than an integer the function to clear input buffer is called and the loop is
loop is entered again from the beginning*/
	do {
		do {
			printf("\n\n\nEnter your choice:\n\n\t1 for BMI (Body Mass Index) Calculation\n\t2 for Blood Pressure Assessment\n\t3 for Cardiac Risk Score Assessment\n\t0 to exit\n");
			
			if(scanf("%d", &choice) != 1) {
				Clear_Buffer(); 
				continue;
			}
		} while(choice < 0 || choice > 3);
		printf("\n");

		switch(choice) {
			case 1:
				BMI_Calculation();
				break;
			case 2:
				Blood_Pressure_Assessment();
				break;
			case 3:
				Cardiac_Risk_Score_Assessment();
				break;
		}
	} while (choice != 0);	
	
	return 0;
}

//function to calculate BMI
void BMI_Calculation() {
	double height, weight, BMI;
	/*loop prompting user to enter height until user enters valid input for height (non integer values and height too short or tall that it is not
	possible are taken to be invalid input)*/
	do {
		printf("Enter your height in metres(m): ");
		Clear_Buffer(); 
		continue;
	//loop prompting user to enter weight until user enters valid input for weight 
	} while(scanf("%lf", &height) != 1 || height < 0.2 || height > 3);
	printf("\n");

	do {
		printf("Enter your weight in kilograms(kg): ");
		Clear_Buffer(); 
		continue;
	} while(scanf("%lf", &weight) != 1 || weight < 1 || weight > 600);
	
	//calculating BMI and printing it
	BMI =  weight / (height * height);
	printf("\nYour BMI is %.1lf\n", BMI);

	//determining and prinitng weight category based on BMI value obtained
	if(BMI < 18.5) {
		printf("Weight Category: Underweight");
	} else if (BMI >= 18.5 && BMI <= 24.9) {
		printf("Weight Category: Normal weight");
	} else if(BMI >= 25 && BMI <= 29.9) {
		printf("Weight Category: Overweight");
	} else {
		printf("Weight Category: Obesity");
	}
}

void Blood_Pressure_Assessment() {
	int systolic_bp[5], diastolic_bp[5], sumsystolic_bp = 0, sumdiastolic_bp = 0, avgsystolic_bp = 0, avgdiastolic_bp = 0;
	//loop to get 5 systolic bp readings and inner loop to loop until user enters valid input
	for(int i = 0; i < 5; i++) {
		do {	
			printf("Enter reading %d for Systolic blood pressure in mmHg: ", i + 1);
			Clear_Buffer();
			continue;
		} while(scanf("%d", &systolic_bp[i]) != 1 || systolic_bp[i] < 40 || systolic_bp[i] > 400);
	//sum of each systolic bp reading
		sumsystolic_bp += systolic_bp[i];
		printf("\n");
	}
	printf("\n");
	//loop to get 5 diastolic bp readings and inner loop to loop until user enters valid input
	for(int i = 0; i < 5; i++) {	
		do {
			printf("Enter reading %d for Diastolic blood pressure in mmHg: ", i + 1);
			Clear_Buffer();
			continue;
		} while(scanf("%d", &diastolic_bp[i]) != 1 || diastolic_bp[i] < 10 || diastolic_bp[i] > 400);
	//sum of each diastolic reading
		sumdiastolic_bp += diastolic_bp[i];	
		printf("\n");
	}

	//dividing sum of 5 readings for both by 5 to get average and printing them
	avgsystolic_bp = sumsystolic_bp / 5;
	avgdiastolic_bp = sumdiastolic_bp / 5;

	printf("\nAverage Systolic blood pressure reading is %dmmHg\n", avgsystolic_bp);
	printf("Average Diastolic blood pressure reading is %dmmHg\n\n", avgdiastolic_bp);

	//determining and printing bp category based on average of systolic and diastolic bp values obtained
	if(avgsystolic_bp >= 140 || avgdiastolic_bp >= 90) {
		printf("Blood Pressure Category: High Blood Pressure");
	} else if(avgsystolic_bp <= 90 || avgdiastolic_bp <= 60) {
		printf("Blood Pressure Category: Low Blood Pressure");
	} else if( (avgsystolic_bp >= 120 && avgsystolic_bp < 140) || (avgdiastolic_bp >= 80 && avgdiastolic_bp < 90) ) {
		printf("Blood Pressure Category: Pre-high Blood Pressure");
	} else {
		printf("Blood Pressure Category: Ideal Blood Pressure");
	}	
}

void Cardiac_Risk_Score_Assessment() {
	int age, sex, diabetic, smoker, erice_SBP, erice_category;
	double cholestrol_level;
	//loop prompting user to enter (only 30 or above) if 30 or above or to enter -1 to end function and exit to menu until user enters valid input 
	do {	
		if(age == -1) {
			return;
		}
		printf("\n\nCardiac risk score data available only for age 30 and above\n\nEnter your age (only for age 30 and above) or Enter -1 to exit to menu: ");
		Clear_Buffer(); 
		continue;
	}while(scanf("%d", &age) != 1 || age < 30 || age > 180);
	/*for ages below 40 and ages 80 or above and in women aged below 50 other factors do not determine risk category and in women cholestrol does
	not determine risk category. User is prompted to enter all the factors neccesary to determine risk category and for each factor it loops until
	user enters valid input. If user enters all the factors neccesary to determine risk category the determined risk category is printed*/
	if(age < 40) {
		print_ERICE_risk_category(1);
	} else if(age >= 80) {
		print_ERICE_risk_category(6);
	} else {
		do {
			printf("\nEnter your sex:\n\tEnter 1 for man\n\tEnter 0 for woman\n");
			Clear_Buffer(); 
			continue;
		} while(scanf("%d", &sex) != 1 || (sex != 0 && sex != 1));
	
		if(sex == 0 && age < 50) {
			print_ERICE_risk_category(1);
		} else {
			do {
				printf("\nDo you have diabetes?\n\tEnter 1 for yes\n\tEnter 0 for no\n");
				Clear_Buffer(); 
				continue;
			} while(scanf("%d", &diabetic) != 1 || (diabetic != 0 && diabetic != 1));

			do {
				printf("\nAre you a smoker?\n\tEnter 1 for yes\n\tEnter 0 for no\n");
				Clear_Buffer(); 
				continue;
			} while(scanf("%d", &smoker) != 1 || (smoker != 0 && smoker != 1));

			do {
				printf("\nEnter your Systolic blood pressure in mmHg: ");
				Clear_Buffer(); 
				continue;
			} while(scanf("%d", &erice_SBP) != 1 || erice_SBP < 40 || erice_SBP > 400);

			if(sex == 1) {
				do {
					printf("\nEnter your cholestrol level in mmol/L: ");
					Clear_Buffer(); 
					continue;
				} while(scanf("%lf", &cholestrol_level) != 1 || cholestrol_level < 0.5 || cholestrol_level > 50);
			}
		}
	}
	/*switch case to factor in if user is a man or a woman to determine risk category. For both cases different factors taken as input from user
	are used to determine risk category and print it by calling in the function with numbers 1 to 6 as arguments to print the appropriate
	risk category*/
	switch(sex) {
		//for men
		case 1:
		/*if age is between 40 and 49 and if they are not diabetic and they dont smoke then their risk category is low. If age is between 40 and 49
		 and if they are not diabetic and they dont smoke then if their SBP is less than 140 then their risk category is low or if SBP is greater
		 than or equal to 140 then their risk category is mild*/
		if(age >= 40 && age < 50) {
			if(diabetic == 0 && smoker == 0) {
				print_ERICE_risk_category(1);
			} else if(diabetic == 1 && smoker == 1) {
				if(erice_SBP < 140) {
					print_ERICE_risk_category(1);
				} else {
					print_ERICE_risk_category(2);
				}
			} else {
				if(erice_SBP < 180 && cholestrol_level < 6.5) {
					print_ERICE_risk_category(1);
				} else if(diabetic == 0 && smoker == 1 && cholestrol_level < 5.2) {
					print_ERICE_risk_category(1);
				} else {
					print_ERICE_risk_category(2);
				}
			}
		} else if(age >= 50 &&  age < 60) {
			if(diabetic == 0 && smoker == 0) {
				if(erice_SBP >= 180 && cholestrol_level >= 5.2) {
					print_ERICE_risk_category(3);
				} else {
					print_ERICE_risk_category(2);
				}
			} else if(diabetic == 1 && smoker == 1) {
				if(erice_SBP >= 160) {
					print_ERICE_risk_category(4);
				} else if ((erice_SBP < 140 && cholestrol_level < 5.2) || (erice_SBP < 140 && cholestrol_level >= 7.8)) {
					print_ERICE_risk_category(2);
				} else {
					print_ERICE_risk_category(3);
				}
			} else {
				if(erice_SBP < 140) {
					print_ERICE_risk_category(2);
				} else {
					print_ERICE_risk_category(3);
				}
			}
		} else if(age >= 60 &&  age < 70) {
			if(diabetic == 1 && smoker == 1) {
				if(erice_SBP < 140) {
					print_ERICE_risk_category(4);
				} else if((erice_SBP >= 180) || (erice_SBP >= 160 && cholestrol_level >= 6.5)) {
					print_ERICE_risk_category(6);
				} else {
					print_ERICE_risk_category(5);
				}
			} else if(diabetic == 0 && smoker == 0) {
				if(erice_SBP < 140) {
					print_ERICE_risk_category(3);
				} else {
					print_ERICE_risk_category(4);
				}
			} else {
				if(erice_SBP < 140 && cholestrol_level < 5.2) {
					print_ERICE_risk_category(3);
				} else if(erice_SBP < 140 && cholestrol_level >= 5.2) {
					print_ERICE_risk_category(4);
				} else {
					print_ERICE_risk_category(5);
				}
			}
		} else if(age >= 70 && age < 80) {
			if(diabetic == 0 && smoker == 0) {
				if(erice_SBP < 140) {
					print_ERICE_risk_category(4);
				} else {
					print_ERICE_risk_category(5);
				}
			} else {
				if(erice_SBP < 140) {
					print_ERICE_risk_category(5);
				} else {
					print_ERICE_risk_category(6);
				}
			}
		}
		break;

		//for women
		case 0:
		if(age >= 50 && age < 60) {
			if(diabetic == 1 && smoker == 0 || diabetic == 0 && smoker == 1) {
				if(erice_SBP < 180) {
					print_ERICE_risk_category(2);
				} else {
					print_ERICE_risk_category(3);
				}
			} else if(diabetic == 0 && smoker == 0) {
				print_ERICE_risk_category(2);
			} else {
				if(erice_SBP < 180) {
					print_ERICE_risk_category(3);
				} else {
					print_ERICE_risk_category(4);
				}
			}
		} else if(age >= 60 && age < 70) {
			if(diabetic == 1 && smoker == 0 || diabetic == 0 && smoker == 1) {
				if(erice_SBP < 180) {
					print_ERICE_risk_category(3);
				} else {
					print_ERICE_risk_category(4);
				}
			} else if(diabetic == 1 && smoker == 1) {
				if(erice_SBP < 180) {
					print_ERICE_risk_category(4);
				} else {
					print_ERICE_risk_category(5);
				}
			} else {
				if(erice_SBP < 180) {
					print_ERICE_risk_category(2);
				} else {
					print_ERICE_risk_category(3);
				}
			}
		} else if(age >= 70 && age < 80) {
			if(diabetic == 1 && smoker == 0 || diabetic == 0 && smoker == 1) {
				if(erice_SBP < 180) {
					print_ERICE_risk_category(5);
				} else {
					print_ERICE_risk_category(6);
				}
			} else if(diabetic == 0 && smoker == 0) {
				if(erice_SBP < 180) {
					print_ERICE_risk_category(4);
				} else {
					print_ERICE_risk_category(5);
				}
			} else {
				print_ERICE_risk_category(6);
			}
		}
		break;
	}
}



