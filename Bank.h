#include <iostream>
#include <vector>

using namespace std;

#include "Account.h"
#include "FileManager.h"

class Bank
{
	private:
		std::vector<Account> accounts;
		FileManager* fm;	

		Account* findAccountByNumber(int);
	 	void printAccountNotFoundMessage(int);

	public:
		Bank(void);
		~Bank(void);
		void Open();
		void Deposit();
		void Withdraw();
		void Inspect();
};
