#include <iostream>
#include <vector>
#include <string>

// Structure to represent a task
struct Task {
    std::string description;
    bool completed;
};

// Function declarations
void addTask(std::vector<Task>& tasks);
void viewTasks(const std::vector<Task>& tasks);
void markTaskCompleted(std::vector<Task>& tasks);
void removeTask(std::vector<Task>& tasks);

int main() {
    std::vector<Task> tasks;
    int choice;

    do {
        std::cout << "\n--- To-Do List Manager ---\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Remove Task\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();  // Ignore trailing newline character

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                std::cout << "Exiting To-Do List Manager.\n";
                break;
            default:
                std::cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

// Function to add a new task to the list
void addTask(std::vector<Task>& tasks) {
    Task newTask;
    std::cout << "Enter task description: ";
    std::getline(std::cin, newTask.description);
    newTask.completed = false;  // New tasks are initially pending
    tasks.push_back(newTask);
    std::cout << "Task added successfully!\n";
}

// Function to view the list of tasks
void viewTasks(const std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks to display.\n";
        return;
    }

    std::cout << "\n--- Task List ---\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". " << tasks[i].description << " ["
                  << (tasks[i].completed ? "Completed" : "Pending") << "]\n";
    }
}

// Function to mark a task as completed
void markTaskCompleted(std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks to mark as completed.\n";
        return;
    }

    int taskNumber;
    std::cout << "Enter task number to mark as completed: ";
    std::cin >> taskNumber;
    std::cin.ignore();

    if (taskNumber < 1 || taskNumber > tasks.size()) {
        std::cout << "Invalid task number.\n";
    } else {
        tasks[taskNumber - 1].completed = true;
        std::cout << "Task marked as completed!\n";
    }
}

// Function to remove a task from the list
void removeTask(std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks to remove.\n";
        return;
    }

    int taskNumber;
    std::cout << "Enter task number to remove: ";
    std::cin >> taskNumber;
    std::cin.ignore();

    if (taskNumber < 1 || taskNumber > tasks.size()) {
        std::cout << "Invalid task number.\n";
    } else {
        tasks.erase(tasks.begin() + taskNumber - 1);
        std::cout << "Task removed successfully!\n";
    }
}
