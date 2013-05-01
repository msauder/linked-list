// LinkedList.cpp
// LinkedList class implementation
// Written by Matthew Sauder

#include "LinkedList.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Default constructor
template <class T>
LinkedList<T>::LinkedList() {
    head = NULL;
}

// Add item to end of list
template <class T>
void LinkedList<T>::append(T d) {
    NODE *q, *r;
    // If list is empty simply add NODE at head
    if (head == NULL) {
        head = new NODE;
        head->data = d;
        head->link = NULL;
    }
    // If not, find the end of list and add NODE, update pointers as required
    else {
        q = head;
        while (q->link != NULL) {
            q = q->link;
        }
        r = new NODE;
        r->data = d;
        r->link = NULL;
        q->link = r;
    }
}

// Add item to beginning of list
template <class T>
void LinkedList<T>::addAtStart(T d) {
    NODE *q = new NODE;
    q->data = d;
    q->link = head;
    head = q; // Let q be the new head of list
}

// Add item somewhere in list
template <class T>
void LinkedList<T>::insert(int position, T d) {
    NODE *q, *r;
    q = head;
    for (int i = 1; i < position; i++) {
        q = q->link;
        if (q == NULL) {
            cout << "\nNode " << position << " does not exist." << endl;
            return;
        }
    }
    r = new NODE;
    r->data = d;
    r->link = q->link;
    q->link = r;
}

// Delete first occurence of an item
template <class T>
void LinkedList<T>::del(T d) {
    NODE *q, *r;
    q = head;
    // If head contains item to remove then delete create new head and delete old head
    if (q->data == d) {
        head = q->link;
        delete q;
        return;
    }
    // If not, search for item and delete, bridging nodes using r
    r = q;
    while (q != NULL) {
        if (q->data == d) {
            r->link = q->link;
            delete q;
            return;
        }
        r = q;
        q = q->link;
    }
    cout << "\nItem " << d << " does not exist." << endl;
}

// Return position of first occurence of an item
template <class T>
int LinkedList<T>::find(T d) {
    NODE *q = head;
    int position = 0;
    while (q != NULL) {
        if (q->data == d) {
            return position;
        }
        q = q->link;
        position++;
    }
    cout << "\nItem " << d << " does not exist." << endl;
}

// Display contents of LinkedList
template <class T>
void LinkedList<T>::display() {
    NODE *q = head;
    int nodeNumber = 0;
    cout << setw(6) << "Node #" << " " << setw(6) << "Data" << endl;
    while (q != NULL) {
        cout << setw(6) << nodeNumber << " " << setprecision(3) << setw(6) << q->data << endl;
        q = q->link;
        nodeNumber++;
    }
    cout << endl;
}

// Clear all items in LinkedList
template <class T>
void LinkedList<T>::clear() {
    NODE *q = head;
    while (q != NULL) {
        head = q->link;
        delete q;
        q->link = NULL;
        q = head;
    }
}

template <class T>
LinkedList<T>::~LinkedList() {
    (*this).clear();
}
