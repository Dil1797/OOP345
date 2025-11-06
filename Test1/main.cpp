#include <iostream>
#include "linkedList.h"

using namespace std;

int main() {
    LinkedListStack stack;
    int choice, value;

    //menu options
    do {
        cout << "Menu:\n";
        cout << "1. Insert (Push)\n";
        cout << "2. Delete (Pop)\n";
        cout << "3. Display\n";
        cout << "4. Size\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: //insert
            cout << "Enter value to insert: ";
            cin >> value;
            stack.insert(value);
            cout << endl;
            break;

        case 2: //delete
            stack.deleteNode();
            cout << endl;
            break;

        case 3: // display
            stack.display();
            cout << endl;
            break;

        case 4: //size
            cout << "Current size: " << stack.getSize() << endl;
            cout << endl;
            break;

        case 5: //exit
            cout << "Exiting program." << endl;
            cout << endl;
            break;

        default:
            cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
