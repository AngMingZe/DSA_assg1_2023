// List.h - - Specification of List ADT (implemented using Pointers)
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
	TopicList();			// constructor

	~TopicList();// destructor

	// add an item to the back of the list (append)
	// pre : size < MAX_SIZE
	// post: item is added to the back of the list
	//       size of list is increased by 1
	bool add(TopicItem item);

	// add an item at a specified position in the list (insert)
	// pre : 0 <= index <= size
	// post: item is added to the specified position in the list
	//       items after the position are shifted back by 1 position
	//       size of list is increased by 1
	bool add(int index, TopicItem item);

	// remove an item at a specified position in the list
	// pre : 0 <= index < size
	// post: item is removed the specified position in the list
	//       items after the position are shifted forward by 1 position
	//       size of list is decreased by 1
	void remove(int index);

	void remove(string message);

	// get an item at a specified position of the list (retrieve)
	// pre : 0 <= index < size
	// post: none
	// return the item in the specified index of the list
	TopicItem indexGet(int index);

	void stringGet(string message, string newMessage);

	TopicList ownTopics(string username);


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

	void print();

	//------------------- Other useful functions -----------------

	// display the items in the list
	void loadTopics();
	//Load file items into list
	void saveTopics();

	void createTopic(Topic topic);
	
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