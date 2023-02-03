#include "ReplyList.h"
#include<string>
#include<iostream>
using namespace std;

ReplyList::ReplyList()
{
	firstNode = NULL;
	size = 0;
}

ReplyList::~ReplyList()
{
	while (firstNode != NULL) {
		Node* temp = firstNode;
		firstNode = firstNode->next;
		delete temp;
	}
	firstNode = NULL;
}


bool ReplyList::add(ReplyItem item)
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

bool ReplyList::add(int index, ReplyItem item) //firstnode is index 0
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

void ReplyList::remove(int index)
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

ReplyItem ReplyList::get(int index)
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

bool ReplyList::isEmpty()
{
	if (size > 0) {
		return false;
	}
	else {
		return true;
	}
}

int ReplyList::getLength()
{
	return size;
}

void ReplyList::print()
{
	Node* temp = firstNode;
	cout << temp->item.message << endl;
	while (temp->next != NULL)
	{
		temp = temp->next;
		cout << temp->item.message << endl;
	}
}

void ReplyList::loadReplies()
{
	ifstream replyFile("Reply.txt");
	string line;
	while (getline(replyFile, line))
	{
		int pos = line.find(":");
		string replyCreator = line.substr(0, pos);
		string sample = line.substr(pos + 1);
		int pos_2 = sample.find(":");
		string replyPost = sample.substr(0, pos_2);
		string replyMessage = sample.substr(pos_2 + 1);
		Reply replyData;
		replyData.creator = replyCreator;
		replyData.postName = replyPost;
		replyData.message = replyMessage;
		add(replyData);
	}
	replyFile.close();
}

void ReplyList::saveReplies()
{
	ofstream replyFile("Reply.txt");
	for (int i = 0; i < size; i++)
	{
		Reply replyData = get(i);
		if (replyData.message != "")
		{
			replyFile << replyData.creator << ":" << replyData.postName << ":" << replyData.message << endl;
		}
	}
	replyFile.close();
	return;
}