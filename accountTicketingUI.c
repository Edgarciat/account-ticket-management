// ===================================================================================
//  Assignment: 2 //  Milestone : 2
// ===================================================================================
//  Student Name  : Edgar David Garcia Torres
//  Student ID    : 104433206
//  Student Email : edgarciat-torres@myseneca.ca
//  Course Section: ZZA
// ===================================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "account.h"
#include "accountTicketingUI.h"


void applicationStartup(struct AccountTicketingData* account) { //ENTRY POINT LOGIC

	int index = 0;
	if (index == 0) {
		index = menuLogin(account);
		
	}else{
		menuAgent(account,  &account->accounts[index - 1]);
		index = 0;
	}
		
	printf("\n==============================================");
	printf("\nAccount Ticketing System - Terminated");
	printf("\n==============================================\n\n");
}

int menuLogin( struct AccountTicketingData* account) {//LOGINLOGINLOGINLOGINLOGINLOGINLOGINLOGINLOGINLOGI
	int Max = account->ACCOUNT_MAX_SIZE;// LOOK IN THE ATRUCT THE VALUE FOR THE MAX SIZE
	int option = 3, index = 0, numberacount;
//R:	
	option = 3;
	do {
	K:
		printf("==============================================\n");
		printf("Account Ticketing System - Login\n");
		printf("==============================================\n");
		printf("1) Login to the system\n0) Exit application\n");
		printf("----------------------------------------------\n\n");
		printf("Selection: ");
		option = getIntFromRange(0, 1);
		char desition;
		
		if (option == 0) {//exit aplication
			printf("\nAre you sure you want to exit? ([Y]es|[N]o): ");
			desition = getCharOption("yYnN");
			if (desition == 'y' || desition == 'Y') {
				goto T;
			}
			if (desition == 'n' || desition == 'N') {
				printf("\n");
			//	goto R;
			}
		}

	} while (option != 1);
	
	int atemptRemaining, menu=0;
	if (option == 1) {
		do {
			atemptRemaining = 3;
			do {
				char loginUser[30] = "0";
				char loginPassword[30] = "0";
				printf("\nEnter the account#: ");
				numberacount = getPositiveInteger();
				printf("User Login    :");
				getCString(loginUser, 0, 30);
				printf("Password      :");
				getCString(loginPassword, 0, 30);
				index = findAccountIndexByAcctNum(numberacount, account, Max, 0);
				if (index != 0 && !strcmp(account->accounts[index-1].loggin.user, loginUser) && !strcmp(account->accounts[index-1].loggin.password, loginPassword)) {
					menu = 1;
					goto S;
				}
				else {
					atemptRemaining = atemptRemaining - 1;
					printf("INVALID user login/password combination! [attempts remaining:%d]\n", atemptRemaining);

					if (atemptRemaining == 0) {
						printf("\nERROR: Login failed!\n\n");
						pauseExecution();
						printf("\n");
						goto K;
					}
				}
			}while(atemptRemaining>0||menu==1);
			S:
			if (menu == 1) {
				if (account->accounts[index - 1].acType== 'C') {//CUSTOMER MENU
					menuCustomer(account, &account->accounts[index - 1]);
				
				//pauseExecution();
				//printf("\n");
				goto K;
				index=0;
				}
				else {
					menuAgent(account, &account->accounts[index - 1]);
					index = 0;
					goto K;
				}
			}
		} while (menu==0);
	}
	T:
	return index;
}

