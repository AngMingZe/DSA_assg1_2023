#pragma once

/* a) Identify and list the operations required for the application
* List the phone numbers
* Add a new contact
* Remove a contact
* Search for a phone number
*/

/* b) Specify the operations of the List ADT
* print()
* add(item: ItemType): boolean
* add(index: int,item: ItemType): boolean
* remove(index: int): void
* get(index: int): ItemType
*/

const int MAX_SIZE = 100;
typedef topic ItemType;

class List {
private:
	ItemType items[MAX_SIZE];
	int size;
public:
	List();
	string print();
	int getLength();
	bool add(ItemType item);
	void remove(int pos);
	ItemType get(int pos);
	string search(string no);
};


