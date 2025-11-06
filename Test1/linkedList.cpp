#include <iostream>
#include "linkedList.h"

using namespace std;

Node::Node(int value) : data(value), next(nullptr) {}

LinkedListStack::LinkedListStack() : head(nullptr), size(0) {}

void LinkedListStack::insert(int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = newNode; // If list is empty, new node is the head
    }
    else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next; // Traverse to the end of the list
        }
        temp->next = newNode; // Current node's next pointer points to new node
    }
    size++;
}

void LinkedListStack::deleteNode() {
    if (!head) {
        cout << "Stack is empty. Cannot delete." << endl;
        return;
    }
    if (head->next == nullptr) {
        delete head; // Only one element
        head = nullptr; // Update head to null
    }
    else {
        Node* current = head;
        Node* previous = nullptr;
        while (current->next) {
            previous = current; // Keep track of the previous node
            current = current->next; // Move to the next node
        }
        delete current; // Delete the last node
        previous->next = nullptr; // Set previous node's next to null
    }
    size--;
}

//display
void LinkedListStack::display() {
    if (!head) {
        cout << "Stack is empty." << endl;
        return;
    }
    Node* temp = head;
    cout << "Stack elements: ";
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

//size
int LinkedListStack::getSize() {
    return size;
}

LinkedListStack::~LinkedListStack() {
    while (head) {
        deleteNode(); // Delete all nodes
    }
}