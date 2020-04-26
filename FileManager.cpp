#include "FileManager.h"

//namespace fs = std::filesystem;

const std::string FileManager::BASE_DIR = "files";

FileManager::FileManager()
{

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
	std::string path = BASE_DIR;
	for (const auto & entry : std::filesystem::directory_iterator(path))
	{
		std::cout << entry.path() << std::endl;
	}
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
