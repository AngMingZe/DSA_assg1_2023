#pragma once
#include<iostream>
#include<string>
using namespace std;


class Topic
{
private:
	string username;
	string message;

public:
	Topic();
	Topic(string username, string message);

	void setUsername(string n);
	string getUsername();
	void setMessage(string p);
	string getMessage();
};

