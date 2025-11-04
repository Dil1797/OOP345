#ifndef BOOKINGHASHTABLE_H
#define BOOKINGHASHTABLE_H

#include "Booking.h"
#include <iostream>

using namespace std;

class BookingHashTable {
private:
    static const int TABLE_SIZE = 15; // Fixed size of the hash table.
    Booking* table[TABLE_SIZE];
    int currentBookings; // To track the number of current bookings

    int hashFunction(int bookingID) {
        return bookingID % TABLE_SIZE;
    }

public:
    BookingHashTable() : currentBookings(0) { // Initialize currentBookings to 0
        for (int i = 0; i < TABLE_SIZE; ++i) {
            table[i] = nullptr;
        }
    }

    ~BookingHashTable() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            delete table[i];
        }
    }

    // Method to book tickets
    void bookTicket(int bookingID, const string& movieName, int seats, const string& customerName) {
        if (seats <= 0) {
            cout << "Booking failed: Invalid number of seats." << endl;
            return;
        }
        if (movieName.empty()) {
            cout << "Booking failed: Movie name cannot be empty." << endl;
            return;
        }

        // Check for double booking
        if (searchBooking(bookingID) != nullptr) {
            cout << "Booking failed: Booking ID " << bookingID << " already exists. You can not book ticket twice." << endl;
            return;
        }

        // Check if the table is full
        if (currentBookings >= TABLE_SIZE) {
            cout << "Booking failed: Hash table is full. Cannot book more tickets." << endl;
            return;
        }

        // Find index for booking
        int index = hashFunction(bookingID);
        for (int i = 0; i < TABLE_SIZE; ++i) {
            if (table[index] == nullptr) {
                // Book the ticket
                table[index] = new Booking(bookingID, movieName, seats, customerName);
                currentBookings++; // Increase number of current bookings
                cout << "Booking successful: " << bookingID << endl;
                return;
            }
            index = (index + 1) % TABLE_SIZE; // Linear probing
        }

        // If we reach this point, the table is full
        cout << "Booking failed: Hash table is full." << endl;
    }

    // Method to check if a booking exists
    Booking* searchBooking(int bookingID) {
        int index = hashFunction(bookingID);
        for (int i = 0; i < TABLE_SIZE; ++i) {
            if (table[index] == nullptr) {
                return nullptr; // Not found
            }
            if (table[index]->bookingID == bookingID) {
                return table[index]; // Found
            }
            index = (index + 1) % TABLE_SIZE;
        }
        return nullptr; // Not found
    }

    // Method to cancel bookings
    void cancelBooking(int bookingID) {
        int index = hashFunction(bookingID);
        for (int i = 0; i < TABLE_SIZE; ++i) {
            if (table[index] == nullptr) {
                cout << "Cancellation failed: Booking ID " << bookingID << " does not exist." << endl;
                return; // Booking ID not found
            }
            if (table[index]->bookingID == bookingID) {
                delete table[index]; // Free memory
                table[index] = nullptr; // Remove booking
                currentBookings--; // Decrease number of current bookings
                cout << "Booking cancelled: " << bookingID << endl;
                return;
            }
            index = (index + 1) % TABLE_SIZE;
        }
    }

    // Method to display current bookings
    void displayBookings() {
        cout << "Current Bookings:" << endl;
        for (int i = 0; i < TABLE_SIZE; ++i) {
            if (table[i] != nullptr) {
                cout << "Booking ID: " << table[i]->bookingID
                    << ", Movie: " << table[i]->movieName
                    << ", Seats: " << table[i]->seats
                    << ", Customer: " << table[i]->customerName << endl;
            }
        }
    }

    // Method to get the number of available bookings
    int availableBookings() const {
        return TABLE_SIZE - currentBookings; // Calculate available slots
    }
};

#endif // BOOKINGHASHTABLE_H