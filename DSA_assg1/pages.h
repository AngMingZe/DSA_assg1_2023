#pragma once
#include <iostream>
using namespace std;

//Pages
void TestMenu() {
    cout << "1. Register account" << endl;
    cout << "2. Log In" << endl;
    cout << "3. View all topics" << endl;
    cout << "4. See post by certain user" << endl;
    cout << "5. Create new topic" << endl;
    cout << "6. Create new post" << endl;
    cout << "7. Edit/delete own posts" << endl;
    cout << "8. Reply to posts" << endl;
}

void LogIn() {
    cout << "Username: " << endl;
    cout << "Password: " << endl;
}
//Page 1: Main Page
/*
User: Unknown
cout << "1. Register account" << endl;
cout << "2. Log In" << endl;
3. View all topics
select:
*/

//Page 2: List of Topics
/*
1. Topic
2. Topic
3. Topic
4. Topic
5. Topic
6. Topic
7. Topic
8. Topic
9. Topic
10. Topic
p. page 1
n. page 3
select:
*/

//Page 3: All posts of a topic
/*
Topic Name
Post
Post
Post
Post
Post
select:
*/

//Page 1 Alternative: after log in Main Page
/*
User: Terrence
cout << "1. Log Out" << endl;
2. View all topics and posts
3. View own topics and posts
*/

//Page 2: List of Topics
/*
1. Topic
2. Topic
3. Topic
4. Topic
5. Topic
6. Topic
7. Topic
8. Topic
9. Topic
10. Topic
11. Create own topic
12. next page
select:
*/