void menuCustomer(struct AccountTicketingData account[], struct Account* logged) {
	int  selection = 8, i;
	do {
		printf("\nCUSTOMER:  %s (%d)", logged->loggin.name, logged->accountNum);
		printf("\n==============================================\n");
		printf("Customer Main Menu\n");
		printf("1) View your account detail\n");
		printf("2) Create a new ticket\n");
		printf("3) Modify an active ticket\n");
		printf("4) List my tickets\n");
		printf("----------------------------------------------\n");
		printf("0) Logout\n\n");
		printf("Selection: ");

		selection = getIntFromRange(0, 4);
		if (selection == 1) {//VIEW YOUR ACCOUNT DETAIL
			char pass[9] = "0", typC[10] = "CUSTOMER";   int e = 0;

			for (e = 0; e < 8; e++) {
				if (e == 1 || e == 3 || e == 5 || e == 7 || e == 6) {
					pass[e] = '*';
				}
				if (e == 0 || e == 2 || e == 4) {
					pass[e] = logged->loggin.password[e];
				}
			}
			printf("\n");
			displayAccountDetailHeader();
			printf("%05d %-9s %5d $%10.2lf %-10s %-15s %-10s %8s\n\n", logged->accountNum, typC, logged->Demo.birthYear, logged->Demo.inccome, logged->Demo.country, logged->loggin.name, logged->loggin.user, pass);
			pauseExecution();
		}
		if (selection == 2) {
			printf("Feature #2 currently unavailable!");
			pauseExecution();
		}
		if (selection == 3) {
			printf("Feature #3 currently unavailable!");
			pauseExecution();
		}
	K:	
	if (selection == 4) {
		int ticketNum = 0, index = 0;
		do {
		char statusO[] = "OPEN";
		char statusC[] = "CLOSED";
		printf("\n------ ------ ------------------------------ --------");
		printf("\nTicket Status Subject                        Messages");
		printf("\n------ ------ ------------------------------ --------\n");
		for (i = 0; i < 10; i++) {
			if (logged->accountNum == account->tickets[i].NumAcc) {
				if (account->tickets[i].Status == 1) {
					printf("%06d %-6s %-30s %5d\n", account->tickets[i].TIckNum, statusO, account->tickets[i].Subject, account->tickets[i].Counter);
				}
				else {
					printf("%06d %-6s %-30s %5d\n", account->tickets[i].TIckNum, statusC, account->tickets[i].Subject, account->tickets[i].Counter);
				}

			}
		}
		printf("------ ------ ------------------------------ --------\n");
		
		
			ticketNum = 0; 
			index = 0;
			printf("\nEnter the ticket number to view the messages or");
			printf("\n0 to return to previous menu: ");
			ticketNum = getPositiveInteger();
			if (ticketNum == 0) {
				///finish
				index = 0;
				goto H;
			}
			for (i = 0; i < 20; i++) {//Check the if the ticket number exists
				if (account->tickets[i].TIckNum == ticketNum) {
					index = i + 1;
					goto L;
				}
			}
			if (index == 0) {
				printf("\nERROR: Invalid ticket number.\n\n");
				pauseExecution();
				goto K;
			}

		//} while (ticketNum != 0 || index == 0);
	L:
		if (index != 0) {
			char ActypeA[9] = "AGENT";
			char ActypeC[9] = "COSTUMER";

			printf("\n================================================================================");
			printf("\n%d (OPEN) Re: %s", ticketNum, account->tickets[i].Subject);
			printf("\n================================================================================");
			for (i = 0; i < 10; i++) {
				if (account->tickets[index - 1].Mes->MessAcType !=0) {
					if (account->tickets[index - 1].Mes[i].MessAcType == 'A') {
						printf("\n%s (%s):", ActypeA, account->tickets[index - 1].Mes[i].MessName);
						printf("\n   %s\n", account->tickets[index - 1].Mes[i].MessDetail);
					}
					if (account->tickets[index - 1].Mes[i].MessAcType == 'C') {
						printf("\n%s (%s):", ActypeC, account->tickets[index - 1].Mes[i].MessName);
						printf("\n   %s\n", account->tickets[index - 1].Mes[i].MessDetail);
					}
				}
			}
			printf("\n");
			pauseExecution();

		

		}
		} while (ticketNum != 0 || index == 0);
	}
H:
	; }while (selection != 0);
		printf("\n### LOGGED OUT ###\n\n");
}

