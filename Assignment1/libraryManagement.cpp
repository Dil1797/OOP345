
/*
Name: Dil Humyra Sultana Borna
Student ID: 139166227
Date: 16/10/2024
*/

#include "LibraryManagement.h"
#include <iostream>

using namespace std; // Use the standard namespace

// Function to display the main menu
void displayMainMenu() {
    cout << "\nWelcome to the Virtual Library\n\n";
    cout << "Library Management System Menu:\n";
    cout << "1. Books\n";
    cout << "2. Magazines\n";
    cout << "0. Exit\n";
    cout << "Choose an option: ";
}

// Function to manage book operations
void handleBooks(Catalog<Book>& bookCatalog) {
    bool running = true;

    while (running) {
        cout << "\nBook Menu:\n";
        cout << "1. View All Books\n";
        cout << "2. Search Book\n";
        cout << "3. Borrow Book\n";
        cout << "4. View Borrowed Items\n";
        cout << "5. Store Book\n";
        cout << "6. Return Book\n";
        cout << "0. Back to Main Menu\n";
        cout << "Choose an option: ";

        int option;
        cin >> option;
        cin.ignore(); // Clear the newline character from the input buffer

        if (option == 1) {
            // New menu for sorting options
            cout << "\nView Books By:\n";
            cout << "1. Title\n";
            cout << "2. Author\n";
            cout << "3. ISBN\n";
            cout << "0. Back to Book Menu\n"; // Option to go back
            cout << "Choose an option: ";

            int sortOption;
            cin >> sortOption;
            cout << endl;
            cin.ignore(); // Clear the newline character from the input buffer

            if (sortOption == 1) {
                bookCatalog.displayAllSorted("title");
            }
            else if (sortOption == 2) {
                bookCatalog.displayAllSorted("author");
            }
            else if (sortOption == 3) {
                bookCatalog.displayAllSorted("isbn");
            }
            else if (sortOption == 0) {
                continue; // Back to main book options
            }
            else {
                cout << "Invalid option.\n";
            }
        }
        else if (option == 2) {
            // Search for a book
            string attribute, value;
            cout << "\nSearch by:\n";
            cout << "1. Title\n";
            cout << "2. Author\n";
            cout << "3. ISBN\n";
            cout << "Choose an option: ";
            int searchOption;
            cin >> searchOption;
            cin.ignore(); // Clear the buffer

            if (searchOption == 1) {
                cout << "Enter Title: ";
                getline(cin, value);
                bookCatalog.searchItem("title", value);
            }
            else if (searchOption == 2) {
                cout << "Enter Author: ";
                getline(cin, value);
                bookCatalog.searchItem("author", value);
            }
            else if (searchOption == 3) {
                cout << "Enter ISBN: ";
                getline(cin, value);
                bookCatalog.searchItem("isbn", value);
            }
            else {
                cout << "Invalid option.\n";
            }
        }
        else if (option == 3) {
            string isbn;
            cout << "Enter ISBN of the book to borrow: ";
            getline(cin, isbn);
            string borrowerName;
            cout << "Enter your name: "; // Prompt for borrower's name
            getline(cin, borrowerName);
            bookCatalog.borrowItem(isbn, borrowerName); // Use provided name
        }
        else if (option == 4) {
            bookCatalog.displayBorrowedItems();
        }
        else if (option == 5) {
            // Store Book
            string title, author, isbn, genre;
            int year;
            cout << "Enter Book Title: ";
            getline(cin, title);
            cout << "Enter Author Name: ";
            getline(cin, author);
            cout << "Enter Year: ";
            cin >> year;
            cin.ignore(); // Clear the buffer
            cout << "Enter ISBN: ";
            getline(cin, isbn);
            cout << "Enter Genre: ";
            getline(cin, genre);
            bookCatalog.addItem(Book(title, author, isbn, genre, year));
            cout << "Congratulations! The book has been stored successfully.\n";
        }
        else if (option == 6) {
            // Return Book
            string isbn;
            cout << "Enter ISBN of the book to return: ";
            getline(cin, isbn);
            bookCatalog.returnItem(isbn);
        }
        else if (option == 0) {
            running = false; // Back to Main Menu
        }
        else {
            cout << "Invalid choice. Please try again.\n";
        }
    }
}

