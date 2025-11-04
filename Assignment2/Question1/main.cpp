#include <iostream>
#include "BookingHashTable.h"

using namespace std;

int main() {
    cout << "Welcome to the Movie Ticket Booking System!" << endl; // Welcome message

    BookingHashTable hashTable;
    int choice;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Book Ticket" << endl;
        cout << "2. Cancel Booking" << endl;
        cout << "3. Display Bookings" << endl;
        cout << "4. Booking Status" << endl; // New option for booking status
        cout << "5. Exit" << endl;
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int bookingID, seats;
            string movieName, customerName;
            cout << "Enter Booking ID: ";
            cin >> bookingID;
            cout << "Enter Movie Name: ";
            cin.ignore(); // Clear input buffer
            getline(cin, movieName);
            cout << "Enter Number of Seats: ";
            cin >> seats;
            cout << "Enter Customer Name: ";
            cin.ignore(); // Clear input buffer
            getline(cin, customerName);

            hashTable.bookTicket(bookingID, movieName, seats, customerName);
            break;
        }
        case 2: {
            int bookingID;
            cout << "Enter Booking ID to cancel: ";
            cin >> bookingID;
            hashTable.cancelBooking(bookingID);
            break;
        }
        case 3: {
            hashTable.displayBookings();
            break;
        }
        case 4: { // New case for Booking Status
            cout << "Available Bookings: " << hashTable.availableBookings() << endl;
            break;
        }
        case 5: // Updated option for exit
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}