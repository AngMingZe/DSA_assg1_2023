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
		}
		size--;
	}
	else {
		cout << "No item in index" << endl;
	}
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
	cout << temp->item.message << endl;
	while (temp->next != NULL)
	{
		temp = temp->next;
		cout << temp->item.message << endl;
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
		Post postData = get(i);
		if (postData.message != "")
		{
			postFile << postData.creator << ":" << postData.topicName << ":" << postData.message << endl;
		}
	}
	postFile.close();
	return;
}