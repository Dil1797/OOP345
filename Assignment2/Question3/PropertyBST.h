#pragma once
#ifndef PROPERTYBST_H
#define PROPERTYBST_H

#include "Property.h"

class PropertyBST {
private:
    struct Node {
        Property* property;
        Node* left;
        Node* right;

        Node(Property* prop) : property(prop), left(nullptr), right(nullptr) {}
    };

    Node* root;

    // Helper function to add a property recursively
    Node* addProperty(Node* node, Property* property) {
        if (!node) {
            return new Node(property);
        }

        if (property->getPropertyID() < node->property->getPropertyID()) {
            node->left = addProperty(node->left, property);
        }
        else if (property->getPropertyID() > node->property->getPropertyID()) {
            node->right = addProperty(node->right, property);
        }
        return node; // Return unchanged node pointer
    }

    // Helper function to find a property recursively
    Node* findProperty(Node* node, int propertyID) {
        if (node == nullptr || node->property->getPropertyID() == propertyID) {
            return node;
        }

        if (propertyID < node->property->getPropertyID()) {
            return findProperty(node->left, propertyID);
        }
        else {
            return findProperty(node->right, propertyID);
        }
    }

    // Helper function to delete a property recursively
    Node* deleteProperty(Node* node, int propertyID) {
        if (node == nullptr) return node;

        // Recursively find the node to delete
        if (propertyID < node->property->getPropertyID()) {
            node->left = deleteProperty(node->left, propertyID);
        }
        else if (propertyID > node->property->getPropertyID()) {
            node->right = deleteProperty(node->right, propertyID);
        }
        else {
            // Node with only one child or no child
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node->property;
                delete node;
                return temp;
            }
            else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node->property;
                delete node;
                return temp;
            }

            // Node with two children: Get the inorder successor (smallest in the right subtree)
            Node* temp = node->right;
            while (temp && temp->left) {
                temp = temp->left;
            }

            // Replace the value of this node with the inorder successor's value
            node->property->setPropertyID(temp->property->getPropertyID());
            node->property->setAddress(temp->property->getAddress());
            node->property->setPrice(temp->property->getPrice());
            node->property->setType(temp->property->getType());

            // Delete the inorder successor
            node->right = deleteProperty(node->right, temp->property->getPropertyID());
        }
        return node;
    }

    // Helper function to display properties in order
    void displayPropertiesInOrder(Node* node) {
        if (node) {
            displayPropertiesInOrder(node->left);
            cout << "Property ID: " << node->property->getPropertyID()
                << ", Address: " << node->property->getAddress()
                << ", Price: $" << node->property->getPrice()
                << ", Type: " << node->property->getType() << endl;
            displayPropertiesInOrder(node->right);
        }
    }

public:
    PropertyBST() : root(nullptr) {}

    // Public method to add a property
    void addProperty(int propertyID, const string& address, double price, const string& type) {
        Property* newProperty = new Property(propertyID, address, price, type);
        root = addProperty(root, newProperty);
    }

    // Public method to find a property
    Property* findProperty(int propertyID) {
        Node* result = findProperty(root, propertyID);
        return result ? result->property : nullptr; // Return found property or nullptr
    }

    // Public method to delete a property
    void deleteProperty(int propertyID) {
        root = deleteProperty(root, propertyID);
    }

    // Public method to display properties in order
    void displayPropertiesInOrder() {
        displayPropertiesInOrder(root);
    }
};

#endif // PROPERTYBST_H
