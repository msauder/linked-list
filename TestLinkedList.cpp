// TestLinkedList.cpp
// Test LinkedList class definition and implementation files
// Written by Matthew Sauder

#include "LinkedList.h"
#include <iostream>
#include <cmath>
using namespace std;

int main () {
    LinkedList<char> charList;
    LinkedList<int> intList;
    LinkedList<float> floatList;
    int temp, numOfChar, numOfInt, numOfFloat;
    char dummy;
    float tempF;

    // Prompt user for size of charList
    cout << "How many characters in your list? ";
    cin >> numOfChar;
    
    // Prompt user for charList entries
    cout << "Enter characters to be in your list: ";
    for (int i = 0; i < numOfChar; i++) {
    cin >> dummy;
    charList.append(dummy);
    }
    
    // Display contents of charList to ensure append(char) works
    cout << "charList contains: " << endl;
    charList.display();
    
    // Test addAtStart and insert functions
    charList.addAtStart('X');
    charList.insert(3, 'X');
    cout << "modified charList contains" << endl;
    charList.display();

    charList.clear();

    // Prompt user for size of intList
    cout << "How many integers in your list? ";
    cin >> numOfInt;
    
    // Prompt user for intList entries
    cout << "Enter integers to be in your list: ";
    for (int i = 0; i < numOfInt; i++) {
        cin >> temp;
        intList.append(temp);
    }
   
    // Display contents of intList to ensure append(int) works
    cout << "intList contains: " << endl;
    intList.display();
    
    // Test delete function by removing user selected entry
    cout << "Enter integer to be deleted from list: ";
    cin >> temp;
    intList.del(temp);
    cout << "modified intList contains: " << endl;
    intList.display();

    intList.clear();

    // Prompt user for size of floatList
    cout << "How many floats in your list? ";
    cin >> numOfFloat;

    // Prompt user for floatList entries
    cout << "Enter floats to be in your list: ";
    for (int i = 0; i < numOfFloat; i++) {
        cin >> tempF;
        floatList.append(tempF);
    }

    // Display contents of floatList to ensure append(flaot) works
    cout << "floatList conatins: " << endl;
    floatList.display();

    // Test find function by finding position of user selected entry
    cout << "Enter float to determine it's position in your list: ";
    cin >> tempF;
    cout << "Position of " << tempF << " is " << floatList.find(tempF) << endl;

    floatList.clear();

    return 0;

}
