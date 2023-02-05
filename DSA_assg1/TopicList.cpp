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


bool TopicList::add(TopicItem item)
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

bool TopicList::add(int index, TopicItem item) //firstnode is index 0
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
			temp = temp->next;
			delete temp;
		}
		size--;
	}
	else {
		cout << "No item in index" << endl;
	}
}

int TopicList::getIndex(string message)
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

TopicItem TopicList::indexGet(int index)
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

TopicItem TopicList::stringGet(string message)
{
	return TopicItem();
}

TopicItem TopicList::getItem(string message)
{
	Node* temp = firstNode;
	Topic tempItem;
	while (true)
	{
		while (temp != NULL)
		{
			if (temp->item.message == message) {
				Topic tempItem = temp->item;
			}
			temp = temp->next;
		}
		break;
	}
	return tempItem;
}

bool TopicList::search(string input) {
	Node* temp = firstNode;
	Topic tempItem;
	while (true)
	{
		while (temp != NULL)
		{
			if (temp->item.message == input) {
				return true;
			}
			temp = temp->next;
		}
		break;
	}
	return false;
}

TopicList TopicList::ownTopics(string username) {
	TopicList topicList;
	Node* temp = firstNode;
	int index = 0;
	while (temp != NULL)
	{
		if (temp->item.creator == username) {
			cout << index << "." << temp->item.message << endl;
			index++;
			topicList.add(temp->item);
		}
		temp = temp->next;
	}
	return topicList;
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

void TopicList::print()
{
	Node* temp = firstNode;
	int index = 0;
	while (temp != NULL)
	{
		cout << index << "." << temp->item.message << endl;
		index++;
		temp = temp->next;
	}
}

void TopicList::reverse() {
	Node* current = firstNode;
	Node* prev = NULL;
	Node* next = NULL;
	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	firstNode = prev;
}

void TopicList::printByLatest() {
	reverse();
	print();
}

void TopicList::loadTopics() {
	ifstream topicFile("Topics.txt");
	string line;
	while (getline(topicFile, line))
	{
		int pos = line.find(":");
		string topicCreator = line.substr(0, pos);
		string topicMessage = line.substr(pos + 1);
		Topic topicData;
		topicData.creator = topicCreator;
		topicData.message = topicMessage;
		add(topicData);
	}
	topicFile.close();
}

void TopicList::saveTopics()
{
	ofstream topicFile("Topics.txt");
	for (int i = 0; i < size; i++)
	{
		Topic topicData = indexGet(i);
		if (topicData.message != "")
		{
			topicFile << topicData.creator << ":" << topicData.message << endl;
		}
	}
	topicFile.close();
	return;
}

void TopicList::createTopic(Topic topic)
{
	ofstream topicFile("Topics.txt");
	if (topic.message != "")
	{
		topicFile << topic.creator << ":" << topic.message << endl;
	}
	topicFile.close();
	return;
}


