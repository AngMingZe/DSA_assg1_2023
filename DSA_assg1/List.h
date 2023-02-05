// List.h - - Specification of List ADT (implemented using Pointers)
#pragma once
#include<string>
#include<iostream>
#include <fstream>
#include "Account.h"
using namespace std;

typedef Account ItemType;

class List
{
private:
	struct Node
	{
		ItemType item;	// item
		Node* next;	// pointer pointing to next item
	};
	Node* firstNode;	// point to the first item
	int  size;		// number of items in the list

public:
	// constructor
	List();
	// destructor
	~List();

	//parameter:Account object
	//return: True or false
	//Adds an Account class type item to the back of the list, success returns true
	bool add(Account item);

	//parameter:NIL
	//return: True or false
	//Checks if list is empty
	bool isEmpty();

	//parameter:NIL
	//return: length of the list
	//Gets the length of the List
	int getLength();

	//parameter:NIL
	//return: NIL
	//Prints Account objects stored in the List
	void printAccounts();

	//parameter:NIL
	//return: NIL
	//Saves the objects in the list into a text file
	void saveTXT(Account item);

	//parameter:NIL
	//return: True or false
	//Data validation for logging in
	bool dataValidation(string name, string pw);

	//parameter:NIL
	//return: True or false
	//Check if username already exist in data when user is registering
	bool checkDuplicates(string username);
};
