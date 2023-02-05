#pragma once
#include<string>
#include<iostream>
#include <fstream>
#include "Topic.h"
#include "PostList.h"
using namespace std;

typedef Topic TopicItem;

class TopicList
{
private:
	struct Node
	{
		TopicItem item;	// data item
		Node* next;	// pointer pointing to next item
	};

	Node* firstNode;	// point to the first item
	int  size;			// number of items in the list

public:
	TopicList(); // constructor

	~TopicList();// destructor

	//Adds a Topic item to the list
	bool add(TopicItem item);


	// Remove an item at a specified position in the list

	void remove(string message);
	// Gets the position of the item 
	int getIndex(string message);
	// pre : 0 <= index < size
	// post: item is removed the specified position in the list
	//       items after the position are shifted forward by 1 position
	//       size of list is decreased by 1
	void remove(int index);

	int getIndex(string message);

	// Retrieve a Topic object/item at a specified position of the list 
	TopicItem indexGet(int index);

	void stringGet(string message, string newMessage);

	//If input == topic in list, return Topic object
	TopicItem getItem(string input);

	//Retrives the topic created by user(the input)
	TopicList ownTopics(string username);


	// check if the list is empty
	bool isEmpty();

	// check the size of the list
	int getLength();

	//Prints the contents of the list
	void print();

	// display the items in the list
	void loadTopics();

	//Load file items into list
	void saveTopics();

	// Creates a Topic object
	void createTopic(Topic topic);
	
	//Reverese the list
	void reverse();

	//Print the list sorted by latest 
	void printByLatest();

	//Searches for the input in the list, if found return true
	bool search(string input);
};