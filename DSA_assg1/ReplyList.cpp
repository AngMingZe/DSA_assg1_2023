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

void ReplyList::remove(int index)
{
	if (index >= 0 && index < size)
	{
		Node* temp = firstNode;
		int indexCount = 0;
		if (index == 0)
		{
			firstNode = firstNode->next;
			delete temp;
		}
		else
		{
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

void ReplyList::remove(string postName) {
	Node* prev = firstNode;
	while (prev->item.postName == postName) {
		firstNode = firstNode->next;
		delete prev;
		Node* prev = firstNode;

	}
	Node* temp = prev->next;
	while (temp != NULL)
	{
		if (temp->item.postName == postName) {
			prev->next = temp->next;
			delete temp;
			Node* temp = prev->next;
		}
		else {
			temp = temp->next;
			prev = prev->next;
		}
	}
	size--;
}

int ReplyList::getIndex(string message)
{
	Node* temp = firstNode;
	int index = 0;
	while (temp != NULL)
	{
		if (temp->item.message == message) {
			return index;
			break;
		}
		temp = temp->next;
		index++;
	}
}

ReplyItem ReplyList::indexGet(int index)
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
void ReplyList::stringGet(string message, string newMessage)
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
void ReplyList::postEdited(string postName, string newPostName)
{
	Node* temp = firstNode;
	while (temp != NULL)
	{
		if (temp->item.postName == postName) {
			temp->item.postName = newPostName;
		}
		temp = temp->next;
	}
	// parsh in selectedTopic.message
	// create temp go through all nodes
	// if topicName == selectedTopic.message
	// change post
}

void ReplyList::getPrint(string postName) {
	Node* temp = firstNode;
	while (temp != NULL)
	{
		if (temp->item.postName == postName) {
			cout << temp->item.message << endl;
		}
		temp = temp->next;
	}
}

ReplyList ReplyList::ownReplies(string username) {

	ReplyList replyList;
	Node* temp = firstNode;
	int index = 0;
	while (temp != NULL)
	{
		if (temp->item.creator == username) {
			cout << index << "." << temp->item.message << endl;
			index++;
			replyList.add(temp->item);
		}
		temp = temp->next;
	}
	return replyList;
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
	while (temp != NULL)
	{
		cout << temp->item.message << endl;
		temp = temp->next;
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
		Reply replyData = indexGet(i);
		if (replyData.message != "")
		{
			replyFile << replyData.creator << ":" << replyData.postName << ":" << replyData.message << endl;
		}
	}
	replyFile.close();
	return;
}