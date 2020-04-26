#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

#include "Account.h"

using namespace std;

class FileManager
{
	private:
		static const std::string BASE_DIR;

		void WriteToFile(std::string, std::string);
		std::string ReadFromFile(std::string);
		std::string* ListFiles(void);

	public:
		FileManager();
		void SaveAccount(Account*);
		Account* LoadAllAccounts(void);
};

#endif
