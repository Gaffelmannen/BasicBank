#include "Account.h"

void Account::setName(std::string value)
{
	name = value;
}

void Account::setNumber(int value)
{
	number = value;
}

void Account::setType(std::string value)
{
	type = value;
}

void Account::setBalance(double value)
{
	balance = value;
}

std::string Account::getName(void)
{
	return name;
}

int Account::getNumber(void)
{
	return number;
}

std::string Account::getType(void)
{
	return type;
}

double Account::getBalance(void)
{
	return balance;
}
