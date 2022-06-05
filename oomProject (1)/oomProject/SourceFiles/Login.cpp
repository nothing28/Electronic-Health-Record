#include <iostream>
#include "../HeaderFiles/Login.h"

using namespace std;

bool Login::LoginFunctionality(string correct_password)
{
    cout << "Please enter the password = ";
    cin >> input_password;
    if (input_password == correct_password)
    {
        cout << "Correct password!" << endl;
        cout << endl;
        return true;
    }
    else
    {
        while (input_chances > 1)
        {
            input_chances -= 1;
            cout << "Incorrect password! " << input_chances << " chances remain!" << endl;
            cout << "Please enter your password = ";
            cin >> input_password;
            if (input_password == correct_password)
            {
                cout << "Correct password!" << endl;
                cout << endl;
                return true;
            }
        }
        if (input_chances == 1)
        {
            cout << "Sorry!You are not allowed access to the system" << endl;
            cout << endl;
        }
        return false;
    }
}