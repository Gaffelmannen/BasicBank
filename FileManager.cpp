#include "FileManager.h"

//namespace fs = std::filesystem;
using namespace std;

const std::string FileManager::BASE_DIR = "files";
const std::string FileManager::ACCOUNT_FILE_HEADER = "-#-account-#-";
const std::string FileManager::FILE_ABBREVATION = ".txt";

FileManager::FileManager()
{

}

void FileManager::WriteToFile(string filename, string content)
{
    std::string path = BASE_DIR + "/" + filename;
    
	ofstream file(path);
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

vector<string> FileManager::ReadFromFile(string filename)
{
    vector<string> content;
    
	string line;
	ifstream file (filename);
	if (file.is_open())
	{
		while ( getline (file, line) )
		{
            content.push_back(line);
		}
        file.close();
	}
	else
	{
		cout << "Unable to open file"; 
	}

    return content;
}

vector<string> FileManager::ListFiles(void)
{
    vector<string> files;
    
	std::string path = BASE_DIR;
    for (const auto & entry : std::filesystem::directory_iterator(path))
	{
        files.push_back(entry.path());
	}
    
	return files;
}

vector<vector<string>> FileManager::ReadAllFiles(void)
{
    vector<vector<string>> data;
    
    vector<string> files = FileManager::ListFiles();
    for (vector<string>::iterator file=files.begin(); file!=files.end(); ++file)
    {
        vector<string> content = FileManager::ReadFromFile(*file);
        data.push_back(content);
    }
    
    return data;
}

void FileManager::SaveAccount(Account* account)
{
    string filename = std::to_string(account->getNumber()) + FILE_ABBREVATION;
    
    string content = ACCOUNT_FILE_HEADER;
    content += "\n";
    content += account->getName() + "\n";
    content += std::to_string(account->getNumber()) + "\n";
    content += account->getType() + "\n";
    content += std::to_string(account->getBalance()) + "\n";
    
    FileManager::WriteToFile(filename, content);
	return;
}

vector<Account> FileManager::LoadAllAccounts(void)
{
    vector<Account> accounts;
    
    vector<vector<string>> contentOfFiles = FileManager::ReadAllFiles();
    for (vector<vector<string>>::iterator file=contentOfFiles.begin(); file!=contentOfFiles.end(); ++file)
    {
        try
        {
            cout << file[0][0] << " ";
            if( file[0][0].compare(ACCOUNT_FILE_HEADER) == 0 )
            {
                Account a;
                a.Account::setName(file[0][1]);
                a.Account::setNumber(stoi(file[0][2]));
                a.Account::setType(file[0][3]);
                a.Account::setBalance(stod(file[0][4]));
                accounts.push_back(a);
                cout << " valid." << endl;
            }
            else
            {
                cout << " NOT valid." << endl;
            }
        }
        catch (const std::exception& e)
        {
            cout << "Something went wrong." << endl;
        }
        
    }
    
    return accounts;
}
