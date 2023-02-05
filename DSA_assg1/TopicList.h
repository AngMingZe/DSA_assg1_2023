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

	// Adds a Topic item to the list at aspecified position 
	bool add(int index, TopicItem item);

	// Remove an item at a specified position in the list
	void remove(int index);

	// Gets the position of the item 
	int getIndex(string message);

	// Retrieve a Topic object/item at a specified position of the list 
	TopicItem indexGet(int index);

	TopicItem stringGet(string message);

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