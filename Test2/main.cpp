#include <iostream>
#include <sstream> // For string stream manipulation
#include <iomanip> // For output formatting
#include "TaskManager.h"

using namespace std;

// Function to validate the date format and range
bool isValidDate(int day, int month, int year) {
    // Check for valid date ranges
    if (month < 1 || month > 12 || day < 1 || year < 2024) return false;

    // Simple check for the number of days in each month
    int daysInMonth = 31;
    if (month == 2) {
        daysInMonth = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) ? 29 : 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        daysInMonth = 30;
    }
    return day <= daysInMonth;
}

// Function to obtain a valid date from the user
int getValidDate() {
    string dateInput;
    int day, month, year;

    while (true) {
        cout << "Due date (dd/mm/yyyy): ";
        cin >> dateInput;

        // Parse the date input
        char slash1, slash2; // To capture the '/' characters
        istringstream dateStream(dateInput);
        dateStream >> day >> slash1 >> month >> slash2 >> year;

        if (dateStream && slash1 == '/' && slash2 == '/' && isValidDate(day, month, year)) {
            break; // Exit loop when the date is valid
        }

        else {
            cout << "Invalid date format or range. Please enter in dd/mm/yyyy format." << endl;
        }
    }

    // Return date in DDMMYYYY format for the tree
    return (day * 1000000) + (month * 10000) + year; // Creates an integer in the format DDMMYYYY
}

// Function to obtain a valid priority from user
int getValidPriority() {
    int priority;
    while (true) {
        cout << "Importance (1-5): ";
        cin >> priority;
        if (priority >= 1 && priority <= 5) {
            break;
        }
        else {
            cout << "Priority must be between 1 and 5. Please try again." << endl;
        }
    }
    return priority;
}

int main() {
    TaskManager manager;
    int option;
    int dueDate;     // Declare dueDate here
    int priority;     // Declare priority here
    string description;

    cout << "Welcome to Enhanced Task Scheduler\n";
    do {
        cout << "\nOptions:\n"
            << "1. Add Task\n"
            << "2. Show All Tasks\n"
            << "3. Find Task by Due Date\n"
            << "4. Count Pending Tasks\n"
            << "5. Exit\n"
            << "\nSelect Option: ";
        cin >> option;

        switch (option) {
        case 1:
            cin.ignore(); // Clear the newline from the input buffer before getline
            cout << "Task description: ";
            getline(cin, description);
            dueDate = getValidDate();    // Get valid date here
            priority = getValidPriority();  // Get valid priority here
            manager.addTask(description, dueDate, priority);
            break;

        case 2:
            cout << "Displaying all tasks in order:\n";
            manager.displayAllTasks();
            break;

        case 3: {
            cin.ignore(); // Clear input buffer before getline
            string dateInput;
            cout << "Enter due date (dd/mm/yyyy): ";
            cin >> dateInput;

            // Parse the input date
            int day, month, year;
            char slash1, slash2;
            istringstream inputStream(dateInput);
            inputStream >> day >> slash1 >> month >> slash2 >> year;

            if (inputStream && slash1 == '/' && slash2 == '/' && isValidDate(day, month, year)) {
                // Convert to DDMMYYYY format
                dueDate = (day * 1000000) + (month * 10000) + year;
                manager.searchForTask(dueDate);
            }
            else {
                cout << "Invalid date format. Please use dd/mm/yyyy." << endl;
            }
            break;
        }

        case 4: {
            cin.ignore(); // Clear input buffer before getline
            string dateInput;
            cout << "Enter a date to count tasks after (dd/mm/yyyy): ";
            cin >> dateInput;

            // Parse the input
            int day, month, year;
            char slash1, slash2;
            istringstream inputStream(dateInput);
            inputStream >> day >> slash1 >> month >> slash2 >> year;

            if (inputStream && slash1 == '/' && slash2 == '/' && isValidDate(day, month, year)) {
                // Convert to DDMMYYYY format
                dueDate = (day * 1000000) + (month * 10000) + year;
                manager.countTasksAfter(dueDate);
            }
            else {
                cout << "Invalid date format. Please use dd/mm/yyyy." << endl;
            }
            break;
        }

        case 5:
            cout << "Exiting the Task Scheduler. Have a great day!\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (option != 5);

    return 0;
}
