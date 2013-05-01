// LinkedList.h
// LinkedList class definition
// Written by Matthew Sauder

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <class T>
class LinkedList {
    private:
     // Only data member is a pointer to first node in the list
     struct NODE {
         T data;
         NODE *link;
     } *head;

    public:
     // Default constructor
     LinkedList();

     // Add item to end of list
     void append(T d);

     // Add item at beginning of list
     void addAtStart(T d);

     // Add item somewhere in list
     void insert(int position, T d);

     // Delete first occurence of an item
     void del(T d);

     // Return position of first occurence of an item
     int find(T d);

     // Display contents of LinkedList
     void display();

     // Clear all items in LinkedList
     void clear();

     // Default destructor
     ~LinkedList();
};

#endif

