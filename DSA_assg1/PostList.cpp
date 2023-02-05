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

bool PostList::add(int index, PostItem item) //firstnode is index 0
{
	if (index >= 0 && index < size)
	{
		Node* newNode = new Node;
		newNode->item = item;
		newNode->next = NULL;
		if (index == 0 && size == 0)
		{
			firstNode = newNode;
		}
		else if (index == 0 && size > 0)
		{
			newNode->next = firstNode->next;
			firstNode->next = newNode;
		}
		else
		{
			int indexCount = 0;
			Node* temp = firstNode;
			while (indexCount != index - 1)
			{
				temp = temp->next;
				indexCount++;
			}
			newNode->next = temp->next;
			temp->next = newNode;
		}
		size++;
		return true;
	}
	else {
		return false;
	}
}

void PostList::remove(int index)
{
	if (index >= 0 && index < size)
	{
		int indexCount = 0;
		if (index == 0)
		{
			firstNode = firstNode->next;
		}
		else
		{
			Node* temp = firstNode;
			while (indexCount != index - 1)
			{
				temp = temp->next;
				indexCount++;
			}
			temp->next = temp->next->next;
			temp = temp->next;
			delete temp;
		}
		size--;
	}
	else {
		cout << "No item in index" << endl;
	}
}

int PostList::getIndex(string message)
{
	Node* temp = firstNode;
	int index = -1;
	while (temp != NULL)
	{
		if (temp->item.message == message) {

		}
		temp = temp->next;
		index++;
	}
	return index;
}

PostItem PostList::indexGet(int index)
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

PostItem PostList::stringGet(string message)
{
	Node* temp = firstNode;
	Post tempItem;
	while (true)
	{
		while (temp != NULL)
		{
			if (temp->item.message == message) {
				Post tempItem = temp->item;
			}
			temp = temp->next;
		}
		break;
	}
	return tempItem;
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

void PostList::print()
{
	Node* temp = firstNode;
	while (temp != NULL)
	{
		cout << temp->item.message << endl;
		temp = temp->next;
	}
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
		Post postData = indexGet(i);
		if (postData.message != "")
		{
			postFile << postData.creator << ":" << postData.topicName << ":" << postData.message << endl;
		}
	}
	postFile.close();
	return;
}

void PostList::pinPost(Post item) {
	//Sets post selected as pinned, making it always appear at the top of the post list
	cout << "nothing";
}