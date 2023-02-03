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
		while (true) {
			if (printer->next != NULL) {
				cout << "username: " << printer->item.getUsername() << " Password: " << printer->item.getPassword() << endl;
				printer = printer->next;
			}
			else {
				cout << "username: " << printer->item.getUsername() << " Password: " << printer->item.getPassword() << endl;
				break;
			}
		}
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

bool List::add(Account itm) {
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

void List::saveTXT(Account att) {
	ofstream MyFile;
	MyFile.open("accounts.txt",std::ios_base::app);

	MyFile << att.getUsername() << "\n";
	MyFile << att.getPassword() << "\n";

	MyFile.close();
}

bool List::dataValidation(string name,string pw) {
	Node* checker = firstNode;
	for (int x = 0; x < size; x++) {
		if (name == checker->item.getUsername()) {
			if (pw == checker->item.getPassword()) {
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


