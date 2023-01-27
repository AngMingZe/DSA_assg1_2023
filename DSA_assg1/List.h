#pragma once
#include<iostream>
using namespace std;

typedef int ItemType;

class List
{
private:
	struct Node
	{
		ItemType item;	// data item
		Node* next;		// pointer pointing to next node
	};
	Node* firstNode;	// pointer pointing to first node
	int   size;			// number of items in the list

public:
	// constructor
	List();

	// destructor
	~List();

	// add an item to the back of the list (append)
	bool add(ItemType item);

	// add an item at a specified position in the list (insert)
	bool add(int index, ItemType item);

	// remove an item at a specified position in the list
	void remove(int index);

	// get an item at a specified position of the list (retrieve)
	ItemType get(int index);

	// check if the list is empty
	bool isEmpty();

	// check the size of the list
	int getLength();
};
