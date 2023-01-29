#include <iostream>
#include <fstream>
#include <string>
#include "pages.h"
#include "List.h"
using namespace std;

int main()
{
    //TestMenu();

    // Create and open a text file
    ofstream MyFile("filename.txt");
    MyFile << "1";
    MyFile << "\n2";
    MyFile << "\n3";
    MyFile.close();

    string myText;
    List storage;

    // Read from the text file
    ifstream MyReadFile("filename.txt");

    // Use a while loop together with the getline() function to read the file line by line
    while (getline(MyReadFile, myText)) {
        // Output the text from the file
        storage.add(myText);
    }
    MyReadFile.close();

    cout << storage.getLength() << endl;
    storage.print();
}