void menuAgent(struct AccountTicketingData account[], struct Account* logged) {//MENUMENUMENUMENUMENUMENUMENUMENU
	int Max = account->ACCOUNT_MAX_SIZE;// LOOK IN THE ATRUCT THE VALUE FOR THE MAX SIZE
	int selection = 10, i, found = 0, notfound;
K:
	do {
		if (logged->acType == 'A') {
		//if (logged->accounts->acType == 'A') {
		//	printf("\nAGENT: %s (%d)", logged->accounts->loggin.name, logged->accounts->accountNum);
			printf("\nAGENT: %s (%d)", logged->loggin.name, logged->accountNum);
		}
		printf("\n==============================================");
		printf("\nAccount Ticketing System - Agent Menu");
		printf("\n==============================================");
		printf("\n1) Add a new account");
		printf("\n2) Modify an existing account");
		printf("\n3) Remove an account");
		printf("\n4) List accounts: summary view");
		printf("\n5) List accounts: detailed view");
		printf("\n----------------------------------------------");
		printf("\n6) List new tickets");
		printf("\n7) List active tickets");
		printf("\n8) Manage a ticket");
		printf("\n9) Archive closed tickets");
		printf("\n----------------------------------------------");
		printf("\n0) Logout\n");
		printf("\nSelection: ");

		selection = getIntFromRange(0, 9);
		if (selection == 1) {//**********************ADD A NEW ACCOUNT****************************
			notfound = 1;
			do {   //check account numbers = 0
				for (i = 0; i < Max; i++) {
					if (account->accounts[i].accountNum == 0) {
						found = i;//found is the position of the free spot
						goto L;
					}
				}L:
				if (found == 0) {//DID NOT FIND A FREE SPOT 
					printf("\nERROR: Account listing is FULL, call ITS Support!\n");
					notfound = 1;
				}
				if (found > 0 && found <= Max) {//FOUND A FREE SPOT IN i
					getAccount(account, &account->accounts[found]);
					getUserLogin(&account->accounts[found]);
					getDemographic(&account->accounts[found]);
					printf("\n*** New account added! ***\n");
					
					pauseExecution();
					notfound = 0;
				}
			} while (notfound == 1);
		}
		if (selection == 2) {//************************MODIFY AN EXISTING ACCOUNT***************
			updateAccount(account, Max);
		}
		if (selection == 3) {//*************************REMOVAL AN ACCOUNT********************
			int removeAccount;
			int remove = 0;//index
			char confirRemove;

			printf("\nEnter the account#: ");
			removeAccount = getIntFromRange(0, 99999);
			//if (removeAccount == logged->accounts->accountNum) {//DENY REMOVAL
			if (removeAccount == logged->accountNum) {//DENY REMOVAL
				printf("\nERROR: You can't remove your own account!\n\n");
				pauseExecution();
				selection = 8;
				goto K;
			}
			//------------------------------------------------------------------
			remove = findAccountIndexByAcctNum(removeAccount, account, Max, 0);
			//------------------------------------------------------------------
			if (remove == 0) {
				printf("\nthat account does not exist");
			}
			//if (remove < Max && remove != 0 && removeAccount != logged->accounts->accountNum) {
			if (remove < Max && remove != 0 && removeAccount != logged->accountNum) {
				//display the account
				char pass[9] = "0";
				int e = 0;
				char typC[10] = "CUSTOMER";
				char typA[10] = "AGENT";
				for (e = 0; e < 8; e++) {
					if (e == 1 || e == 3 || e == 5 || e == 7) {
						pass[e] = '*'; 
					}
					if (e == 0 || e == 2 || e == 4 || e == 6) {
						pass[e] = account->accounts[remove - 1].loggin.password[e];
					}
				}
				displayAccountDetailHeader();
				if (account->accounts[remove - 1].acType== 'C') {
					printf("%05d %-9s %5d $%10.2lf %-10s %-15s %-10s %8s\n", account->accounts[remove - 1].accountNum, typC, account->accounts[remove - 1].Demo.birthYear, account->accounts[remove - 1].Demo.inccome, account->accounts[remove - 1].Demo.country, account->accounts[remove - 1].loggin.name, account->accounts[remove - 1].loggin.user, pass);
				}
				if (account->accounts[remove - 1].acType == 'A') {
					printf("%05d %-9s %5d $%10.2lf %-10s %-15s %-10s %8s\n", account->accounts[remove - 1].accountNum, typA, account->accounts[remove - 1].Demo.birthYear, account->accounts[remove - 1].Demo.inccome, account->accounts[remove - 1].Demo.country, account->accounts[remove - 1].loggin.name, account->accounts[remove - 1].loggin.user, pass);
				}
				//Request confirmation
				printf("\nAre you sure you want to remove this record? ([Y]es|[N]o): ");
				confirRemove = getCharOption("YN");
				int ConfR = 0;
				if ( confirRemove == 'Y') {
					ConfR = 1;
				}
				if (ConfR == 1 && account->accounts[remove - 1].accountNum!= logged->accountNum) {//double check to not 
					account->accounts[remove - 1].accountNum= 0;     //Remove the account
					account->accounts[remove - 1].acType= 0;
					account->accounts[remove - 1].Demo.birthYear= 0;
					*account->accounts[remove - 1].Demo.country= 0;
					account->accounts[remove - 1].Demo.inccome= 0;
					*account->accounts[remove - 1].loggin.name= 0;
					*account->accounts[remove - 1].loggin.password= 0;
					*account->accounts[remove - 1].loggin.user= 0;
					printf("\n*** Account Removed! ***\n\n");
					pauseExecution();
					ConfR = 0;
					selection = 8;
					goto K;
				}
				if (confirRemove == 'N') {
					printf("\n*** No changes made! ***\n\n");
					pauseExecution();
					selection = 8;
				}
			}
		}
		if (selection == 4) {//***********************SUMMARY VIEW**************************
				displayAllAccountSummaryRecords(account, Max);
			}
		if (selection == 5) {
			printf("\n");
			displayAllAccountDetailRecords(account, Max);
		}
		if (selection == 6) {
			listNewtickets(account);
		}
		if (selection == 7) {//List active tickets
			listActivetickets(account);
		}
		if (selection == 8) {
			printf("Feature #8 currently unavailable!");
			pauseExecution();
		}
		if (selection == 9) {
			printf("Feature #9 currently unavailable!");
			pauseExecution();
		}
		if (selection == 0) {//********************************EXIT*************************
			goto T;
			//pauseExecution();
		}
	} while (selection != 0);
	T:
		printf("\n### LOGGED OUT ###\n\n");
	}

