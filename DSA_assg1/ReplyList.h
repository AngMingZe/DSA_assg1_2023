#pragma once
#include<string>
#include<iostream>
#include <fstream>
#include "Reply.h"
using namespace std;

typedef Reply ReplyItem;

class ReplyList
{
private:
	struct Node
	{
		ReplyItem item;	// data item
		Node* next;	// pointer pointing to next item
	};

	Node* firstNode;	// point to the first item
	int  size;			// number of items in the list

public:
	ReplyList();			// constructor

	~ReplyList();// destructor

	// add an item to the back of the list (append)
	// pre : size < MAX_SIZE
	// post: item is added to the back of the list
	//       size of list is increased by 1
	bool add(ReplyItem item);

	// remove an item at a specified position in the list
	// pre : 0 <= index < size
	// post: item is removed the specified position in the list
	//       items after the position are shifted forward by 1 position
	//       size of list is decreased by 1
	void remove(int index);

	void remove(string topicName);

	int getIndex(string message);

	// get an item at a specified position of the list (retrieve)
	// pre : 0 <= index < size
	// post: none
	// return the item in the specified index of the list
	ReplyItem indexGet(int index);

	void stringGet(string message, string newMessage);

	void postEdited(string postName, string newPostName);

	void getPrint(string postName);

	ReplyList ownReplies(string username);

	// check if the list is empty
	// pre : none
	// post: none
	// return true if the list is empty; otherwise returns false
	bool isEmpty();

	// check the size of the list
	// pre : none
	// post: none
	// return the number of items in the list
	int getLength();

	//------------------- Other useful functions -----------------

	// display the items in the list
	void print();

	void loadReplies();

	void saveReplies();

	// void replace(int index, ReplyItem item);
	// int search(ReplyItem item);
};

