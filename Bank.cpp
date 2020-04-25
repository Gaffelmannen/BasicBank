#include "Bank.h"

#include <iostream>
#include <iomanip>

using namespace std;


int readInt(std::istream& stream)
{
	int i;
	cin>>i;
	return i;
}

double readDecimal(std::istream& stream)
{
	double d;
	cin>>d;
	return d;
}

std::string readString(std::istream& stream)
{
	std::string tmp;
	cin>>tmp;
	return tmp;
}

Account* Bank::findAccountByNumber(int number)
{
	for(unsigned int i = 0; i < accounts.size(); i++)
	{
		if(accounts.at(i).getNumber() == number)
		{
			return &accounts.at(i);
		}
	}

	return NULL;
}

void Bank::Open()
{
	Account a;

	cout << endl << endl;
	
	cout << "Name: ";
	a.Account::setName(readString(cin));
	
	cout << "Account number: ";
	a.Account::setNumber(readInt(cin));

	cout << "Account Type: ";
	a.Account::setType(readString(cin));

	cout << "Opening Balance: ";
	a.Account::setBalance(readDecimal(cin));

	accounts.push_back(a);

	return;
}

void Bank::Deposit()
{
	cout << "Enter account number to deposit to: ";
	int number = readInt(cin);
	Account* a = Bank::findAccountByNumber(number);
	
	if(a == NULL)
	{
		cout << "The specified account number " << number;
		cout << "was not found in the system.";
		cout << "Aborting!";
		return;
	}
	
	cout << "Enter amount to deposit: ";
	double deposit = readDecimal(cin);

	a->Account::setBalance(a->Account::getBalance() + deposit);

	return;
}

void Bank::Withdraw()
{
	return;
}

void Bank::Inspect()
{
	cout << "\n";
	cout << "List of all " << accounts.size() <<  " accounts: " << "\n";
	cout << "======================" << "\n";
	for(unsigned int i = 0; i < accounts.size(); i++)
	{
		cout << accounts.at(i).getName() << "\n";
		cout << accounts.at(i).getNumber() << "\n";
		cout << accounts.at(i).getType() << "\n";
		cout << accounts.at(i).getBalance() << "\n";
	}
	cout << "======================" << "\n";

	return;
}


