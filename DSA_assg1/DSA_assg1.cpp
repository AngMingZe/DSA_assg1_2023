#include <iostream>
#include <fstream>
#include "pages.h"
using namespace std;

int main()
{
    TestMenu();

    // Create and open a text file
    ofstream MyFile("filename.txt");

    // Write to the file
    MyFile << "Files can be tricky, but it is fun enough!";
    MyFile << "\nFiles are not fun";

    // Close the file
    MyFile.close();

}
