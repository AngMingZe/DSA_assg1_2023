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


bool PostList::add(ItemType item)
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

bool PostList::add(int index, ItemType item) //firstnode is index 0
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

ItemType PostList::get(int index)
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
	cout << temp->item.getMessage() << endl;
	while (temp->next != NULL)
	{
		temp = temp->next;
		cout << temp->item.getMessage() << endl;
	}
}
