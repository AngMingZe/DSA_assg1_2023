#pragma once
#include <iostream>
using namespace std;

//Pages
void TestMenu() {
    cout << "1. Register account" << endl;
    cout << "2. Log In" << endl;
    cout << "3. See post by certain user" << endl;
    cout << "4. Create new topic" << endl;
    cout << "5. Create new post" << endl;
    cout << "6. Edit/delete own posts" << endl;
    cout << "6. Reply to posts" << endl;
}

void LogIn() {
    cout << "Username: " << endl;
    cout << "Password: " << endl;
}