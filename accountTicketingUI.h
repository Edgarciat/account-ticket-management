// ===================================================================================
//  Assignment: 2 //  Milestone : 2
// ===================================================================================
//  Student Name  : Edgar David Garcia Torres
//  Student ID    : 104433206
//  Student Email : edgarciat-torres@myseneca.ca
//  Course Section: ZZA
// ===================================================================================
#ifndef ACCOUNT_TICKETINGUI_H_
#define ACCOUNT_TICKETINGUI_H_
// Header file contents goes here...
#include "account.h"
#include "commonHelpers.h"
#include <string.h>

struct Message {
	char MessAcType;
	char MessName[30];
	char MessDetail[150];
};

struct Ticket {
	int TIckNum;
	int NumAcc;
	int Status;
	char Subject[30];
	int Counter;
	struct Message Mes[20];
};

struct AccountTicketingData {
	struct Account* accounts; // array of accounts const
	int ACCOUNT_MAX_SIZE; // maximum elements for account array
	struct Ticket* tickets; // array of tickets
	const int TICKET_MAX_SIZE; // maximum elements for ticket array 
};

void displayAccountSummaryHeader();

void displayAccountDetailHeader();

void applicationStartup(struct AccountTicketingData* account); //ENTRY POINT LOGIC

int menuLogin(struct AccountTicketingData* account);

void menuCustomer(struct AccountTicketingData account[], struct Account* logged);

void menuAgent(struct AccountTicketingData account[], struct Account* logged);

void listActivetickets(struct AccountTicketingData* account);

void listNewtickets(struct AccountTicketingData* account);

int findticketIndex(int ticketNum, struct AccountTicketingData* account);

int findAccountIndexByAcctNum(int accNumber, struct AccountTicketingData* account, int max, int zero);

void displayAllAccountSummaryRecords(struct AccountTicketingData account[], int max);

void displayAllAccountDetailRecords(struct AccountTicketingData* account, int max);

void pauseExecution(void);

void updateAccount(struct AccountTicketingData account[], int max);

void updateUserLogin(struct Account* login);

void updateDemographic(struct Account* demographic);

#endif 