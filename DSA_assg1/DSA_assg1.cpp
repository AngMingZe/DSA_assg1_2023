//Ang Ming Ze,S10203953
//Terrence Eng, 
//DSA P02, Group 4
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>

#include "pages.h"
#include "List.h"
#include "Account.h"
#include "TopicList.h"
#include "PostList.h"
#include "ReplyList.h"

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

void createTopic(TopicList topicList, Account user) {
    cout << "Enter topic: ";
    string message;
    getline(cin, message);
    Topic newTopic;
    newTopic.creator = user.getUsername();
    newTopic.message = message;
    topicList.add(newTopic);
    topicList.saveTopics();
}

bool numberCheck(string str) {
    for (int i = 0; i <= str.length(); i++) {
        if (isdigit(str[i])) {
            return true;
        }
    }
    return false;
}

int main()
{
    string Option;//Stores the option of the user
    string temp;
    Account user; //Stores the infomation of the user
    List accountList; //Stores the accounts
    TopicList topicList; //Stores the topics
    PostList postList; //Stores the posts
    ReplyList replyList; //Stores the replies

    LoadAccounts(accountList);
    topicList.loadTopics();
    postList.loadPosts();
    replyList.loadReplies();

    cout << "Welcome!" << endl;
    cout << "How would you like to sort the topics today?" << endl;
    cout << "1. by Oldest" << endl;
    cout << "2. by Latest" << endl;
    string sortInput;
    getline(cin, sortInput);
    if (sortInput == "1") {
        cout << "Topics will be in order of oldest to latest" << endl;
    }
    else if (sortInput == "2") {
        topicList.reverse();
        cout << "Topics will be in order of latest to oldest" << endl;
    }

    while (true) {
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
                        createTopic(topicList, user);
                        //maybe put this in see topics section
                    }
                    else if (Option == "2") {
                        while (true) {
                            //print all topics, posts and replies from if topic.creator == user.getusername()
                            cout << "Topics" << endl;
                            TopicList ownTopics = topicList.ownTopics(user.getUsername());
                            cout << endl;
                            cout << "Posts" << endl;
                            PostList ownPosts = postList.ownPosts(user.getUsername());
                            cout << endl;
                            cout << "Replies" << endl;
                            ReplyList ownReplies = replyList.ownReplies(user.getUsername());
                            cout << "Edit/Delete/Back: ";
                            getline(cin, Option);
                            //convert input to lowercase
                            transform(Option.begin(), Option.end(), Option.begin(),
                                [](unsigned char c) { return tolower(c); });
                            if (Option == "edit") {
                                cout << "Topic/Post/Reply: ";
                                getline(cin, Option);
                                transform(Option.begin(), Option.end(), Option.begin(),
                                    [](unsigned char c) { return tolower(c); });
                                if (Option == "topic") {
                                    cout << "which? ";
                                    getline(cin, Option);
                                    if (!numberCheck(Option) || stoi(Option) > ownTopics.getLength() - 1) {
                                        cout << "invalid topic number, please try again." << endl;
                                    }
                                    else if (stoi(Option) >= 0) {
                                        //get the topic
                                        Topic selectedTopic = ownTopics.indexGet(stoi(Option));
                                        //ask for new message
                                        cout << "new message: ";
                                        string message;
                                        getline(cin, message);
                                        //find the selectedTopic in topicList;
                                        topicList.stringGet(selectedTopic.message, message);
                                        postList.topicEdited(selectedTopic.message, message);
                                        //change name of topic in post.txt
                                        // parsh in selectedTopic.message
                                        // create temp go through all nodes
                                        // if topicName == selectedTopic.message
                                        // change post

                                        topicList.saveTopics();
                                        postList.savePosts();
                                    }
                                    else {
                                        cout << "incorrect input";
                                    }
                                }
                                else if (Option == "post") {
                                    cout << "which? ";
                                    getline(cin, Option);
                                    if (!numberCheck(Option) || stoi(Option) > ownPosts.getLength() - 1) {
                                        cout << "invalid post number, please try again." << endl;
                                    }
                                    else if (stoi(Option) >= 0) {
                                        //get the topic
                                        Post selectedPost = ownPosts.indexGet(stoi(Option));
                                        //ask for new message
                                        cout << "new message: ";
                                        string message;
                                        getline(cin, message);
                                        //find the selectedTopic in topicList;
                                        postList.stringGet(selectedPost.message, message);
                                        replyList.postEdited(selectedPost.message, message);
                                        postList.savePosts();
                                        replyList.saveReplies();
                                    }
                                    else {
                                        cout << "incorrect input";
                                    }
                                }
                                else if (Option == "reply") {
                                    cout << "which? ";
                                    getline(cin, Option);
                                    if (!numberCheck(Option) || stoi(Option) > ownReplies.getLength() - 1) {
                                        cout << "invalid reply number, please try again." << endl;
                                    }
                                    else if (stoi(Option) >= 0) {
                                        //get the topic
                                        Reply selectedReply = ownReplies.indexGet(stoi(Option));
                                        //ask for new message
                                        cout << "new message: ";
                                        string message;
                                        getline(cin, message);
                                        //find the selectedTopic in topicList;
                                        replyList.stringGet(selectedReply.message, message);
                                        replyList.saveReplies();
                                    }
                                    else {
                                        cout << "incorrect input";
                                    }
                                }
                                else {
                                    cout << "incorrect input";
                                }
                            }
                            else if (Option == "delete") {
                                cout << "Topic/Post/Reply: ";
                                getline(cin, Option);
                                transform(Option.begin(), Option.end(), Option.begin(),
                                    [](unsigned char c) { return tolower(c); });
                                if (Option == "topic") {
                                    cout << "which? ";
                                    getline(cin, Option);
                                    if (!numberCheck(Option) || stoi(Option) > ownTopics.getLength() - 1 ) {
                                        cout << "invalid topic number, please try again." << endl;
                                    }
                                    else if (stoi(Option) >= 0) {
                                        //get the topic
                                        Topic selectedTopic = ownTopics.indexGet(stoi(Option));
                                        topicList.remove(selectedTopic.message);
                                        postList.remove(selectedTopic.message);
                                        //search for postName
                                        //if return false, remove
                                        //horrible time complexity
                                        topicList.saveTopics();
                                    }
                                    else {
                                        cout << "incorrect input";
                                    }
                                }
                                else if (Option == "post") {
                                    cout << "which? ";
                                    getline(cin, Option);
                                    if (!numberCheck(Option) || stoi(Option) > ownPosts.getLength() - 1 ) {
                                        cout << "invalid post number, please try again." << endl;
                                    }
                                    else if (stoi(Option) >= 0) {
                                        //get the topic
                                        Post selectedPost = ownPosts.indexGet(stoi(Option));
                                        //find the selectedTopic in topicList;
                                        postList.remove(selectedPost.message);
                                        replyList.remove(selectedPost.message);
                                        cout << "4" << endl;
                                        postList.savePosts();
                                        replyList.saveReplies();
                                    }
                                    else {
                                        cout << "incorrect input";
                                    }
                                }
                                else if (Option == "reply") {
                                    cout << "which? ";
                                    getline(cin, Option);
                                    if (!numberCheck(Option) || stoi(Option) > ownReplies.getLength() - 1) {
                                        cout << "invalid reply number, please try again." << endl;
                                    }
                                    else if (stoi(Option) >= 0) {
                                        //get the topic
                                        Reply selectedReply = ownReplies.indexGet(stoi(Option));
                                        //find the selectedTopic in topicList;
                                        int index = replyList.getIndex(selectedReply.message);
                                        replyList.remove(index);
                                        replyList.saveReplies();
                                    }
                                    else {
                                        cout << "incorrect input";
                                    }
                                }
                                else {
                                    cout << "incorrect input";
                                }
                            }
                            else if (Option == "back") {
                                break;
                            }
                            else {
                                cout << "wrong input" << endl;
                            }
                        }
                    }
                    else if (Option == "3") {
                        while (true) {
                            topicList.print();
                            cout << "Topic to view (negative number to go back): ";
                            getline(cin, Option);
                            if (!numberCheck(Option) || stoi(Option) > topicList.getLength() - 1) {
                                cout << "invalid topic number, please try again." << endl;
                            }
                            else if (stoi(Option) >= 0) {
                                //view all posts of the topic
                                //get topic
                                Topic topicName = topicList.indexGet(stoi(Option));
                                while (true) {
                                    //print chosen topic
                                    cout << topicName.message << endl << endl;
                                    // go through all posts, if post.topicName = topic.message then print
                                    // create new PostList and have it contain only the post of the topic
                                    PostList topicPosts = postList.getPrint(topicName.message);
                                    cout << "view Replies (negative number to go back) or 'create' to create new post: ";
                                    getline(cin, Option);
                                    transform(Option.begin(), Option.end(), Option.begin(),
                                        [](unsigned char c) { return tolower(c); });
                                    if (Option == "create") {
                                        //create new post
                                        cout << "Enter post: ";
                                        string message;
                                        getline(cin, message);
                                        Post newPost;
                                        newPost.creator = user.getUsername();
                                        newPost.topicName = topicName.message;
                                        newPost.message = message;
                                        postList.add(newPost);
                                        postList.savePosts();
                                    }
                                    else if (!numberCheck(Option) || stoi(Option) > topicPosts.getLength() - 1 ) {
                                        cout << "invalid post number, please try again." << endl;
                                    }
                                    else if (stoi(Option) >= 0) {
                                    
                                        // view replies
                                        Post postName = topicPosts.indexGet(stoi(Option));
                                        cout << postName.message << endl << endl;
                                        replyList.getPrint(postName.message);
                                        cout << "'reply' to reply (negative number to go back): ";
                                        getline(cin, Option);
                                        transform(Option.begin(), Option.end(), Option.begin(),
                                            [](unsigned char c) { return tolower(c); });
                                        if (Option == "reply") {
                                            //create new reply
                                            cout << "Enter post: ";
                                            string message;
                                            getline(cin, message);
                                            Reply newReply;
                                            newReply.creator = user.getUsername();
                                            newReply.postName = postName.message;
                                            newReply.message = message;
                                            replyList.add(newReply);
                                            replyList.saveReplies();
                                        }
                                    }

                                    else {
                                        break;
                                    }
                                }
                            }
                            else {
                                break;
                            }
                        }
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
            while (true) {
                topicList.print();
                cout << "Topic to view (negative number to go back, 'search' to search for topic): ";
                getline(cin, Option);
                transform(Option.begin(), Option.end(), Option.begin(),
                    [](unsigned char c) { return tolower(c); });
                if (Option == "search") {
                    cout << "Enter topic:";
                    string input;
                    getline(cin, input);
                    bool result = topicList.search(input);
                    if (result) {
                        Topic topicName = topicList.getItem(input);
                        while (true) {
                            //print chosen topic
                            cout << topicName.message << endl << endl;
                            //go through all posts, if post.topicName = topic.message then print
                            // need to create a postlist object
                            // have it contain only the post of the topic
                            PostList topicPosts = postList.getPrint(topicName.message);
                            cout << "View Replies (negative number to go back): ";
                            getline(cin, Option);
                            if (!numberCheck(Option) || stoi(Option) > topicPosts.getLength() - 1) {
                                cout << "invalid post number, please try again." << endl;
                            }
                            else if (stoi(Option) >= 0) {
                                Post postName = topicPosts.indexGet(stoi(Option));
                                cout << postName.message << endl << endl;
                                replyList.getPrint(postName.message);
                                cout << "enter anything to go back: ";
                                getline(cin, Option);
                                if (Option != "") {
                                    continue;
                                }
                            }
                            else {
                                break;
                            }
                        }
                    }
                    else {
                        cout << "Topic was not found" << endl;
                    }
                }
                else if (!numberCheck(Option) || stoi(Option) > topicList.getLength() - 1) {
                    cout << "invalid topic number, please try again." << endl;
                }
                else if (stoi(Option) >= 0) {
                    //view all posts of the topic
                    //get topic
                    Topic topicName = topicList.indexGet(stoi(Option));
                    while (true) {
                        //print chosen topic
                        cout << topicName.message << endl << endl;
                        //go through all posts, if post.topicName = topic.message then print
                        // need to create a postlist object
                        // have it contain only the post of the topic
                        PostList topicPosts = postList.getPrint(topicName.message);
                        cout << "View Replies (negative number to go back): ";
                        getline(cin, Option);
                        if (!numberCheck(Option) || stoi(Option) > topicPosts.getLength() - 1) {
                            cout << "invalid post number, please try again." << endl;
                        }
                        else if (stoi(Option) >= 0) {
                            Post postName = topicPosts.indexGet(stoi(Option));
                            cout << postName.message << endl << endl;
                            replyList.getPrint(postName.message);
                            cout << "enter anything to go back: ";
                            getline(cin, Option);
                            if (Option != "") {
                                continue;
                            }
                        }
                        else {
                            break;
                        }
                    }
                }
                else {
                    break;
                }
            }
        }

        else { cout << "Please enter 1,2,3 only please" << endl; }
    }
}

