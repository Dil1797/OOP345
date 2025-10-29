
/*
Name: Dil Humyra Sultana Borna
Student ID: 139166227
Date: 16/10/2024
*/


#ifndef LIBRARYMANAGEMENT_H
#define LIBRARYMANAGEMENT_H

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <stdexcept>
#include <typeinfo>

using namespace std; // Using the standard namespace

// Base class LibraryItem
class LibraryItem {
protected:
    string title;
    string author;
    string ISBN;

public:
    LibraryItem(const string& title, const string& author, const string& ISBN)
        : title(title), author(author), ISBN(ISBN) {}

    virtual ~LibraryItem() = default;

    // Pure virtual function for displaying item details
    virtual void displayDetails() const = 0;

    // Getters for attributes
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getISBN() const { return ISBN; }
};

// Derived class Book
class Book : public LibraryItem {
private:
    string genre;
    int year;
    bool isBorrowed = false; // Track if the book is borrowed

public:
    Book(const string& title, const string& author, const string& ISBN,
        const string& genre, int year)
        : LibraryItem(title, author, ISBN), genre(genre), year(year) {}

    void displayDetails() const override {
        cout << "Book: " << title << " by " << author << ", ISBN: " << ISBN
            << ", Genre: " << genre << ", Year: " << year
            << (isBorrowed ? " (Borrowed)" : " (Available)") << endl;
    }

    int getYear() const { return year; }
    string getGenre() const { return genre; }
    bool getIsBorrowed() const { return isBorrowed; }
    void setIsBorrowed(bool status) { isBorrowed = status; }
};

// Derived class Magazine
class Magazine : public LibraryItem {
private:
    int issueNumber;

public:
    Magazine(const string& title, const string& author, const string& ISBN, int issueNumber)
        : LibraryItem(title, author, ISBN), issueNumber(issueNumber) {}

    void displayDetails() const override {
        cout << "Magazine: " << title << " by " << author
            << ", ISBN: " << ISBN << ", Issue: " << issueNumber << endl;
    }
};

// Template class Catalog
template <typename T>
class Catalog {
private:
    vector<T> items;
    map<string, string> borrowedItems; // Key: ISBN, Value: Borrower's Name

public:
    void addItem(const T& item) {
        items.push_back(item);
    }

    void removeItem(const T& item) {
        items.erase(remove(items.begin(), items.end(), item), items.end());
    }

    template <typename Func>
    T searchItem(Func func) {
        auto it = find_if(items.begin(), items.end(), func);
        if (it != items.end()) {
            return *it;
        }
        throw runtime_error("Item not found");
    }

    // Function to search item based on attributes like title, author, or ISBN
    void searchItem(const string& attribute, const string& value) const {
        auto it = find_if(items.begin(), items.end(),
            [&attribute, &value](const T& item) {
                if (attribute == "title") return item.getTitle() == value;
                if (attribute == "author") return item.getAuthor() == value;
                if (attribute == "isbn") return item.getISBN() == value;
                return false;
            });

        if (it != items.end()) {
            cout << "Search Result:\n";
            it->displayDetails();
        }
        else {
            cout << "Item not found." << endl;
        }
    }

    void displayAll() const {
        for (const auto& item : items) {
            item.displayDetails();
        }
    }

    void displayAllSorted(const string& sortBy) {
        vector<T> sortedItems = items; // Create a copy to sort
        if (sortBy == "title") {
            sort(sortedItems.begin(), sortedItems.end(), [](const T& a, const T& b) {
                return a.getTitle() < b.getTitle();
                });
        }
        else if (sortBy == "author") {
            sort(sortedItems.begin(), sortedItems.end(), [](const T& a, const T& b) {
                return a.getAuthor() < b.getAuthor();
                });
        }
        else if (sortBy == "isbn") {
            sort(sortedItems.begin(), sortedItems.end(), [](const T& a, const T& b) {
                return a.getISBN() < b.getISBN();
                });
        }

        for (const auto& item : sortedItems) {
            item.displayDetails();
        }
    }

    void borrowItem(const string& isbn, const string& borrower) {
        auto it = find_if(items.begin(), items.end(),
            [&isbn](const T& item) { return item.getISBN() == isbn; });

        if (it != items.end()) {
            if constexpr (is_same<T, Book>::value) { // Check if T is Book
                if (!it->getIsBorrowed()) {
                    borrowedItems[isbn] = borrower;
                    it->setIsBorrowed(true);
                    cout << "Congratulations, you have borrowed the book!" << endl;
                }
                else {
                    cout << "Sorry, this book is already borrowed." << endl;
                }
            }
            else {
                // For magazines, simply note the borrowing
                borrowedItems[isbn] = borrower; // Track borrowing without the borrowed status
                cout << "You've borrowed the magazine!" << endl;
            }
        }
        else {
            cout << "Item not found. Please check the title, author, year, or ISBN." << endl;
        }
    }

    void returnItem(const string& isbn) {
        auto it = find_if(items.begin(), items.end(),
            [&isbn](const T& item) { return item.getISBN() == isbn; });

        if (it != items.end()) {
            auto borrowedIt = borrowedItems.find(isbn);
            if (borrowedIt != borrowedItems.end()) {
                borrowedItems.erase(borrowedIt);
                if constexpr (is_same<T, Book>::value) { // Check if T is Book
                    it->setIsBorrowed(false); // Reset borrowed status for books
                }
                cout << "You have returned the item successfully!" << endl;
            }
            else {
                cout << "This item was not borrowed." << endl;
            }
        }
        else {
            cout << "Item not found." << endl;
        }
    }

    void displayBorrowedItems() const {
        if (borrowedItems.empty()) {
            cout << "No items are currently borrowed." << endl;
            return;
        }

        cout << "Currently Borrowed Items:\n";
        for (const auto& entry : borrowedItems) {
            cout << "ISBN: " << entry.first << ", Borrower: " << entry.second << endl;
        }
    }

    // Iterator support
    typename vector<T>::iterator begin() { return items.begin(); }
    typename vector<T>::iterator end() { return items.end(); }
};

// Functor for sorting by title
struct SortByTitle {
    bool operator()(const Book& a, const Book& b) {
        return a.getTitle() < b.getTitle();
    }
};

// Functor for sorting by author
struct SortByAuthor {
    bool operator()(const Book& a, const Book& b) {
        return a.getAuthor() < b.getAuthor();
    }
};

// Functor for sorting by year (for Book objects)
struct SortByYear {
    bool operator()(const Book& a, const Book& b) {
        return a.getYear() < b.getYear();
    }
};

#endif // LIBRARYMANAGEMENT_H