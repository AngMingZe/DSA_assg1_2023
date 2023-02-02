#include "TopicList.h"
#include<string>
#include<iostream>
using namespace std;

TopicList::TopicList()
{
	firstNode = NULL;
	size = 0;
}

TopicList::~TopicList()
{
	while (firstNode != NULL) {
		Node* temp = firstNode;
		firstNode = firstNode->next;
		delete temp;
	}
	firstNode = NULL;
}


bool TopicList::add(ItemType1 item)
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

bool TopicList::add(int index, ItemType1 item) //firstnode is index 0
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

void TopicList::remove(int index)
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

ItemType1 TopicList::get(int index)
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

bool TopicList::isEmpty()
{
	if (size > 0) {
		return false;
	}
	else {
		return true;
	}
}

int TopicList::getLength()
{
	return size;
}

void TopicList::PrintTopics(string fileName) {
	/*ifstream TopicFile;
	TopicFile.open("Topics.txt", ios::out);*/
	ifstream file(fileName);

	// Check if the file was successfully opened
	if (!file.is_open()) {
		cout << "Failed to open file " << fileName << endl;
		return;
	}

	// Read the contents of the file line by line
	string line;
	while (getline(file, line)) {
		cout << line << endl;
	}

	// Close the file
	file.close();
}


