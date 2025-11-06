#pragma once
#ifndef STACK_H
#define STACK_H

struct Node {
    int data;
    Node* next;

    Node(int value);
};

class LinkedListStack {
private:
    Node* head;
    int size;

public:
    LinkedListStack(); // Default constructor
    void insert(int value); // Function to push data onto the stack
    void deleteNode(); // Function to pop data from the stack
    void display(); // Function to display the stack
    int getSize(); // Function to get the size of the stack
    ~LinkedListStack(); // Destructor
};

#endif // STACK_H
