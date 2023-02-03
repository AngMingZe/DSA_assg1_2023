#pragma once
#include<string>
#include<iostream>
using namespace std;

class Account
{
private:
	string username;
	string password;

public:
	Account();
	Account(string username,string password);
	~Account();

	void setUsername(string n);
	string getUsername();
	void setpassword(string p);
	string getPassword();
};

