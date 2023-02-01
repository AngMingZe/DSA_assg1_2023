#include <iostream>
#include <fstream>
#include <string>
#include "List.h"
#include "Account.h"
using namespace std;

void registration(List accountList) {
	//Prompt for user info
	//Check if there is the same username in the loaded list
    cout << "Set a username: ";
    string NameInput;
    getline(cin, NameInput);
    cout << "Set a password: ";
    string PWInput;
    getline(cin, PWInput);

    Account inputData;
    inputData.setUsername(NameInput);
    inputData.setpassword(PWInput);

    accountList.add(inputData);
    accountList.saveTXT(accountList);

    cout << "Registration successful" << endl;
}