#include <iostream>

using namespace std;

#include "Bank.h"

int main()
{
    Bank b;

    int input;
    while(1)
    {
        cout << "\n";
        cout << "Main Menu:\n";
        cout << "1. Open new account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Inspect\n";
        cout << "5. Exit\n";
        cout << "> ";
        cin >> input;
        switch(input)
        {
            case 1:
                b.Open();
                break;
            case 2:
                b.Deposit();
                break;
            case 3:
                b.Withdraw();
                break;
            case 4:
                b.Inspect();
                break;
            case 5:
                cout << endl << "Bye!" << endl;
                return 0;
        }
    }
}