// Function to manage magazine operations
void handleMagazines(Catalog<Magazine>& magazineCatalog) {
    bool running = true;

    while (running) {
        cout << "\nMagazine Menu:\n";
        cout << "1. View All Magazines\n";
        cout << "2. Search Magazine\n"; // Search option
        cout << "3. Borrow Magazine\n";
        cout << "4. View Borrowed Items\n";
        cout << "5. Store Magazine\n";
        cout << "6. Return Magazine\n";
        cout << "0. Back to Main Menu\n";
        cout << "Choose an option: ";

        int option;
        cin >> option;
        cin.ignore(); // Clear the newline character from the input buffer

        if (option == 1) {
            // New menu for sorting options for magazines
            cout << "\nView Magazines By:\n";
            cout << "1. Title\n";
            cout << "2. Author\n";
            cout << "3. ISBN\n";
            cout << "0. Back to Magazine Menu\n"; // Option to go back
            cout << "Choose an option: ";

            int sortOption;
            cin >> sortOption;
            cout << endl;
            cin.ignore(); // Clear the newline character from the input buffer

            if (sortOption == 1) {
                magazineCatalog.displayAllSorted("title");
            }
            else if (sortOption == 2) {
                magazineCatalog.displayAllSorted("author");
            }
            else if (sortOption == 3) {
                magazineCatalog.displayAllSorted("isbn");
            }
            else if (sortOption == 0) {
                continue; // Back to main magazine options
            }
            else {
                cout << "Invalid option.\n";
            }
        }
        else if (option == 2) {
            // Search for a magazine
            string attribute, value;
            cout << "Search by:\n";
            cout << "1. Title\n";
            cout << "2. Author\n";
            cout << "3. ISBN\n";
            cout << "Choose an option: ";
            int searchOption;
            cin >> searchOption;
            cin.ignore(); // Clear the buffer

            if (searchOption == 1) {
                cout << "Enter Title: ";
                getline(cin, value);
                magazineCatalog.searchItem("title", value); // Call the search function
            }
            else if (searchOption == 2) {
                cout << "Enter Author: ";
                getline(cin, value);
                magazineCatalog.searchItem("author", value); // Call the search function
            }
            else if (searchOption == 3) {
                cout << "Enter ISBN: ";
                getline(cin, value);
                magazineCatalog.searchItem("isbn", value); // Call the search function
            }
            else {
                cout << "Invalid option.\n";
            }
        }
        else if (option == 3) {
            string isbn;
            cout << "Enter ISBN of the magazine to borrow: ";
            getline(cin, isbn);
            string borrowerName;
            cout << "Enter your name: "; // Prompt for borrower's name
            getline(cin, borrowerName);
            magazineCatalog.borrowItem(isbn, borrowerName); // Use provided name
        }
        else if (option == 4) {
            magazineCatalog.displayBorrowedItems();
        }
        else if (option == 5) {
            // Store Magazine
            string title, author, isbn;
            int issueNumber;
            cout << "Enter Magazine Title: ";
            getline(cin, title);
            cout << "Enter Author Name: ";
            getline(cin, author);
            cout << "Enter ISBN: ";
            getline(cin, isbn);
            cout << "Enter Issue Number: ";
            cin >> issueNumber;
            cin.ignore(); // Clear the buffer
            magazineCatalog.addItem(Magazine(title, author, isbn, issueNumber));
            cout << "Congratulations! The magazine has been stored successfully.\n";
        }
        else if (option == 6) {
            string isbn;
            cout << "Enter ISBN of the magazine to return: ";
            getline(cin, isbn);
            magazineCatalog.returnItem(isbn);
        }
        else if (option == 0) {
            running = false; // Back to Main Menu
        }
        else {
            cout << "Invalid choice. Please try again.\n";
        }
    }
}

int main() {
    Catalog<Book> bookCatalog;
    Catalog < Magazine> magazineCatalog;

    // Sample books
    Book b1("The Great Gatsby", "F. Scott Fitzgerald", "123456789", "Fiction", 1925);
    Book b2("1984", "George Orwell", "987654321", "Dystopian", 1949);
    Book b3("Brave New World", "Aldous Huxley", "111222333", "Sci-Fi", 1910);

    bookCatalog.addItem(b1);
    bookCatalog.addItem(b2);
    bookCatalog.addItem(b3);

    // Sample magazines
    Magazine m1("Tech Weekly", "Jane Doe", "333444555", 42);
    Magazine m2("Nature World", "John Smith", "444555666", 15);

    magazineCatalog.addItem(m1);
    magazineCatalog.addItem(m2);

    bool running = true;

    while (running) {
        displayMainMenu();
        int menuOption;
        cin >> menuOption;
        cin.ignore(); // Clear the newline character from the input buffer

        if (menuOption == 1) {
            handleBooks(bookCatalog);
        }
        else if (menuOption == 2) {
            handleMagazines(magazineCatalog);
        }
        else if (menuOption == 0) {
            running = false; // Exit the program
        }
        else {
            cout << "Invalid option. Please select a valid choice.\n";
        }
    }

    cout << "\nThank you for using the Library Management System. Goodbye!" << endl;
    return 0;
}
