#include "List.h"
#include <iostream>
using namespace std;

//Constructor
List::List() { firstNode = NULL; size = 0; };

List::~List() {
	Node* current = firstNode;
	while (current != NULL) {
		Node* next = current->next;
		delete current;
		current = next;
	}
};

//Functions
void List::printAccounts() {
	if (!isEmpty()) {
		cout << "List is empty";
	}
	else{
		Node* printer = firstNode;
		int i = 1;
		while (true) {
			if (printer->next != NULL) {
				cout << "username: " << printer->item.getUsername() << " Password: " << printer->item.getPassword() << endl;
				printer = printer->next;
				i++;
			}
			else {
				cout << "username: " << printer->item.getUsername() << " Password: " << printer->item.getPassword() << endl;
				break;
			}
		}
		cout << "\n";
	}
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
		Node* hihi = firstNode;
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

void List::saveTXT(List accountlist) {
	ofstream MyFile("accounts.txt");

	Node* adder = firstNode;
	for (int i = 0; i < size; i++) {
		MyFile << adder->item.getUsername() << "\n";
		MyFile << adder->item.getPassword() << "\n";
		adder = adder->next;
	}
	MyFile.close();
}

bool List::dataValidation(Account data) {
	Node* checker = firstNode;
	for (int x = 0; x < size; x++) {
		if (data.getUsername() == checker->item.getUsername()) {
			if (data.getPassword() == checker->item.getPassword()) {
				return 1;//Returns true
			}
		}
		checker = checker->next;
	}
	return 0;//Return false
}

bool List::checkDuplicates(string username) {
	Node* checker = firstNode;
	for (int x = 0; x < size; x++) {
		if (username == checker->item.getUsername()) {
			return 1;//Returns true
		}
		checker = checker->next;
	}
	return 0;//Return false
}


