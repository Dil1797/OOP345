#pragma once
#ifndef HOSPITALLINKEDLIST_H
#define HOSPITALLINKEDLIST_H

#include "Patient.h"

class HospitalLinkedList {
private:
    struct Node {
        Patient* patient;
        Node* next;

        Node(Patient* p) : patient(p), next(nullptr) {}
    };

    Node* head;
    Node* tail;

    // Function to determine the severity order
    bool severityHigherOrEqual(const string& severity1, const string& severity2) {
        if (severity1 == "high") return true;
        if (severity1 == "moderate" && severity2 != "high") return true;
        return false;
    }

public:
    HospitalLinkedList() : head(nullptr), tail(nullptr) {}

    ~HospitalLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp->patient; // Freeing allocated memory
            delete temp;
        }
    }

    void addPatient(int id, const string& name, const string& severity) {
        Patient* newPatient = new Patient(id, name, severity);
        Node* newNode = new Node(newPatient);

        // If the list is empty
        if (!head) {
            head = tail = newNode;
        }
        else {
            // Find the correct position based on severity
            Node* current = head;
            Node* previous = nullptr;

            while (current && severityHigherOrEqual(current->patient->getSeverity(), severity)) {
                previous = current;
                current = current->next;
            }

            // Insert at the beginning
            if (!previous) {
                newNode->next = head;
                head = newNode;
            }
            else { // Insert in the middle/end
                newNode->next = current;
                previous->next = newNode;

                if (current == nullptr) {
                    tail = newNode; // Update tail if it's end insertion
                }
            }
        }
        cout << "Patient added: ID = " << id << ", Name = " << name << ", Severity = " << severity << endl;
    }

    void removePatient(int id) {
        Node* current = head;
        Node* previous = nullptr;

        while (current && current->patient->getPatientID() != id) {
            previous = current;
            current = current->next;
        }

        if (!current) {
            cout << "Patient with ID " << id << " does not exist." << endl;
            return;
        }

        if (previous) {
            previous->next = current->next; // Bypass the current node
        }
        else {
            head = current->next; // Move head if it's the first node
        }

        if (current == tail) {
            tail = previous; // Update tail if it was the last node
        }

        delete current->patient; // Free memory of the patient
        delete current; // Free memory of the node
        cout << "Patient with ID " << id << " removed." << endl;
    }

    void displayPatients() {
        if (!head) {
            cout << "No patients in the list." << endl;
            return;
        }

        cout << "Patients in the list (prioritized by severity):" << endl;
        Node* current = head;
        while (current) {
            cout << "ID: " << current->patient->getPatientID()
                << ", Name: " << current->patient->getName()
                << ", Severity: " << current->patient->getSeverity() << endl;
            current = current->next;
        }
    }

    Patient* searchPatient(int id) {
        Node* current = head;

        while (current) {
            if (current->patient->getPatientID() == id) {
                return current->patient; // Return the found patient
            }
            current = current->next;
        }
        cout << "Patient with ID " << id << " not found." << endl;
        return nullptr; // Return nullptr if not found
    }
};

#endif // HOSPITALLINKEDLIST_H