void listActivetickets(struct AccountTicketingData* account) {
	//based on the status being open(will have a value of 1)
	int i = 0,  ticketNum, index = 0;
	char open[] = "OPEN";
	do {
		printf("\n------ ----- --------------- ------ ------------------------------ --------");
		printf("\nTicket Acct# Display Name    Status Subject                        Messages");
		printf("\n------ ----- --------------- ------ ------------------------------ --------\n");
		//check which status are in open
		for (i = 0; i < account->TICKET_MAX_SIZE; i++) {
			if (account->tickets[i].Status == 1) {
				printf("%06d %5d %-15s %-6s %-30s %5d\n", account->tickets[i].TIckNum, account->tickets[i].NumAcc, account->tickets[i].Mes->MessName, open, account->tickets[i].Subject, account->tickets[i].Counter);
			}
		}
		printf("------ ----- --------------- ------ ------------------------------ --------\n");

		printf("\nEnter the ticket number to view the messages or");
		printf("\n0 to return to previous menu: ");
		ticketNum = getPositiveInteger();
		index = findticketIndex(ticketNum, account);
		if (ticketNum == 0) {
			//goto E;
		}
		if (index == 0) {
			printf("\nERROR: Invalid ticket number.\n\n");
			pauseExecution();
		}
		if (index > 0 && ticketNum != 0) {
			char actypC[9] = "COSTUMER";
			char actypA[9] = "AGENT";

			printf("\n================================================================================");
			printf("\n%06d (OPEN) Re: %s", account->tickets[index - 1].TIckNum, account->tickets[index - 1].Subject);
			printf("\n================================================================================");
			printf("\n ");
			for (i = 0; i < account->TICKET_MAX_SIZE; i++) {
				if (account->tickets[index-1].Status == 1) {
					if (account->tickets[index - 1].Mes[i].MessAcType == 'C') {
						printf("\n%s (%s):", actypC, account->tickets[index - 1].Mes->MessName);
						printf("\n   %s\n", account->tickets[index - 1].Mes[i].MessDetail);
					}
					if (account->tickets[index - 1].Mes[i].MessAcType == 'A') {
						printf("\n%s (%s):", actypA, account->tickets[index - 1].Mes[i].MessName);
						printf("\n   %s\n", account->tickets[index - 1].Mes[i].MessDetail);
					}
				}
			}
			printf("\n");
			pauseExecution();

		}

	} while (ticketNum != 0);


}

