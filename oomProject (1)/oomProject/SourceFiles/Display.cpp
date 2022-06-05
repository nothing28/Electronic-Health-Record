#include <iostream>
#include "../HeaderFiles/Display.h"

using namespace std;

void Display::DisplayPatients(string patients[3])
{
    cout << "The list of your patients => " << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << i + 1 << " . " << patients[i] << endl;
    }
    cout << endl;
}

void Display::DisplayMedicalInfo(string arr[3])
{
    for (int i = 0; i < 3; i++)
    {
        if (i == 2)
            cout << arr[i] << endl;
        else
            cout << arr[i] << " , ";
    }
}