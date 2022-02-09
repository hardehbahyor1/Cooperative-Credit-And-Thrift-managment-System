#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
// definition of structure variable for members registration

struct date{
    int month,day,year;
    };

struct transaction
		{
			char Aname[50];
			char Atype[20];
			double account_number;
			int rno;
			float totalbalance;
			float newbalance;	
			int deposit; // amount deposit
			int withdraw;
			long int loan_Balance;
			long int loan_repayment;
			char identity[40];	// for Account User Name
		};
struct account   //  The Definition of this account will be for CICS Account opening
		{
			int id_no;
			int rno;
			int age;
			char Aname[50];
			char address[60];
			double mobilenumber;
			double account_number;
			char Atype[20];	 				// either Savings or Current Account.
			struct date create;
			struct date deposit;
			struct transaction f;
		}a;

struct next_of_kin
				{
					char name[50];
					char mobile[20];
					char email [50];
					char address[50];
				 	char relationship[50];
					char occupation[50];
				};

struct biodata
		{
			int roll_no;
			char name[50];
			double mobile[20];
			char email [50];
			int year,month, day; 		// DOB declaration
			char state_of_origin[20];
			char LGA[30];
			char hometown[30];
			char residential_Address[50];
			char marital_Status[20];

			// BANK DETAILS
				char bank_name[30];
				char account_name[50];
				int account_no[20];
				char account_type[20]; // either Saving or Current Account

			struct next_of_kin k1; // structure within structure
		};

