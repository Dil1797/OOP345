#pragma once
#ifndef BOOKING_H
#define BOOKING_H

#include <iostream>
#include <string>

using namespace std;

class Booking {
public:
    int bookingID;
    string movieName;
    int seats;
    string customerName;

    // Constructor
    Booking(int id, const string& movie, int s, const string& customer)
        : bookingID(id), movieName(movie), seats(s), customerName(customer) {}

    // Getter methods
    int getBookingID() const { return bookingID; }
    string getMovieName() const { return movieName; }
    int getSeats() const { return seats; }
    string getCustomerName() const { return customerName; }

    // Setter methods
    void setBookingID(int id) { bookingID = id; }
    void setMovieName(const string& movie) { movieName = movie; }
    void setSeats(int s) { seats = s; }
    void setCustomerName(const string& customer) { customerName = customer; }
};

#endif // BOOKING_H
