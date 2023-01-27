#include "List.h"

// constructor
List::List()
{
	firstNode = NULL;
	size = 0;
}

// destructor
List::~List() { }

// add an item to the back of the list (append)
bool List::add(ItemType item)
{
	// create a new node to store the item
	Node* newNode = new Node;
	newNode->item = item;
	newNode->next = NULL;

	// add new node to the list
	if (isEmpty())	// list is empty
		firstNode = newNode;
	else			// list is not empty
	{
		Node* current = firstNode;
		Node* previous = firstNode;
		while (current != NULL) 		// move to last node
		{
			previous = current;
			current = current->next;
		}
		previous->next = newNode;		// make last node point to new node
	}
	size++;			// increase the size by 1

	return true;  	// no size constraint
}


// add an item at a specified position in the list (insert)
bool List::add(int index, ItemType item)
{
	bool success = (index >= 0) && (index <= size);
	if (success)
	{
		// create a new node to store the item
		Node* newNode = new Node;
		newNode->item = item;
		newNode->next = NULL;

		// add new node to the list at the specified position
		if (index == 0) // inserting in front
		{
			newNode->next = firstNode;
			firstNode = newNode;
		}
		else
		{
			Node* temp = firstNode;
			// move to the node at the position before the index
			for (int i = 0; i < index - 1; i++)
				temp = temp->next;
			// make new node point to node pointed to by temp
			newNode->next = temp->next;
			// make temp point to the new node		
			temp->next = newNode;
		}
		size++; // increase the size by 1
	}
	return success;
}


// remove an item at a specified position in the list
void List::remove(int index)
{
	bool success = (index >= 0) && (index < size);
	if (success)
	{
		if (index == 0) // remove front node
			firstNode = firstNode->next;
		else		    // remove the node at the specified position
		{
			Node* current = firstNode;
			Node* previous = firstNode;
			// move to node at the specified position
			for (int i = 0; i < index; i++)
			{
				previous = current;
				current = current->next;
			}
			previous->next = current->next;
			delete current;		// de-allocate the node
			current = NULL; 	// set current to NULL
		}
		size--;	// decrease the size by 1
	}
}

// get (retrieve) an item at a specified position in the list
ItemType List::get(int index)
{
	ItemType item = -1;	// default (not successiful)
	bool success = index >= 0 && index < size;
	if (success)
	{
		Node* temp = firstNode;

		for (int i = 0; i < index; i++)  // move to specified node
			temp = temp->next;

		item = temp->item;
	}

	return item;
}

bool List::isEmpty() { return (size == 0); }

int List::getLength() { return size; }
