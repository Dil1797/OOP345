#include <iostream>
#include "HospitalLinkedList.h"

using namespace std;

int main() {
    HospitalLinkedList hospital;
    int choice;

    cout << "Welcome to the Emergency Hospital Management System!" << endl;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Add Patient" << endl;
        cout << "2. Remove Patient" << endl;
        cout << "3. Display Patients" << endl;
        cout << "4. Search Patient" << endl;
        cout << "5. Exit" << endl;
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int id;
            string name, severity;
            cout << "Enter Patient ID: ";
            cin >> id;
            cout << "Enter Patient Name: ";
            cin.ignore(); // Clear input buffer
            getline(cin, name);
            cout << "Enter Severity (low, moderate, high): ";
            getline(cin, severity);

            hospital.addPatient(id, name, severity);
            break;
        }
        case 2: {
            int id;
            cout << "Enter Patient ID to remove: ";
            cin >> id;
            hospital.removePatient(id);
            break;
        }
        case 3: {
            hospital.displayPatients();
            break;
        }
        case 4: {
            int id;
            cout << "Enter Patient ID to search: ";
            cin >> id;
            Patient* patient = hospital.searchPatient(id);
            if (patient) {
                cout << "ID: " << patient->getPatientID() << ", Name: " << patient->getName()
                    << ", Severity: " << patient->getSeverity() << endl;
            }
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