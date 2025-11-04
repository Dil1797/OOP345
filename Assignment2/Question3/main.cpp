#include <iostream>
#include "PropertyBST.h"

using namespace std;

int main() {
    PropertyBST propertyList;
    int choice;

    cout << "Welcome to the Real Estate Property Listings Management System!" << endl;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Add Property" << endl;
        cout << "2. Find Property" << endl;
        cout << "3. Delete Property" << endl;
        cout << "4. Display Properties" << endl;
        cout << "5. Exit" << endl;
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int propertyID;
            string address;
            double price;
            string type;

            cout << "Enter Property ID: ";
            cin >> propertyID;
            cout << "Enter Address: ";
            cin.ignore(); // Clear the input buffer
            getline(cin, address);
            cout << "Enter Price: ";
            cin >> price;
            cout << "Enter Type (house/apartment/commercial): ";
            cin.ignore(); // Clear the input buffer
            getline(cin, type);

            propertyList.addProperty(propertyID, address, price, type);
            break;
        }
        case 2: {
            int propertyID;
            cout << "Enter Property ID to search: ";
            cin >> propertyID;
            Property* property = propertyList.findProperty(propertyID);
            if (property) {
                cout << "Property Found: ID: " << property->getPropertyID()
                    << ", Address: " << property->getAddress()
                    << ", Price: $" << property->getPrice()
                    << ", Type: " << property->getType() << endl;
            }
            else {
                cout << "Property with ID " << propertyID << " not found." << endl;
            }
            break;
        }
        case 3: {
            int propertyID;
            cout << "Enter Property ID to delete: ";
            cin >> propertyID;
            propertyList.deleteProperty(propertyID);
            break;
        }
        case 4: {
            propertyList.displayPropertiesInOrder();
            break;
        }
        case 5: // Exit option
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
