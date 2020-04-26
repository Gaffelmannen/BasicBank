#include "FileManager.h"

FileManager::FileManager()
{
	BASE_DIR = "files";
}

void FileManager::WriteToFile(std::string filename, std::string content)
{
	ofstream file(filename);
	if(file.is_open())
	{
		file << content;
		file.close();
	}
	else
	{
		cout << "Unable to open file.\n";
	}

	return;
}

std::string FileManager::ReadFromFile(std::string filename)
{
	return NULL;
}

std::string* FileManager::ListFiles(void)
{
	return NULL;
}

void FileManager::SaveAccount(Account* account)
{
	return;
}

Account* FileManager::LoadAllAccounts(void)
{
	return NULL;
}
