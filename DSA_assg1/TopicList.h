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

	//parameter:Topic object 
	//return: Returns True if added, false if cannot add
	//Adds a Topic item to the list
	bool add(TopicItem item);

	//parameter:Name of topic user wants to remove
	//return: NIL
	//Removes the topic name from the topic list the user inputs
	void remove(string topicName);
	
	//parameter:index number 
	//return: NIL
	//Removes the object specified at the index in the list
	void remove(int index);

	//parameter:index number 
	//return: Returns Topic object 
	//Finds a Topic object given the input(the index) and returns it
	TopicItem get(int index);

	//parameter:Current topic name and new topic name
	//return: NIL
	//Changes topic name (Editing topic name)
	void EditName(string currentTopicName, string newTopicName);

	//parameter:string input
	//return: NIL
	//Finds the topic object given the name of the object and returns it
	TopicItem getItem(string input);

	//parameter:user's username
	//return: TopicList object
	//Returns a topic list that contains posts that the user posted
	TopicList ownTopics(string username);

	//parameter:NIL
	//return: True or false
	//Checks if list is empty
	bool isEmpty();

	//parameter:NIL
	//return: size of the list
	//Gets the size of the list and returns it
	int getLength();

	//parameter:NIL
	//return: NIL
	//Prints the contents of the list
	void print();

	//parameter:NIL
	//return: NIL
	//Load the topics from the text file and add it into a TopicList object
	void loadTopics();

	//parameter:NIL
	//return: NIL
	//Saves the objects in the list into a text file
	void saveTopics();

	//parameter:Topic object
	//return:NIL
	//Creates a Topic object
	void createTopic(Topic topic);
	
	//parameter:Topic object
	//return:NIL
	//Reverse the list
	void reverse();

	//parameter:string topic name 
	//return:True or false
	//Searches for the input in the list, returns true if found
	bool search(string input);
};