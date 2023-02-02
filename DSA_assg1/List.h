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

	//Adds an Account class type item to the back of the list
	bool add(ItemType item);

	//Checks if list is empty
	bool isEmpty();

	//Gets the length of the List
	int getLength();

	//Prints the data store in the List
	void printAccounts();

	// save data to txt file
	void saveTXT(Account item);

	//Data validation for logging in
	bool dataValidation(Account data);

	//Check if username already exist in data when user is registering
	bool checkDuplicates(string username);
};

//Topic
//struct Node
//{
//	ItemType item;	// item
//	Node* next;	// point to next topic
//};
//
//Post
//struct Node
//{
//	ItemType item;	// item
//	Node* topic;	// point to topic
//
//};
//
//Replies
//struct Node
//{
//	ItemType item;	// item
//	Node* post;	// point to post
//};