void listNewtickets(struct AccountTicketingData* account) {
	//The ticket status must be open (will have a value of 1) and there will be only one (1) message.
	int i=0,  ticketNum, index=0;
	char open[] = "OPEN";
	do {
		printf("\n------ ----- --------------- ------ ------------------------------ --------");
		printf("\nTicket Acct# Display Name    Status Subject                        Messages");
		printf("\n------ ----- --------------- ------ ------------------------------ --------\n");
		//check which status are in open
		for (i = 0; i < account->TICKET_MAX_SIZE; i++) {
			if (account->tickets[i].Counter == 1 && account->tickets[i].Status == 1) {
				printf("%06d %5d %-15s %-6s %-30s %5d", account->tickets[i].TIckNum, account->tickets[i].NumAcc, account->tickets[i].Mes->MessName, open, account->tickets[i].Subject, account->tickets[i].Counter);
			}
		}
		printf("\n------ ----- --------------- ------ ------------------------------ --------\n");

		printf("\nEnter the ticket number to view the messages or");
		printf("\n0 to return to previous menu: ");
		ticketNum = getPositiveInteger();
		index = findticketIndex(ticketNum, account);
		
		if (index == 0) {
			printf("\nERROR: Invalid ticket number.\n\n");
			pauseExecution();
		}
		if (index > 0 && ticketNum!=0) {
			char actypC[9] = "COSTUMER";
			char actypA[9] = "AGENT";

			printf("\n================================================================================");
			printf("\n%06d (OPEN) Re: %s",account->tickets[index-1].TIckNum , account->tickets[index-1].Subject);
			printf("\n================================================================================");
			printf("\n ");
			if (account->tickets[index - 1].Mes->MessAcType == 'C') {
				printf("\n%s (%s):", actypC, account->tickets[index - 1].Mes->MessName);
				printf("\n   %s\n", account->tickets[index-1].Mes->MessDetail);
			}
			if (account->tickets[index - 1].Mes->MessAcType == 'A') {
				printf("\n%s (%s):", actypA, account->tickets[index - 1].Mes->MessName);
				printf("\n   %s\n", account->tickets[index - 1].Mes->MessDetail);
			}
			printf("\n");
			pauseExecution();

		}

	} while (ticketNum != 0);

}

int findticketIndex(int ticketNum, struct AccountTicketingData* account) {
	int max = account->ACCOUNT_MAX_SIZE,i,index=0;
	for (i = 0; i < max; i++) {
		if (ticketNum == account->tickets[i].TIckNum) {
			index = i + 1;
		}
	}
	return index;
}

int findAccountIndexByAcctNum(int accNumber, struct AccountTicketingData* account, int max, int zero) {//SEARCH ARRAYRECIEVED
	int i;
	int match=0;
	int getNum;
	if (zero == 0) {//SEARCH!!
		for (i = 0; i < max; i++) {
			if (account->accounts[i].accountNum == accNumber) {
				match = i+1;
			}
		}
	}
	if(zero != 0) {
		printf("\nEnter the account#: ");
		getNum=getIntFromRange(0, 99999);
		if (zero == 0) {//SEARCH!!
			for (i = 0; i < max; i++) {
				if (account->accounts[i].accountNum == getNum) {
					match = i+1;
				}
			}
		}

	}
	return match;
}

void displayAllAccountSummaryRecords(struct AccountTicketingData account[], int max) {
	int i=0;
	char typC[] = "CUSTOMER" , typA[] = "AGENT";
	displayAccountSummaryHeader();
		for (i = 0; i < max; i++) {
			if (account->accounts[i].accountNum != 0) {
				
				if (account->accounts[i].acType == 'C') {
					printf("%05d %-9s %5d\n", account->accounts[i].accountNum, typC, account->accounts[i].Demo.birthYear);
				}
				if (account->accounts[i].acType == 'A') {
					printf("%05d %-9s %5d\n", account->accounts[i].accountNum, typA, account->accounts[i].Demo.birthYear);
				}
			}
		}
		printf("\n");
	pauseExecution();
}

