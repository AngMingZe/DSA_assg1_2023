#include "PostList.h"
#include<string>
#include<iostream>
using namespace std;

PostList::PostList()
{
	firstNode = NULL;
	size = 0;
}

PostList::~PostList()
{
	while (firstNode != NULL) {
		Node* temp = firstNode;
		firstNode = firstNode->next;
		delete temp;
	}
	firstNode = NULL;
}


bool PostList::add(PostItem item)
{
	Node* newNode = new Node;
	newNode->item = item;
	newNode->next = NULL;

	if (size == 0)
	{
		firstNode = newNode;
	}
	else
	{
		Node* temp = firstNode;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newNode;
	}
	size++;
	return true;
}


void PostList::remove(string message) {
	Node* prev = firstNode;
	if (prev->item.message == message)
	{
		firstNode = firstNode->next;
		delete prev;
	}
	else
	{
		Node* temp = firstNode->next;
		while (temp->item.message != message)
		{
			temp = temp->next;
			prev = prev->next;
		}
		prev->next = temp->next;
		delete temp;
	}
	size--;
}

PostItem PostList::get(int index)
{
	if (index >= 0 && index <= size)
	{
		int indexCount = 0;
		Node* temp = firstNode;
		while (indexCount != index)
		{
			temp = temp->next;
			indexCount++;
		}
		return temp->item;
	}
}

//change name of messsage in post.txt
void PostList::EditName(string message, string newMessage)
{
	Node* temp = firstNode;
	while (temp != NULL)
	{
		if (temp->item.message == message) {
			temp->item.message = newMessage;
			break;
		}
		temp = temp->next;
	}
}

//change name of topic in post.txt
void PostList::topicEdited(string topicName, string newTopicName)
{
	Node* temp = firstNode;
	while (temp != NULL)
	{
		if (temp->item.topicName == topicName) {
			temp->item.topicName = newTopicName;
		}
		temp = temp->next;
	}
	// parsh in selectedTopic.message
	// create temp go through all nodes
	// if topicName == selectedTopic.message
	// change post
}

PostList PostList::getPrint(string topicName) {
	//go through all posts, if post.topicName = topic.message then print
	PostList postList;
	Node* temp = firstNode;
	int index = 0;
	while (temp != NULL)
	{
		if (temp->item.topicName == topicName) {
			cout << index << "." << temp->item.message << endl;
			index++;
			postList.add(temp->item);
		}
		temp = temp->next;
	}
	return postList;
}

PostList PostList::ownPosts(string username) {

	PostList postList;
	Node* temp = firstNode;
	int index = 0;
	while (temp != NULL)
	{
		if (temp->item.creator == username) {
			cout << index << "." << temp->item.message << endl;
			index++;
			postList.add(temp->item);
		}
		temp = temp->next;
	}
	return postList;
}

bool PostList::isEmpty()
{
	if (size > 0) {
		return false;
	}
	else {
		return true;
	}
}

int PostList::getLength()
{
	return size;
}

void PostList::loadPosts()
{
	ifstream postFile("Post.txt");
	string line;
	while (getline(postFile, line))
	{
		int pos = line.find(":");
		string postCreator = line.substr(0, pos);
		string sample = line.substr(pos + 1);
		int pos_2 = sample.find(":");
		string postTopic = sample.substr(0, pos_2);
		string postMessage = sample.substr(pos_2 + 1);
		Post postData;
		postData.creator = postCreator;
		postData.topicName = postTopic;
		postData.message = postMessage;
		add(postData);
	}
	postFile.close();
}

void PostList::savePosts()
{
	ofstream postFile("Post.txt");
	for (int i = 0; i < size; i++)
	{
		Post postData = get(i);
		if (postData.message != "")
		{
			postFile << postData.creator << ":" << postData.topicName << ":" << postData.message << endl;
		}
	}
	postFile.close();
	return;
}