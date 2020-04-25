#include <iostream>
#include <vector>

using namespace std;

#include "Account.h"

class Bank
{
	private:
		std::vector<Account> accounts;
		Account* findAccountByNumber(int);

	public:
		void Open();
		void Deposit();
		void Withdraw();
		void Inspect();
};
