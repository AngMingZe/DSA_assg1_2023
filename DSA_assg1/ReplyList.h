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
	ReplyList(); // constructor

	~ReplyList();// destructor

	// parameter: ReplyItem to be added into linkedList
	// return: true or false
	// adds a node with ReplyItem into the LinkedList
	bool add(ReplyItem item);

	// parameter: Node at index to be removed
	// return: NIL
	// removes the node at the index
	void remove(int index);

	// parameter: topicName of Node->ReplyItem to be removed
	// return: NIL
	// removes the node with the same topicName as parameter
	void remove(string topicName);

	// parameter: string message of the ReplyItem
	// return: int index of the Node
	// finds the index of the Node in the LinkedList with Node->item.message
	int getIndex(string message);

	// parameter: index of the ReplyItem we want
	// return: ReplyItem at the specified index
	// return the item in the specified index of the list
	ReplyItem indexGet(int index);

	// parameter: string message used to find ReplyItem to edit, new string message to change ReplyItem.message to
	// return: NIL
	// changes the message of the ReplyItem with the same message as first parameter into the second parameter
	void stringGet(string message, string newMessage);

	// parameter: string topicName used to find ReplyItem to edit, string new TopicName to change ReplyItem.topicName to
	// return: NIL
	// changes the topicName of the ReplyItem with the same message as first parameter into the second parameter 
	void postEdited(string postName, string newPostName);

	// parameter: string topicName to find posts to print
	// return: ReplyList with only the posts with same topicName (under the topic)
	// creates a ReplyList and adds all posts with same topicName and prints them
	void getPrint(string postName);

	// parameter: string username to find posts created by user
	// return: ReplyList with only the posts with same username (created by the user)
	// creates a ReplyList and adds all posts with same username and prints them
	ReplyList ownReplies(string username);

	// parameter: NIL
	// return: true if the list is empty; otherwise returns false
	//check if the list is empty
	bool isEmpty();

	// parameter: NIL
	// return: the number of items in the list
	// check the size of the list
	int getLength();

	//------------------- Saving and Loading Data files -----------------

	// parameter: NIL
	// return: NIL
	// reads the data inside Reply.txt and populate them into a LinkedList
	void loadReplies();

	// parameter: NIL
	// return: NIL
	// writes the data in the LinkedList into Reply.txt
	void saveReplies();
};

