#pragma once
#include<iostream>
#include<string>
using namespace std;

class Post
{
private:
	string username;
	string message;

public:
	Post();
	Post(string username, string message);

	void setUsername(string n);
	string getUsername();
	void setMessage(string p);
	string getMessage();
};

