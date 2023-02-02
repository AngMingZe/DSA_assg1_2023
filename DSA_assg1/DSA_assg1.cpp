//Ang Ming Ze,S10203953
//Terrence Eng, 
//DSA P02, Group 4

#include <iostream>
#include <fstream>
#include <string>
#include "pages.h"
#include "List.h"
#include "Topic.h"
#include "TopicList.h"
#include "Account.h"
using namespace std;

void WriteReadFile() {
    // Create and open a text file
    ofstream MyFile("filename.txt");
    MyFile << "1";
    MyFile << "\n2";
    MyFile << "\n3";
    MyFile.close();

    string myText;
    List storage;

    // Read from the text file
    ifstream MyReadFile("filename.txt");

    // Use a while loop together with the getline() function to read the file line by line
    while (getline(MyReadFile, myText)) {
        // Output the text from the file
        // storage.add('The stuff');
    }
    MyReadFile.close();
}

void LoadAccounts(List& Alist){
    ifstream MyReadFile("accounts.txt");
    Account itm;
    string username;
    string password;
    while (getline(MyReadFile, username)) {
        itm.setUsername(username);
        getline(MyReadFile,password);
        itm.setpassword(password);
        Alist.add(itm);
    }
    MyReadFile.close();
}


int main()
{
    string temp;
    List accountList;
    TopicList topicList;

    LoadAccounts(accountList);

    cout << "Welcome!" << endl;
    cout << "Press 1 to log in, 2 to register for an account if you do not have one" << endl;
    cout << "Press 3 if you want to look around, but you cannot post since you do not have an account" << endl;
    while (true) {
        cout << "Enter option: ";
        string Option;
        getline(cin, Option);
        //Log in
        if (Option == "1") {
            //Log in
            cout << "Username: ";
            string NameInput;
            getline(cin, NameInput);
            cout << "Password: ";
            string PWInput;
            getline(cin, PWInput);

            Account inputData;
            inputData.setUsername(NameInput);
            inputData.setpassword(PWInput);

            bool checkforRecord = accountList.dataValidation(inputData);
            if (checkforRecord) {
                cout << "Success" << endl;
            }
            else {
                cout << "Username or password incorrect" << endl;
            }
        }

        //Register account
        else if (Option == "2") {
            //Register account
            cout << "Set a username: ";
            string NameInput;
            getline(cin, NameInput);

            bool duplicateChecker = accountList.checkDuplicates(NameInput);
            if (duplicateChecker) {
                cout << "Username already taken" << endl;
                //continue;
            }
            cout << "Set a password: ";
            string PWInput;
            getline(cin, PWInput);

            Account inputData;
            inputData.setUsername(NameInput);
            inputData.setpassword(PWInput);

            accountList.add(inputData);
            accountList.saveTXT(inputData);

            cout << "Registration successful" << endl;
        }

        //View topics 
        else if (Option == "3") {
            topicList.PrintTopics("Topics.txt");
        }

        else { cout << "Please enter 1,2,3 only please" << endl; }
    }
}
