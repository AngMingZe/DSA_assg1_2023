#pragma once
#pragma once
#include<string>
#include<iostream>
#include <fstream>
#include "Post.h"
using namespace std;

typedef Post PostItem;

class PostList
{
private:
	struct Node
	{
		PostItem item;	// data item
		Node* next;	// pointer pointing to next item
	};

	Node* firstNode;	// point to the first item
	int  size;			// number of items in the list

public:
	PostList();	// constructor

	~PostList();// destructor

	// parameter: PostItem to be added into linkedList
	// return: true or false
	// adds a node with PostItem into the LinkedList
	bool add(PostItem item);

	// parameter: topicName of Node->PostItem to be removed
	// return: NIL
	// removes the node with the same topicName as parameter
	void remove(string topicName);

	// parameter: index of the PostItem we want
	// return: PostItem at the specified index
	// return the item in the specified index of the list
	PostItem get(int index);

	// parameter: string message used to find PostItem to edit, new string message to change PostItem.message to
	// return: NIL
	// changes the message of the PostItem with the same message as first parameter into the second parameter 
	void EditName(string message, string newMessage);

	// parameter: string topicName used to find PostItem to edit, string new TopicName to change PostItem.topicName to
	// return: NIL
	// changes the topicName of the PostItem with the same message as first parameter into the second parameter 
	void topicEdited(string topicName, string newTopicName);

	// parameter: string topicName to find posts to print
	// return: PostList with only the posts with same topicName (under the topic)
	// creates a PostList and adds all posts with same topicName and prints them
	PostList getPrint(string topicName);

	// parameter: string username to find posts created by user
	// return: PostList with only the posts with same username (created by the user)
	// creates a PostList and adds all posts with same username and prints them
	PostList ownPosts(string username);

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
	// reads the data inside Post.txt and populate them into a LinkedList
	void loadPosts();

	// parameter: NIL
	// return: NIL
	// writes the data in the LinkedList into Post.txt
	void savePosts();
};

