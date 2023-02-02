#include "LinkList.h"
#include <iostream>
#include <String>

using namespace std;


List::List() { size = 0; }

int List::getLength() { return size; }

string List::print()
{
    string x;
    string index;
    for (int i = 0;i < getLength();i++)
    {
        index = to_string(i);
        x += "Index: " + index + "\t Name: " + get(i).getName() + "\t TelNo : " + get(i).getTelNo() + "\n";
    }
    return x;
}


bool List::add(ItemType item)
{
    bool success = size < MAX_SIZE;
    if (success)
    {
        items[size] = item;  // add to the end of the list
        size++;              // increase the size by 1
    }
    return success;
}

void List::remove(int index)
{
    bool success = (index >= 0) && (index < size);
    if (success)
    {   // delete item by shifting all items at positions >
        // index toward the beginning of the list
        // (no shift if index == size)
        for (int pos = index; pos < size; pos++)
            items[pos] = items[pos + 1];
        size--;  // decrease the size by 1
    }
}

ItemType List::get(int index)
{
    bool success = (index >= 0) && (index < size);
    if (success)
        return items[index];
    else
        return Person("0", "0");   // invalid index
}

string List::search(string no)
{
    string x;
    string index;
    for (int i = 0;i < getLength(); i++)
    {
        if (get(i).getTelNo() == no)
        {
            index = to_string(i);
            x += "Index: " + index + "\t Name: " + get(i).getName() + "\t TelNo : " + get(i).getTelNo() + "\n";
            return x;
            break;
        }
    }
    if (x.empty()) {
        x += "could not find the given phone number\n";
        return x;
    }
}
