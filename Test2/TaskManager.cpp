#include "TaskManager.h"
#include <iomanip> // For output formatting

TaskManager::TaskManager() : rootNode(nullptr) {}

// Add a task node in the binary search tree sorted by due date and priority
void TaskManager::addTaskNode(TaskItem*& node, const string& description, int dueDate, int importance) {
    TaskItem* newNode = new TaskItem(description, dueDate, importance);

    if (!node) {
        node = newNode;
        return;
    }

    TaskItem* current = node;
    TaskItem* previous = nullptr;

    while (current) {
        previous = current;

        if (dueDate < current->taskDueDate || (dueDate == current->taskDueDate && importance > current->taskImportance)) {
            current = current->leftChild;  // Go left if due date is less or importance is higher
        }
        else {
            current = current->rightChild; // Go right otherwise
        }
    }

    if (dueDate < previous->taskDueDate || (dueDate == previous->taskDueDate && importance > previous->taskImportance)) {
        previous->leftChild = newNode;
    }
    else {
        previous->rightChild = newNode;
    }
}

// Show tasks in order
void TaskManager::showTasksInOrder(TaskItem* node) const {
    if (node) {
        showTasksInOrder(node->leftChild);
        // Extract day, month, year for formatting the output
        int year = node->taskDueDate % 10000;
        int month = (node->taskDueDate / 10000) % 100;
        int day = node->taskDueDate / 1000000;

        cout << "Task: " << node->taskDescription
            << ", Due: " << std::setfill('0') << std::setw(2) << day << "/"
            << std::setfill('0') << std::setw(2) << month << "/"
            << year << ", Importance: " << node->taskImportance
            << endl;

        showTasksInOrder(node->rightChild);
    }
}

// Locate a task by due date
TaskItem* TaskManager::locateTask(TaskItem* node, int dueDate) const {
    while (node && node->taskDueDate != dueDate) {
        node = (dueDate < node->taskDueDate) ? node->leftChild : node->rightChild;
    }
    return node; // Return found node or nullptr
}

// Count pending tasks after a specific date
int TaskManager::countPendingTasks(TaskItem* node, int currentDate) const {
    if (!node) return 0;
    if (node->taskDueDate > currentDate) {
        return 1 + countPendingTasks(node->leftChild, currentDate) + countPendingTasks(node->rightChild, currentDate);
    }
    return countPendingTasks(node->rightChild, currentDate);
}

// Add a task to the manager
void TaskManager::addTask(const string& description, int dueDate, int importance) {
    addTaskNode(rootNode, description, dueDate, importance);
}

// Display all tasks
void TaskManager::displayAllTasks() const {
    showTasksInOrder(rootNode);
}

// Search for a task by due date
void TaskManager::searchForTask(int dueDate) const {
    TaskItem* foundTask = locateTask(rootNode, dueDate);
    if (foundTask) {
        // Extract day, month, year for formatting
        int year = foundTask->taskDueDate % 10000;
        int month = (foundTask->taskDueDate / 10000) % 100;
        int day = foundTask->taskDueDate / 1000000;

        cout << "Found: " << foundTask->taskDescription
            << ", Due: " << std::setfill('0') << std::setw(2) << day << "/"
            << std::setfill('0') << std::setw(2) << month << "/"
            << year << ", Importance: " << foundTask->taskImportance << endl;
    }
    else {
        cout << "No task found for the due date.\n";
    }
}

// Count tasks that are pending after a specific date
void TaskManager::countTasksAfter(int currentDate) const {
    int count = countPendingTasks(rootNode, currentDate);

    // Extract day, month, year for formatting currentDate
    int year = currentDate % 10000;
    int month = (currentDate / 10000) % 100;
    int day = currentDate / 1000000;

    // Output the count of pending tasks
    cout << "Tasks pending after "
        << std::setfill('0') << std::setw(2) << day << "/"
        << std::setfill('0') << std::setw(2) << month << "/"
        << year << ": " << count << endl;
}