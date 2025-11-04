This is a README.txt file that explains the purpose of the application, includes descriptions of the files, and provides instructions on how to 
compile and run the program based on the three code of Emergency Management System and Property Listings.

Emergency Management System and Property Listings

Purpose of the Application:
This application is designed to manage various aspects of emergency situations and property listings. It consists of three main modules:
1. Movie Ticket Booking System - Manages booking for movies, including hash table functionality.
2. Emergency Hospital Management System - Keeps track of patients in an emergency room using a linked list.
3. Real Estate Property Listings Management System - Manages listings of properties using a binary search tree (BST).

Included Files
The project contains the following files:

1. Movie Ticket Booking System Files:
   - `Booking.h`: Header file defining the `Booking` class for movie ticket bookings.
   - `BookingHashTable.h`: Header file defining the `BookingHashTable` class for managing bookings using a hash table.
   - `main.cpp`: Main implementation file for the Movie Ticket Booking System.

2. Emergency Hospital Management System Files:
   - `Patient.h`: Header file defining the `Patient` class for managing patient data.
   - `HospitalLinkedList.h`: Header file defining the `HospitalLinkedList` class for managing patients in linked list form.
   - `main.cpp`: Main implementation file for the Emergency Hospital Management System.

3. Real Estate Property Listings Management System Files:
   - `Property.h`: Header file defining the `Property` class for managing property data.
   - `PropertyBST.h`: Header file defining the `PropertyBST` class for managing properties using a binary search tree.
   - `main.cpp`: Main implementation file for the Real Estate Property Listings Management System.

Instructions to Compile and Run the Program

Prerequisites
A C++ compiler (such as g++ or Visual Studio).

Compilation and Execution
1. Compile the Movie Ticket Booking System:
   g++ main.cpp -o movieBooking BookingHashTable.h Booking.h
   Run the application:
./movieBooking

2. Compile the Emergency Hospital Management System:
g++ main.cpp -o hospitalManagement HospitalLinkedList.h Patient.h
Run the application:
./hospitalManagement

3. Compile the Real Estate Property Listings Management System:
g++ main.cpp -o propertyListings PropertyBST.h Property.h
Run the application:
./propertyListings

Usage Examples
1. Movie Ticket Booking: Follow the prompt to enter a booking ID, movie name, number of seats, and customer details.
2. Patient Management: Add patients, view their details, or remove them using their ID.
3. Property Listings: Add properties, search by ID, or view all stored properties.

This application demonstrates the use of various data structures to manage different types of data efficiently. Utilize the systems to explore 
managing bookings, patient data, and property listings effectively.