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

bool LogIn(List accountList,Account& user) {
    //Log in
    string NameInput;
    string PWInput;
    cout << "Username: ";
    getline(cin, NameInput);
    cout << "Password: ";
    getline(cin, PWInput);

    bool checkforRecord = accountList.dataValidation(NameInput,PWInput);
    if (checkforRecord == 1) {
        //cout << "Success" << endl;
        user.setUsername(NameInput);
        user.setpassword(PWInput);
        return true;
    }
    else {
        //cout << "Username or password incorrect" << endl;
        return false;
    }
}

int main()
{
    string Option;//Stores the option of the user
    string temp;
    Account user; //Stores the infomation of the user
    List accountList; //Stores the accounts
    TopicList topicList; //Stores the topics

    LoadAccounts(accountList);

    
    while (true) {
        cout << "Welcome!" << endl;
        cout << "Press 1 to log in, 2 to register for an account if you do not have one" << endl;
        cout << "Press 3 if you want to look around, but you cannot post since you do not have an account" << endl;
        cout << "Enter option: ";
        getline(cin, Option);
        //Log in
        if (Option == "1") {
            //Log in
            bool check;
            string NameInput;
            string PWInput;
            cout << "Username: ";
            getline(cin, NameInput);
            cout << "Password: ";
            getline(cin, PWInput);

            bool checkforRecord = accountList.dataValidation(NameInput, PWInput);
            if (checkforRecord == 1) {
                user.setUsername(NameInput);
                user.setpassword(PWInput);
                check = true;
            }
            else {
                check = false;
            }
            if (check) {
                cout << "Login success!" << endl;
                //Start of user features
                while (true)
                {
                    //View the menu and stuff
                    cout << "1. Create new topic" << endl;
                    cout << "2. See your own posts" << endl;
                    cout << "3. See topics" << endl;
                    cout << "4. Log out" << endl;
                    cout << "Option: ";
                    getline(cin, Option);
                    if (Option == "1") {
                        cout << "Enter topic name: " << endl;
                        Topic newTopic;
                        newTopic.creator = user.getUsername();
                        string topicName;
                        getline(cin, topicName);
                        newTopic.message = topicName;
                        topicList.add(newTopic);
                        //Go into that topic channel
                    }
                    else if (Option == "2") {
                        //display Post list, filtered by username
                        //Another menu to show the things user can do  
                        //topicList.showOwnPost(); -> a function to show posts of user
                    }
                    else if (Option == "3") {
                        topicList.loadTopics();
                        topicList.print();
                    }
                    else if (Option == "4") {
                        user.setUsername("NULL");//Sets username of user to Null to allow for logging in again
                        break;
                    }
                    else {
                        cout << "Please enter only what can be done shown in the menu!" << endl;
                    }
                }
                //End of user menu features
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

            cout << "Registration successful" << endl;
        }

        //View topics 
        else if (Option == "3") {
            topicList.loadTopics();
            topicList.print();
        }

        else { cout << "Please enter 1,2,3 only please" << endl; }
    }
}

