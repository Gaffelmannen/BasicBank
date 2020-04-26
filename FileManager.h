#include <iostream>
#include <fstream>

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
		void SaveAccount(Account*);
		Account* LoadAllAccounts(void);
};
