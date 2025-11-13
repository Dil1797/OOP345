#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <iostream>
#include <string>

using namespace std;

// Function to validate if a date is valid (prototype only)
bool isValidDate(int day, int month, int year);

// Structure to represent each task in the tree
struct TaskItem {
    string taskDescription; // Description of the task
    int taskDueDate;        // Stored as DDMMYYYY
    int taskImportance;     // Importance level (1-5)
    TaskItem* leftChild;    // Left child pointer
    TaskItem* rightChild;   // Right child pointer

    // Default constructor
    TaskItem() : taskDescription(""), taskDueDate(0), taskImportance(0), leftChild(nullptr), rightChild(nullptr) {}

    // Parameterized constructor
    TaskItem(const string& description, int dueDate, int importance) {
        taskDescription = description;
        taskImportance = (importance >= 1 && importance <= 5) ? importance : 3;
        if (dueDate >= 1012024 && dueDate <= 31122029) {
            taskDueDate = dueDate; // Set due date if valid
        }
        else {
            taskDueDate = 1012024; // Default date
        }
        leftChild = rightChild = nullptr; // Initialize pointers to nullptr
    }
};

// Class to manage tasks and provide functionalities
class TaskManager {
    TaskItem* rootNode; // Root of the binary tree

    void addTaskNode(TaskItem*& node, const string& description, int dueDate, int importance); // Function to add task to tree
    void showTasksInOrder(TaskItem* node) const; // Display tasks in order
    TaskItem* locateTask(TaskItem* node, int dueDate) const; // Locate a task by due date
    int countPendingTasks(TaskItem* node, int currentDate) const; // Count tasks pending after a particular date

public:
    TaskManager(); // Constructor to initialize the rootNode
    void addTask(const string& description, int dueDate, int importance); // Public method to add task
    void displayAllTasks() const; // Public method to display all tasks
    void searchForTask(int dueDate) const; // Public method to find task by due date
    void countTasksAfter(int currentDate) const; // Public method to count tasks after a particular date
};

#endif // TASKMANAGER_H