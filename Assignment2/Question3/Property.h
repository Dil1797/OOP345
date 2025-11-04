#pragma once
#ifndef PROPERTY_H
#define PROPERTY_H

#include <iostream>
#include <string>

using namespace std;

class Property {
public:
    int propertyID;
    string address;
    double price;
    string type;

    // Constructor
    Property(int id, const string& addr, double prc, const string& pType)
        : propertyID(id), address(addr), price(prc), type(pType) {}

    // Getter methods
    int getPropertyID() const { return propertyID; }
    string getAddress() const { return address; }
    double getPrice() const { return price; }
    string getType() const { return type; }

    // Setter methods
    void setPropertyID(int id) { propertyID = id; }
    void setAddress(const string& addr) { address = addr; }
    void setPrice(double prc) { price = prc; }
    void setType(const string& pType) { type = pType; }
};

#endif // PROPERTY_H