void register_form()   //function definition FOR MEMBERSHIP FORM
	{
		int date;  // used to assign the computer date to the form
		int choice; // to select the account type either savings or current.

		struct biodata m1; // m1 is the UNIVERIAL Variable name FOR AL
		m1.roll_no = 0;
		FILE *registration;
		registration = fopen("memberlist.txt", "a");
			if (registration == NULL)
				{
					puts ("Error Opening Record \n\n");
					system("CLS");
				}
		printf("\n\t\t Welcome to IFEKOREDE E-REGISTRATION PORTAL. \n You need to enter some details for registration.\n\n");
		puts("NB:  You must be a registered Member before you will be allowed to have a Society_Account with us. \n");

			puts("================================================================================");
			puts("Welcome to\n \t\t Account Opening Section.\n\n");
			puts("ATTENTION: Please read carefully and be Attentive in filling the required\n information.\n");

					// form registration
			/*	puts("1. Bio-Data/ Personal Information required \n\n");

					puts("\tEnter Id_Number:\t");
					//fflush(stdin);
					scanf("%d", &m1.roll_no);
					fprintf(registration, "ID_NO :  = %d\n", m1.roll_no);

					    puts("\tEnter Name:\t");
					    fflush(stdin);
						scanf("%[^\n]s", &m1.name);
					    fprintf(registration, "NAME:  = %s\n", m1.name);

					puts("\tEnter Mobile Number:\t");
					fflush(stdin);
					scanf("%lf", &m1.mobile);
					fprintf(registration, "MOBILE NUMBER:  = %s\n", m1.mobile);

						puts("\tEnter DATE OF BIRTH (dd/mm/yy):\t");
					    fflush(stdin);
				   		scanf("%d/%d/%d", &m1.day, &m1.month, &m1.year);
				 		fprintf(registration, "DATE OF BIRTH:  = %d/%d/%d\n", m1.day,m1.month,m1.year);

					puts("\tEnter Email Address:\t");
				    fflush(stdin);
			   		scanf("%s", &m1.email);
			   		fprintf(registration, "Email Address: = %s\n", m1.email);

						puts("\tEnter Residential Address:\t");
						fflush(stdin);
						scanf("%[^\n]s", &m1.residential_Address);
						fprintf(registration, "RESIDENTIAL ADDRESS: = %s\n", m1.residential_Address);

					puts("\tEnter Marital Status:\t");
					fflush(stdin);
					scanf("%[^\n]s", &m1.marital_Status);
					fprintf(registration, "MARITAL STATUS: = %s\n", m1.marital_Status);

					puts("\tEnter State of Origin:\t");
					fflush(stdin);
					scanf("%[^\n]s", &m1.state_of_origin);
					fprintf(registration, "STATE OF ORIGIN: = %s\n", m1.state_of_origin);

						puts("\tEnter Local GOvernment Area:\t");
						fflush(stdin);
						scanf("%[^\n]s", &m1.LGA);
						fprintf(registration, "LOCAL GOVERNMENT AREA: = %s\n", m1.LGA);

					puts("\t Enter Home Town:\t");
					fflush(stdin);
					scanf("%[^\n]s", &m1.hometown);
					fprintf(registration, "HOME TOWN: = %s\n", m1.hometown);

				puts("\n2.NEXT OF KIN \n");	// i want to make it a loop, so that two NEXT of kin can be supplied. #completed
						puts("To be a Fully recongnised Member of IFEKOREDE CICS Ltd, \n your NEXT OF KIN Information is needed.\n ");
						int i; // delaration of variable for iteration of the next of Kin
							fprintf(registration, "\n\t        ****NEXT OF KIN INFROMATION**** \n");
						for(i=0; i<2; i++)
							{
								puts("\n\tName Of Next of Kin:\t");
								fflush (stdin);
								scanf("%[^\n]s", &m1.k1.name[i]);
								fprintf(registration, "Name: = %s\n", m1.k1.name);

								puts("\tEmail Address:\t");
								fflush(stdin);
								scanf("%[^\n]s", &m1.k1.email[i]);
								fprintf(registration, "Email Address: = %s\n", m1.k1.email);

								puts("\tMobile Number:\t");
								fflush(stdin);
								scanf("%[^\n]s", &m1.k1.mobile[i]);
								fprintf(registration, "Mobile Number: = %s\n" ,m1.k1.mobile);

								puts("\tOccupation:\t");
								fflush(stdin);
								scanf("%[^\n]s", &m1.k1.occupation[i]);
								fprintf(registration, "Occupation: = %s\n", m1.k1.occupation);

								puts("\tRelationship (Next of Kin relationship with You):\t");
								fflush(stdin);
								scanf("%[^\n]s", &m1.k1.relationship[i]);
								fprintf(registration, "Relationship: = %s\n", m1.k1.relationship);

								puts("\tResidential Address:\t");
								fflush(stdin);
								scanf("%[^\n]s", &m1.k1.address[i]);
								fprintf(registration, "Residential Address: = %s\n\n", m1.k1.address);
							}

				puts("\n\n3.\n\t\t\t   ********BANK ACCOUNT DETAILS******** \n");
				fprintf(registration, "             ****BANK ACCOUNT DETAILS****  \n");
						puts("Enter Bank Name:");
						fflush(stdin);
						scanf("%[^\n]s", &m1.bank_name);
						fprintf(registration, "\n Bank Name = %s\n", m1.bank_name);

							puts("Account Type(Saving/Current):\t");
							fflush(stdin);
							scanf("%[^\n]s", &m1.account_type);
							fprintf(registration, "Account TYpe = %s\n", m1.account_type);

								puts("Enter Account Name:\t"); // name on the Bank Account
								fflush(stdin);
								scanf("%[^\n]s", &m1.account_name);
								fprintf(registration, "Account Name = %s\n", m1.account_name);

						puts("Enter Bank (1 0 digits) Account Number:\t");
						fflush(stdin);
						scanf("%[^\n]s", &m1.account_no);
						fprintf(registration, "Account No = %s\n\n", &m1.account_no);

	printf("\nConfirming details.......\n........\n\nWelcome, %s!\n",m1.name);
			printf("\n Your Registration as a Member of (ICICS) was Successful! \n");
				printf("Your Identity Number is :%d\n", m1.roll_no);
					printf("Please kindly note your Identity number, as it will be required from you \n in order to perfrom any operations.");
*/
	fclose (registration);
}

void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}


