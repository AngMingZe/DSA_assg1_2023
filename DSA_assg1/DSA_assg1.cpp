//Ang Ming Ze,S10203953
//Terrence Eng, 
//DSA P02, Group 4

#include <iostream>
#include <fstream>
#include <string>
#include "registration.cpp"
#include "pages.h"
#include "List.h"
#include "Topic.h"
//#include "Account.h"
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

extern void registration(List accountList);

void PrintTopics(string fileName) {
    /*ifstream TopicFile;
    TopicFile.open("Topics.txt", ios::out);*/
    ifstream file(fileName);

    // Check if the file was successfully opened
    if (!file.is_open()) {
        cout << "Failed to open file " << fileName << endl;
        return;
    }

    // Read the contents of the file line by line
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }

    // Close the file
    file.close();
}

int main()
{
    string temp;
    List accountList;
    Topic topicList;

    LoadAccounts(accountList);

    while (temp != "0")
    {
        TestMenu();
        cout << "Enter number: ";
        getline(cin, temp);

        if (temp == "1") {
            //Register account
            cout << "Set a username: ";
            string NameInput;
            getline(cin, NameInput);

            bool duplicateChecker = accountList.checkDuplicates(NameInput);
            if (duplicateChecker) {
                cout << "Username already taken" << endl;
                continue;
            }
            cout << "Set a password: ";
            string PWInput;
            getline(cin, PWInput);

            Account inputData;
            inputData.setUsername(NameInput);
            inputData.setpassword(PWInput);

            accountList.add(inputData);
            accountList.saveTXT(inputData);

            cout << "Registration successful"<< endl;
        }

        else if (temp == "2") {
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
        
        else if (temp == "3") {
            PrintTopics("Topics.txt");
        }
        else if (temp == "4") {
            //See post by certain user
        }
        else if (temp == "5") {
            //ask for input
            //data vlaidation
        }
        else if (temp == "6") {
            //Create new post
        }
        else if (temp == "7") {
            //Edit / delete post
        }
        else if (temp == "8") {
            //Reply to post
        }
        else {
            cout << "Please enter a number in the menu!" << endl;
        }
    }
}
