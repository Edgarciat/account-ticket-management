// ===================================================================================
//  Assignment: 2 //  Milestone : 2
// ===================================================================================
//  Student Name  : Edgar David Garcia Torres
//  Student ID    : 104433206
//  Student Email : edgarciat-torres@myseneca.ca
//  Course Section: ZZA
// ===================================================================================
#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include "accountTicketingUI.h"

struct Demographic {
	int birthYear;
	double inccome;
	char country[30];
	};

struct UserLogin {
	char name[30];
	char user[30];
	char password[30];
	};
//
struct Account {
	int accountNum;
	char acType;
	struct UserLogin loggin;
	struct Demographic Demo;
};

void getAccount(struct AccountTicketingData* database, struct Account account[]); //receives a modifiable Account piounter argument

void getUserLogin(struct Account* login); //Recieves a modifiable UserLogin pointer argument

void getuser(struct Account* login);

void getpassword(struct Account* login);

void getDemographic(struct Account* demo); //Recieves a modifiable pointer argument

void getCountry(struct Account* demo);
// Header file contents goes here...
#endif // !COMMON_HELPERS_H_