void myAccount()	//ADD NEW ACCOUNT
{
	int i;
	FILE*ACCOUNT; FILE*registration;
	struct biodata m1;
	ACCOUNT = fopen("IFEKOREDE ACCOUNT.txt", "a+");

	printf("\t\t\t==== ACCOUNT SETUP ====\n");
	puts("Fill the necessary information required below:");
	/*printf("\nENTER YOUR ID_NUMBER:");
		scanf("%d", &a.rno);*/
			printf("\n ACCOUNT NAME:");  fflush(stdin);
				scanf("%[^\n]s", &a.Aname);
					printf("------> ACCOUNT NUMBER:");
					scanf("%ld", &a.account_number);
						printf("\nEnter the date of birth(mm/dd/yyyy):");
					    scanf("%d/%d/%d",&a.create.day, &a.create.month, &a.create.year);
						    printf("\nEnter the age:");
						    scanf("%d",&a.age);
							    printf("\nEnter the address:"); fflush(stdin);
							    scanf("%[^\n]s",a.address);
					    printf("\nEnter the phone number:");
					    scanf("%ld",&a.mobilenumber);
					 printf("------> ACCOUNT TYPE(SAVINGS/CURRENT):");
					scanf("%s", &a.Atype);
		   		printf("\nEnter the amount to deposit:#");
		    	scanf("%d",&a.f.deposit);
		   	a.f.totalbalance += a.f.deposit;
		   	a.f.newbalance += a.f.totalbalance;
				fwrite(&a, sizeof(a), 1, ACCOUNT);  // 	write into the Database

for(i=0;i<=6;i++){
   fordelay(100000000);
    printf(". ");
}
printf("\n");
	system("pause");
		system("cls");

		printf("\t\t*****************************************************\n");
		printf("\t\t**                                                 **\n");
		//printf("\t\t       ROLL No= %d\n							   \n", a.id_no);
		printf("\t\t       NAME= %s\n								   \n", a.Aname);
		printf("\t\t       ACCOUNT NUMBER = %ld\n					   \n", a.account_number);
		printf("\t\t       ACCOUNT TYPE = %s\n						   \n", a.Atype);
		printf("\t\t       AMOUNT DEPOSIT #%d\n						   \n", a.f.deposit);
		printf("\t\t       TOTAL BALANCE  #%.2f\n						   \n", a.f.newbalance);
		printf("\t\t* ****************************************************\n");
printf( "Kindly keep your 'ACCOUNT IDENTITY NUMBER' \nSecured as it will be required for you to access & Perfrom any Operation on Your Account\n\n");

printf("\n--------------------------------------------------------------------------\n");
							printf("\t\t\t\tDATE: %s\n", __DATE__);
							printf("\t\t\t\tTIME: %s\n", __TIME__);
printf("----------------------------------------------------------------------------\n");
fclose(ACCOUNT);
}


