#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

//using namespace std;

class Account
{
	private:
		int number;
		std::string name;
		std::string type;
		double balance;
	public:
		void setNumber(int);
		void setName(std::string);
		void setType(std::string);
		void setBalance(double);
		int getNumber(void);
		std::string getName(void);
		std::string getType(void);
		double getBalance(void);
};

#endif
