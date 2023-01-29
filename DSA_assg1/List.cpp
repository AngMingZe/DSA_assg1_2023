#include "List.h"
#include <iostream>
using namespace std;

//Constructor
List::List() { firstNode = NULL; size = 0; };

List::~List() {
	Node* current = firstNode;
	while (current != 0) {
		Node* next = current->next;
		delete current;
		current = next;
	}
	firstNode = 0;
};

//Functions
void List::print() {
	Node* printer = new Node;
	printer = firstNode;
	int i = 1;
	while (true) {
		if (printer->next != NULL) {
			cout << i << " " << printer->item << endl;
			printer = printer->next;
			i++;
		}
		else {
			cout << i << " " << printer->item << endl;
			break;
		}
	}
	cout << "\n";
}

bool List::isEmpty() {
	if (size > 0) { return 1; }
	else { return 0; }
	//0 is false, non-0 is true
}

int List::getLength() {
	return size;
}

bool List::add(ItemType itm) {
	//create new node
	Node* temp = new Node;
	temp->item = itm;
	temp->next = NULL;

	//If else loop to add
	if (size == 0) {
		firstNode = temp;//Setting pointer of firstNode to address of temp
		size++;
	}
	else {
		Node* hihi = new Node;
		hihi = firstNode;
		for (int i = 0; i < size; i++) {
			if (hihi->next == NULL) {
				hihi->next = temp;
				break;
			}
			else {
				hihi = hihi->next;
			}
		}
		size++;
	}
	return 1;
}

bool List::add(int index, ItemType itm) {
	if (index > size) {
		return 0;//return false as index is larger than list size, cannot be linked 
	}
	//create new node
	Node* temp = new Node;
	temp->item = itm;
	temp->next = NULL;
	Node* infront = new Node; //Node + 1 of new Node
	Node* behind = new Node; //Node - 1 of new Node
	if (size == 0) {
		firstNode = temp;//Setting pointer of firstNode to address of temp
		size++;
	}
	else if (index == 1) {
		infront = firstNode;//Store first node somewhere
		firstNode = temp;//Make firstnode the new item
		temp->next = infront;//Assign pointer of new item to first node
	}
	else {
		behind = firstNode;//Store first node
		for (int i = 1; i < size; i++) {
			if (index - 1 == i) {
				infront = behind->next;
				behind->next = temp;
				temp->next = infront;
				break;
			}
			else {
				behind = behind->next; //Goes to next node
			}
		}
		size++;
	}

	return 1;
}

void List::remove(int index) {
	Node* infront = new Node; //Node + 1 of removed node
	Node* behind = new Node; //Node - 1 of removed node
	if (index == 1) {
		firstNode = firstNode->next;
	}
	else {
		behind = firstNode;//Store first node
		for (int i = 2; i < size; i++) {
			if (index == i) {
				infront = behind->next;
				infront = infront->next;
				behind->next = infront;
				break;
			}
			else {
				behind = behind->next; //Goes to next node
			}
		}
		size--;
	}
}

ItemType List::get(int index) {
	Node* store = firstNode; //Store first node
	for (int i = 1; i <= size; i++) {
		if (index == i) {
			return store->item;
		}
		store = store->next;
	}
	return "Not found";
}