void make_a_deposit()
	{
		int choice, main_exit, i; int rno, found;	// Local Variable Decalration
		for(i=0;i<=6;i++)
			{	//delay loop
				fordelay(100000000);
				printf(". ");
			}
		puts("\n\n Welcome, Dear  Customer, \n To make a Deposit into your Society Account, please input your ACCOUNT_NO:\n ");
		
		struct account a; //account_number;
		FILE *ACCOUNT; FILE *temporary;
		ACCOUNT = fopen("IFEKOREDE ACCOUNT.txt", "a+"); 	// OLD
		temporary= fopen("Fin Record.txt", "a+");	   // NEW
			
		printf("Enter Your Account No. :");
			scanf("%d",&rno); 
				printf("Your Entered: %d\n", rno);
		
		printf("Verifying Account Details.....\n");
			for(i=0;i<=6;i++)
			{	//delay loop
				fordelay(100000000);
				printf(". ");
			}	
	    printf("\n");    system("pause");  system("cls");	 // end of delay loop

		while(fread(&a, sizeof(a), 1, ACCOUNT) !=0)
			{
				
				if ( a.account_number =rno)
					{
						found =1;
						printf("\n\nDo you want to\n1.Deposit\n2.Withdraw?\n\nEnter your choice(1 for deposit and 2 for withdraw):");
	        			scanf("%d",&choice);
						if (choice==1) // to deposit
			                {
			                
								//printf("ACOUNT NUMBER : %d\n", a.account_number);
									printf("NAME:: %s\n", a.Aname);
									printf("Account Type:: %s\n", a.Atype);
										strcpy(a.f.Aname, a.Aname);
				                			strcpy(a.f.Atype, a.Atype);

			                	printf("\nYou choose to Deposit a money\n");
							   	//	printf("Your Balance is: #%.2f\n\n", a.f.totalbalance); // a.amt is the variable for automatic deposit @ Reg point
			                   			printf("Enter the amount you want to deposit:# ");
							    			scanf("%d",&a.f.deposit);
											a.f.newbalance =a.f.totalbalance + a.f.deposit; // deposit EXPRESSION statement.
								
									fwrite(&a, sizeof(a), 1, temporary);	   // update Balance in the Database
									
									printf("\n\nACCOUNT NUMBER: %ld\n", rno);
										printf("ACCOUNT NAME: %s\n", a.f.Aname);
				                   		printf("ACCOUNT TYPE: %s\n", a.f.Atype);
				                   		printf("AMOUNT DEPOSIT= #%d\n", a.f.deposit);
										printf("PREVIOUS BALANCE= #%.2f\n", a.f.totalbalance);
                                    printf("NEW BALANCE= %.2f\n", a.f.newbalance);

								printf("\t\t\n\n======== Deposited successfully! ========\n");
			                }
						else // to withdraw
			                {
			                   for(i=0;i<=6;i++)
									{	//delay loop
										fordelay(100000000);
										printf(". ");
									}
								printf("NAME:: %s\n", a.Aname);
								printf("Account Type:: %s\n", a.Atype);
							    	strcpy(a.f.Aname, a.Aname);
			                			strcpy(a.f.Aname, a.Atype);

								printf("\nYou choose to Withdraw a money\n");
    							//printf("Your Balance is: #%.2f\n\n", a.f.totalbalance);
									printf("Enter the amount you want to withdraw:# ");
					                    scanf("%d",&a.f.withdraw);	 // Withdraw EXPRESSION statement
					                   // a.f.totalbalance -= a.f.withdraw;
										a.f.newbalance =a.f.totalbalance - a.f.withdraw;
								fwrite(&a, sizeof(a), 1, temporary);			// update Balance in the Database
								fprintf(temporary, "%.2f", a.f.totalbalance ); // update Balance in the Database
			                    
								printf("ACCOUNT NUMBER: %d\n", rno);
									printf("ACCOUNT NAME: %s\n", a.f.Aname);
				               			printf("ACCOUNT TYPE: %s\n", a.f.Atype);
				                    		printf("AMOUNT WITHDRAWN:= #%d\n", a.f.withdraw);
				                    			printf("PREVIOUS BALANCE= #%.2f\n", a.f.totalbalance);
				                   					printf("TOTAL BALANCE= #%.2f\n", a.f.totalbalance);

			                    printf("\n\nWithdrawn successfully!\n");
								terminate();
			                }
					}
				
	        }
				if(!found)
				   	printf("\n\nRecord not found!!");
				    	printf("\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
				    		scanf("%d",&main_exit);
				      system("cls");
				    if (main_exit==0)
				    	make_a_deposit();
				    else if (main_exit==1)
				    	main(); // main menu
				    else if (main_exit==2)
				    	close();

		fclose(temporary); fclose (ACCOUNT);	
		printf("\n-----------------------------------");
			printf("\nTIME: %s                  ---\n", __TIME__);
				printf("DATE: %s               ---\n", __DATE__);
		printf("-----------------------------------");
	}


void transactionrecord() { 			//display transaction record
			struct account a;
			FILE *temporary;
			temporary= fopen("Fin Record.txt", "r");		// COPY TO THIS FILE DIRECTORY

	while (fread(&a, sizeof(a), 1, temporary) !=0)
		{
			//printf("\n\nACCOUNT NUMBER: %d\n", a.f.account_number);
			printf("\n\nACCOUNT NAME: %s\n", a.f.Aname);
            printf("ACCOUNT TYPE: %s\n", a.f.Atype);
            printf("LAST DEPOSIT: #%d\n", a.f.deposit);
        	printf("PREVIOUS BALANCE= #%.2f\n", a.f.totalbalance);
        	printf("NEW BALANCE= #%.2f\n", a.f.newbalance);
        
		}
	fclose(temporary);

	printf("\n-----------------------------------");
	printf("\nTIME: %s                  ---\n", __TIME__);
	printf("DATE: %s               ---\n", __DATE__);
	printf("-----------------------------------");
}


//=============== LOAN===============================//
void applyloan_mainmessage(){
		printf("welcome to the Loan Application page\n");
		printf("Kindly check if your are eligible for Loan Applcation\n");
			printf("\nchoose your prefered option below: \n\n");
			printf("\t 1. -----> CHECK ELIGIBILITY \n");
			printf("\t 2. -----> REQUEST FOR A LOAN \n");
			printf("\t 3. -----> PAY BACK MY LOAN \n");
			printf("\t 4. -----> CHECK CUSTOMER FINNANCIAL PROFILE (financial()) \n");
			printf("\t 5. -----> BACK TO HOMEPAGE \n");
	}

void eligibility(){
		printf("\n \t\t--------------------------------------------\n");
		printf("\t\t---					----\n");
		printf("\t\t---					----\n");
		printf("\t\t\t\t LOAN POLICY\n ");
		printf("\t\t---					----\n");
		printf("\t\t---					----\n");
		printf("\t\t-------------- ------------------------------\n");
			printf("\n\n Member loans are offered to permanent members. \n Members whose period of membership is less than 5months \n are not eligible for loans from the COOPERATIVE at any time");
			printf("\n DURATION:- LOANS are offered to Members for a period of ONE (1) years only.\n");
	}


void requestloan(){ //Ask for Loan
		struct account a; 
		FILE*ACCOUNT; FILE *temporary; int i, acc_no;
		ACCOUNT = fopen("IFEKOREDE ACCOUNT.txt", "r");
		temporary = fopen("copy.txt", "r+");
		for(i=0;i<=6;i++){
		   fordelay(100000000);
		    printf(". ");
		}
		printf("\t\t\tWelcome to LOAN APPLICATION PAGE.....\n\n");
		//printf("Enter your Account Number: "); scanf("%d", &acc_no);
			while(fread(&a, sizeof(a), 1, ACCOUNT))
				{
					if(a.account_number == acc_no)
						{
						
							printf("NAME:: %s\n", a.Aname);
							printf("ACCOUNT TYPE:: %s\n", a.Atype);
							printf("ACCOUNT NO:: %ld\n", a.account_number);
							printf("CASH AT BANK:: %.2f\n", a.f.totalbalance);
						}
					else
						errorMessage();
				}
		fclose(ACCOUNT); fclose(temporary);
		printf("\n--------------------------------------------------------------------------\n");
							printf("\t\t\t\tDATE: %s\n", __DATE__);
							printf("\t\t\t\tTIME: %s\n", __TIME__);
		printf("----------------------------------------------------------------------------\n");
	}


void applyforloan(){ // loan App Menu
	int choice; // for switch case structure
	FILE*ACCOUNT; FILE *temporary;
	ACCOUNT = fopen("IFEKOREDE ACCOUNT.txt", "r+");
	temporary = fopen("copy.txt", "r+");

		if (ACCOUNT = NULL){
			printf("ERROR OPENING FILE......\n");
			printf("DATABASE FILE DIRECTION NOT FOUND...\n");
		}
	applyloan_mainmessage();
	printf("your choice:"); scanf("%d",&choice);
		switch(choice){
				case 1:	
					break;
				case 2:
						requestloan(); // want to change it to loan dashboards
					break;
				case 3:
						repayloan();
					break;
				case 4:
						display_all_account();  // to check the customer's financial report
					break;
				case 5:
						main();
					break;
				default:
						errorMessage();
					break;
		}

	printf("-----------------------------------\n");
	printf("\nTIME: %s                  ---\n", __TIME__);
	printf("DATE: %s               ---\n", __DATE__);
	printf("---------------------------------\n");
	fclose(ACCOUNT);
	fclose(temporary);
} // APPLY FOR LOAN


void repayloan(){
	struct biodata m1;
	int rno;
	FILE*ACCOUNT;
	ACCOUNT = fopen("IFEKOREDE ACCOUNT.txt", "r+");
			printf("\t ERROR 504\n\tTHE PAY BACK LOAN MODULE IS UNDER_DEVELOPEMENT\n \tCHECK BACK LATER");

	printf("-----------------------------------");
	printf("\nTIME: %s                  ---\n", __TIME__);
	printf("DATE: %s               ---\n", __DATE__);
	printf("-----------------------------------");

	fclose(ACCOUNT);
}// pay back loan

// function definition to DISPLAY ALL Account information
void display_all_account(){

	struct account a; 
	FILE*ACCOUNT;
	ACCOUNT = fopen("IFEKOREDE ACCOUNT.txt", "r");
		while (fread(&a, sizeof(a), 1, ACCOUNT))
				{

						printf("\t\t \n\nACCOUNT NUMBER: =%d\n", a.account_number);
						printf("\t\t NAME:= %s\n", a.Aname);
						printf("\t\t ACCOUNT TYPE: = %s\n", a.Atype);
						printf("\t\t MOBILE NUMBER: =%d\n", a.mobilenumber);
						printf("\t\t DATE OF BIRTH: = %d/%d/%d \n", a.create.day, a.create.month, a.create.year);
						printf("\t\t AGE: = %d\n", a.age);
						printf("\t\t ADDRESS: = %s\n", a.address);
						printf("\n\t\t LAST DEPOSIT: = #%d\n", a.f.deposit);
						printf("\t\t TOTAL BALANCE: = #%.2f\n", a.f.totalbalance);
				}
						
		printf("\nTIME: %s                  ---\n", __TIME__);
		printf("DATE: %s               ---\n", __DATE__);
		printf("-----------------------------------\n");
		fclose(ACCOUNT);
	} // display account information


// function definition to search for a particular account information ==== under development====
void SearchAccount(){
			struct account a; int test=0, i;
			FILE*ACCOUNT; int check_Acc_No; // to check account_Num
			ACCOUNT = fopen("IFEKOREDE ACCOUNT.txt", "r");

			puts("\n Enter ACCOUNT NUMBER:");
			scanf("%d", &check_Acc_No);

		while (fread(&a, sizeof(a), 1, ACCOUNT) !=0)
			{
				if(a.account_number = check_Acc_No) //(a.account_number == accountnum)
					{
						test=1;
						for(i=0;i<=6;i++){
						   fordelay(100000000);
						    printf(". ");
						}
						    printf("\n");system("pause");system("cls");

						printf("\t\t ACCOUNT NUMBER: =%d\n", a.account_number);
						printf("\t\t NAME:= %s\n", a.Aname);
						printf("\t\t ACCOUNT TYPE: = %s\n", a.Atype);
						printf("\t\t MOBILE NUMBER: =%d\n", a.mobilenumber);
						printf("\t\t DATE OF BIRTH: = %d/%d/%d \n", a.create.day, a.create.month, a.create.year);
						printf("\t\t AGE: = %d\n", a.age);
						printf("\t\t ADDRESS: = %s\n", a.address);
						printf("\n\t\t LAST DEPOSIT: = #%d\n", a.f.deposit);
						printf("\t\t TOTAL BALANCE: = #%.2f\n", a.f.totalbalance);
					}
				else if(test !=1)

						for(i=0;i<=6;i++){
						   fordelay(100000000);
						    printf(". ");
						}
						printf("\n"); system("pause"); system("cls");

				printf("\tPlease wait........... ........\n");
				printf("\tVerifying Account Details.....\n");
				printf("\t Error verificating Account Details\n");
				printf("\t IDENTITY NUMBER does not match the Record in the Database.\n\n");
							
			}
						
			printf("-----------------------------------");
			printf("\nTIME: %s                  ---\n", __TIME__);
			printf("DATE: %s               ---\n", __DATE__);
			printf("-----------------------------------");
fclose(ACCOUNT);
}


void record(){
			char username[10] = "admin1234";
			char password[10]=  "admin1234";
			char uname[10]; char pword[10];  // for entry
			int pmatch, umatch, ch;
			printf("welcome to the COOPERATIVE RECORD PANEL.......\n");
			printf(" Due to the confidentiality of the informations activites of the association, \n ony AUUTHORIZED ADIM \n\
			are allowed to access these page.\n");

				printf(" \t\t******** ADMIN LOGIN DETAILS REQUIRED.******** \n");
				printf("Please supply the information required below:\n");
					printf("---->>\t\t USERNAME: "); scanf("%s", &uname);
					printf("---->>\t\t PASSWORD: "); scanf("%s", &pword);
						umatch = strcmp(username, uname);
							pmatch = strcmp(password, pword);
								printf("\n Please wait........... ........");
					printf("\n Verifying Account Details.....");
				if (umatch == 0 && pmatch == 0)
					{
						printf("\n\t\t     ******** VERIFICATION SUCCESSFUL********\n");
						printf("CHOOSE YOUR PREFERED OPTIONS\n\n");

						puts("------>1. DISPLAY\n");
						puts("------>2. SEARCH ACCOUNT\n");
						puts("------>3. DISPLAY TRANSACTION RECORD \n");
						puts("------>4. BACK TO ACCOUNTS\n");
						puts("Enter Your Choice:\n");
								scanf("%d", &ch);
								switch(ch)
									{
										case 1:
												display_all_account(); 	// to display my account dashboard
											break;
										case 2:
												SearchAccount();		//
											break;
										case 3:
												transactionrecord();		//
											break;
										case 4:
												financial_service();		// back to the main ACCOUNT HOMEPAGE
										break;
										default:
												printf("Wrong choice !, Please Select the right choice");
												puts("You will be redirected to the Application Homepage\n\n");
										break;
									}
					}
				else
					printf("\n\t\t     ******** Verificaiton FAILED ********\n\n");
					errorMessage();

		}

void mainMenu() {//Main Menu for the financaial_service().

		   	puts("------>1. CREATE ACCOUNT \n");
			puts("------>2. MAKE A DEPOSIT / WITHDRAW CASH (#) \n");
			puts("------>3. APPLY FOR LOAN \n");
			puts("------>4. PAY BACK MY LOAN \n");
			puts("------>5. TRANSACTION RECORD \n");
			puts("------>6. RECORD PANEL (ADMIN ONLY) \n");
			puts("------>7. BACK TO HOMEPAGE \n");

}


void financial_service(){
				int ch, choose; // choose is for boolwan value TRUE/FALSE
				bool again = true;
				puts("Welcome to \n\t\tIFEKOREDE COOPERATIVE & INVENSTMENT SOCIETY LIMITED \n\t\t\t\tACCOUNT DASHBOARD\n\n");

			while (again)
			{
				mainMenu();

				printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
				puts("Enter Your Choice:\n");
				scanf("%d", &ch);
				switch(ch)
					{
						case 1:
								myAccount(); 	// Regsiter Account form transaction
							break;
						case 2:
								make_a_deposit();		//TO MAKE A DEPOSIT PANEL
							break;
						case 3:
								applyforloan();		// APPLY FOR A LOAN PANEL
							break;
						case 4:
								repayloan();		// APPLY FOR A LOAN PANEL
							break;
						case 5:
								transactionrecord();		// PAY BACK MY LOAN PANEL
							break;
						case 6:
								record();				// FINANCIAL SERVICE DATABASE(ADMIN only)
							break;
						case 7:
								main();
						break;
						default:
								errorMessage();
								puts( "You will be redirected to the Application Homepage\n\n loading.....");
								main();
						break;
					}

				printf("\n\n =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
		        printf("Would you like to do another transaction:\n");
		        printf("< 1 > Yes\n");
		        printf("< 2 > No\n");
		        scanf("%d", &choose);

		        system("CLS");

		        if (choose == 2)
					{
		            	again = false;
					}

			}
}  // end of financial_service()


//=============== ==== ====  ACCESS_DATABASE() MODULE =======================================

void membership_record()	//function to display members successfully registered
{
	printf("\t\t WELCOME TO IFEKOREDE CICS MEMBERSHIP\n");
	printf("Kindly note that Members registration that has been successfully done will appear here \n\n");
	FILE*registration;
		struct biodata m1;
			registration = fopen("memberlist.txt", "r");
				if (registration == NULL)
					{
						puts ("Error Opening Record \n\n");
						system("CLS");
					}
	while(fread(&m1, sizeof(m1), 1, registration))
	{
			printf("NAME: %s\n", &m1.name);

	}

fclose(registration);
}


void search()	// function definition to search for a members in the Database
{
	int rno = 0;
	struct biodata m1;
	FILE *registration;
		registration = fopen("memberlist.txt", "r");
			if (registration == NULL)
				{
					puts ("Error Opening Record \n\n");
					system("CLS");
				}
	printf("\t\t****** WELCOME, TO CICS MEMBERSHIP DATABASE****** \n\n");

	printf("Enter the IDENTITY NUMBER OF Member to Display:\n");
	scanf("%d", &rno);
		while(fread(&m1, sizeof(m1), 1, registration))
			{
				if(rno == m1.roll_no)
					{
						//printf("%s-%s-%s :", m1.name);
						printf("IDENTITY NUMBER = %s\n", m1.roll_no);
						printf("ADDRESS : %s\n", m1.residential_Address);
						printf("MARITAL STATUS: %s\n", m1.marital_Status);
						printf("EMAIL ADDRESS: = %s\n", m1.email);
				    	//printf("\nConfirming details...\n.......\n");
					}
			}
fclose(registration);
}


void total_number()			// function definition to disaplay the total number of members in the Database
{
	struct biodata m1;
	FILE *registration;
		registration = fopen("memberlist.txt", "r");
			if (registration == NULL)
				{
					puts ("Error Opening Record \n\n");
					system("CLS");
				}
	fseek(registration, 3, SEEK_END);		  // function to determine the total numebr of MEMBERS in the Database
	int n = ftell(registration)/ sizeof(m1);
	printf("\n\n Total Number of Record = %d\n\n", n);
fclose(registration);
}


void ACCESS_DATABASE(){
	char username[10] = "admin1234";
	char password[10] = "admin1234";
	char uname[10];
	char pword[10];
	int umatch, pmatch;

		printf("welcome to the COOPERATIVE RECORD PANEL.......\n");
			printf(" Due to the confidentiality of the informations activites of the SOCIETY, \n ony AUUTHORIZED PERSONNEL is allowed to access these page.\n\n");

		printf(" \t\t******** ADMIN LOGIN DETAILS REQUIRED.******** \n");
		printf("Please supply the information required below:\n");
			printf("---->> /t/t USERNAME: "); scanf("%s", &uname);
			printf("---->> /t/t PASSWORD: "); scanf("%s", &pword);
				umatch = strcmp(username, uname);
				pmatch = strcmp(password, pword);
					printf("\n Please wait........... ........\n");
					printf("\n Verifying Account Details.....\n\n");
		if (umatch == 0 && pmatch==0)
			{
					printf("\n\t\t     ******** VERIFICATION SUCCESSFUL********\n");
					//printf("CHOOSE YOUR PREFERED OPTIONS\n\n");
						int ch;
					puts("\n\n\t\t************IFEKOREDE CICS DATABASE RECORD************\n");

					printf("Please your prefered Choice:\n");
					printf("\t1. MEMBERSHIP RECORD.\n\n");
					printf("\t2. SEARCH FOR A MEMBER.\n\n");
					printf("\t3. TOTAL NUMBERS OF RECORD.\n\n");
					printf("\t4. FINANCIAL ACTIVITIES PAGE.\n\n");
					printf("\t0. GO BACK TO HOMEPAGE.\n\n");

					puts("Enter Your Chocie:"); scanf("%d",&ch);
					switch(ch)
							{
								case 1:
									membership_record();
								break;
								case 2:
									search();
								break;
								case 3:
									total_number();
								break;
								case 4:
									record(); // this is THE DATABASE for the FINANCIAL ACTIVITIES OF THE SOCIETY
								break;
								case 0:
									main();
								default:
										puts("Enter the right choice:\n\n");
								break;
							};
			}
			else
				printf("\n\t\t     ******** Verificaiton FAILED ********");
}


void delete_account()		//function definition
	{
		puts("Under Development \n");
		puts("come back later.");
		printf("\t%s\n", __DATE__);
		printf("\t%s\n", __TIME__);
	}

void errorMessage()	{
   		printf("\t\t+++!!!You selected invalid number!!!+++\n");
   		//close();
	}
void terminate()
	{
    	printf("\n\n\t\t ****** Thank You ******!\n\n");
    	 printf("\n\n--------------Take your receipt!!!------------------\n");
   		 printf("-----Thank you for using TRANSACTING with Us!!!-----\n");
    }

// Main Function
int main()
{
	printf("\t**********************************************************\n");
	printf("\t*                                       	         *\n");
	printf("\t*       -------------------------------------------	 *\n");
	printf("\t*              COOPERATIVE MANAGEMENT SYSTEM (CMS)       *\n");
	printf("\t*       -------------------------------------------	 *\n");
	printf("\t*               ELECTRONIC PROCESSING SYSTEM             *\n");
	printf("\t*                                           	 	 *\n");
	printf("\t*                                           		 *\n");
	printf("\t**********************************************************\n\n");
		printf("\t\t\nCurrent DATE && TIME : %s, %s \n\n", __DATE__, __TIME__);
	puts("=========================================================================");

	puts("please select from the option below:\n");
	puts("\t\t 1. CREATE AN ACCOUNT \n");
	puts("\t\t 2. FINANCIALSERVICE  (DEPOSIT, WITHDRAW, LOAN, etc) \n");
	puts("\t\t 3. RECORD \n");
	puts("\t\t 4. ADMIN PANEL\n");
	puts("\t\t 0. EXIT \n");

		int choice;
		puts("Enter Your Prefered Choice:");
		scanf("%d", &choice);
			switch(choice)
				{
					case 1:
							register_form();
							break;      //function call
					case 2:
							financial_service();		//function call
							break;
					case 3:
							ACCESS_DATABASE();    //function call
							break;
					case 4:
							delete_account();		//function call
							break;
					case 5:
							puts("UNDER DEVELOPEMENT \n\n");		//function call
							break;
					default:
							errorMessage();
							break;
				}

return 0;
}
