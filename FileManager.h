#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <vector>

#include "Account.h"

using namespace std;

class FileManager
{
	private:
		static const std::string BASE_DIR;

		void WriteToFile(std::string, std::string);
        vector<string> ReadFromFile(std::string);
		vector<string> ListFiles(void);
        vector<vector<string>> ReadAllFiles(void);

	public:
		FileManager(void);
		void SaveAccount(Account*);
		vector<Account> LoadAllAccounts(void);
};

#endif
