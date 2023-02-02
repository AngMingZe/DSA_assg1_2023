#pragma once
#include<iostream>
#include<string>
using namespace std;


class Reply
{
private:
	string username;
	string message;

public:
	Reply();
	Reply(string username, string message);

	void setUsername(string n);
	string getUsername();
	void setMessage(string m);
	string getMessage();
};

