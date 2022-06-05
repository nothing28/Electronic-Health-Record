#ifndef LOGIN_H
#define LOGIN_H
#include <string>

using std::string;

class Login
{
private:
    int input_chances = 5;
    string input_password;

public:
    bool LoginFunctionality(string); //Gives the user total 5 attempts to login the system.
};

#endif