void displayAllAccountDetailRecords(struct AccountTicketingData* account, int max) {
	char pass[9] = "0", typC[] = "CUSTOMER", typA[] = "AGENT";
	int i=0,e=0;
	displayAccountDetailHeader();	
		for (i = 0; i < max; i++) {
			for (e = 0; e < 8; e++) {
				if (e == 1 || e == 3 || e == 5 || e == 7) {
					pass[e] = '*';
				}
				if (e == 0 || e == 2 || e == 4 || e == 6) {
					pass[e] =  account->accounts[i].loggin.password[e];
				}
			}
			if (account->accounts[i].accountNum!= 0) {
				if (account->accounts[i].acType== 'C') {
					printf("%05d %-9s %5d $%10.2lf %-10s %-15s %-10s %8s\n", account->accounts[i].accountNum, typC, account->accounts[i].Demo.birthYear, account->accounts[i].Demo.inccome, account->accounts[i].Demo.country, account->accounts[i].loggin.name, account->accounts[i].loggin.user, pass);
				}
				if (account->accounts[i].acType == 'A') {
					printf("%05d %-9s %5d $%10.2lf %-10s %-15s %-10s %8s\n", account->accounts[i].accountNum, typA, account->accounts[i].Demo.birthYear, account->accounts[i].Demo.inccome, account->accounts[i].Demo.country, account->accounts[i].loggin.name, account->accounts[i].loggin.user, pass);
				}
			}
		} 
		printf("\n");
		pauseExecution();
}

void pauseExecution(void) {// Pause execution until user enters the enter key
		printf("<< ENTER key to Continue... >>"); 
	clearStandardInputBuffer();
}

void updateAccount(struct AccountTicketingData account[], int max) {

	int numaccount,selection=6, indx = 0;
	printf("\nEnter the account#: ");
	numaccount = getIntFromRange(0, 99999);
	indx = findAccountIndexByAcctNum(numaccount, account, max, 0);

	do {
		printf("\nAccount: %5d - Update Options", numaccount);
		printf("\n----------------------------------------");
		printf("\n1) Update account type (current value: %c)", account->accounts[indx - 1].acType);
		printf("\n2) Login");
		printf("\n3) Demographics");
		printf("\n0) Done");
		printf("\nSelection: ");
		selection = getIntFromRange(0, 3);
		if (selection == 1) {
			//char type;
			printf("\nEnter the account type (A=Agent | C=Customer): ");
			account->accounts[indx - 1].acType= getCharOption("AC");
		}
		if (selection == 2) {

			updateUserLogin(&account->accounts[indx-1]);
		}
		if (selection == 3) {
			updateDemographic(&account->accounts[indx-1]);
		}
	
	} while (selection != 0);
}

void updateUserLogin(struct Account* login) {

	int selection = 6;

	do {
		printf("\nUser Login: %s - Update Options", login->loggin.user);
		printf("\n----------------------------------------");
		printf("\n1) Display name (current value: %s)", login->loggin.name);
		printf("\n2) Password");
		printf("\n0) Done");
		printf("\nSelection: ");
		selection = getIntFromRange(0, 2);
		if (selection == 1) {
			
			printf("\nEnter the display name (30 chars max): ");
			getCString(login->loggin.name,0,30);
		}
		if (selection == 2) {
			getpassword(login);
			/*printf("\nEnter the password (must be 8 chars in length): ");
			getCString(login->loggin.password,8, 8);*/
		}
	} while (selection != 0);
}

void updateDemographic(struct Account* demographic) {
	int selection=8;
	do {
		printf("\nDemographic Update Options");
		printf("\n----------------------------------------");
		printf("\n1) Household Income (current value: $%.2lf)",demographic->Demo.inccome);
		printf("\n2) Country (current value: %s)",demographic->Demo.country);
		printf("\n0) Done");
		printf("\nSelection: ");
		selection = getIntFromRange(0, 2);
		if (selection == 1) {
			printf("\nEnter the household Income: $");
			demographic->Demo.inccome = getPositiveDouble();
		}
		if (selection == 2) {
			getCountry(demographic);
		}
	} while (selection != 0);
}

void displayAccountSummaryHeader() {
	printf("\nAcct# Acct.Type Birth\n");
	printf("----- --------- -----\n");
}

void displayAccountDetailHeader() {
	printf("Acct# Acct.Type Birth Income      Country    Disp.Name       Login      Password\n");
	printf("----- --------- ----- ----------- ---------- --------------- ---------- --------\n");

}