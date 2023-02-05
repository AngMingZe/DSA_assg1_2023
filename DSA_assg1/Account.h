#pragma once
#include<string>
#include<iostream>
using namespace std;

class Account
{
private:
	string username; //Stores the username of the user
	string password; //Stores the password of the user

public:
	Account();
	Account(string username,string password);
	~Account();

	//Set and getters for private variables
	void setUsername(string n);
	string getUsername();
	void setpassword(string p);
	string getPassword();
};

