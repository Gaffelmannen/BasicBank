#include "Bank.h"

#include <iostream>
#include <iomanip>

using namespace std;

void Bank::Open()
{
	cout << endl << endl;
	
	cout << "Name: ";
	cin>>name;

	cout << "Account number: ";
	cin>>acc_no;

	cout << "Account Type: ";
	cin>>acc_type;

	cout << "Opening Balance: ";
	cin>>balance;

	return;
}

void Bank::Deposit()
{
	return;
}

void Bank::Withdraw()
{
	return;
}

void Bank::Inspect()
{
	return;
}


