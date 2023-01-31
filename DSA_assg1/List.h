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

	bool add(ItemType item);
	bool add(int index, ItemType item);
	void remove(int index);
	string get(int index);
	bool isEmpty();
	int getLength();
	void printAccounts();

	// save data to txt file
	void saveTXT(List accountList);
};


