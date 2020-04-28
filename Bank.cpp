#include "Bank.h"

#include <iostream>
#include <iomanip>

using namespace std;
//using namespace fs;

Bank::Bank(void)
{
	Bank::fm = new FileManager();
    accounts = fm->FileManager::LoadAllAccounts();
}

Bank::~Bank(void)
{
	delete fm;
}

void Bank::printAccountNotFoundMessage(int number)
{
	cout << "The specified account number " << number;
	cout << " was not found in the system.";
	cout << " Aborting!";
	return;
}

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
		printAccountNotFoundMessage(number);
		return;
	}
	
	cout << "Enter amount to deposit: ";
	double deposit = readDecimal(cin);

	a->Account::setBalance(a->Account::getBalance() + deposit);
    fm->FileManager::SaveAccount(a);

	return;
}

void Bank::Withdraw()
{
	cout << "Enter account number to withdraw from: ";
	int number = readInt(cin);
	Account* a = Bank::findAccountByNumber(number);

	if(a == NULL)
	{
		printAccountNotFoundMessage(number);
		return;
	}

	cout << "Enter amount to withdraw: ";
	double withdraw = readDecimal(cin);

	double newBalance = a->Account::getBalance() - withdraw;
	if(newBalance > 0)
	{
		a->Account::setBalance(newBalance);
		cout << "The amount has been withdrawn from the account.\n";
        
        fm->FileManager::SaveAccount(a);
	}
	else
	{
		cout << "Error! Insufficent funds. Aborting!\n";
	}

	return;
}

void Bank::Inspect()
{
	cout << "\n";
	cout << "List of all " << accounts.size() <<  " accounts: " << "\n";
	cout << "===============================" << "\n";
    cout << "Name" << "\t";
    cout << "Number" << "\t";
    cout << "Type" << "\t";
    cout << "Balance" << "\t";
    cout << endl;
    cout << "===============================" << "\n";
	for(unsigned int i = 0; i < accounts.size(); i++)
	{
		cout << accounts.at(i).getName() << "\t";
		cout << accounts.at(i).getNumber() << "\t";
		cout << accounts.at(i).getType() << "\t";
		cout << accounts.at(i).getBalance() << "\t";
        cout << endl;
	}
	cout << "===============================" << "\n";

	return;
}


