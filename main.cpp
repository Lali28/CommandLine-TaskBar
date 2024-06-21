#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
};

class TaskManager {
private:
    vector<Task> tasks;

public:
    void addTask(const string& description) {
        tasks.push_back({description, false});
        cout << "Task added successfully!" << endl;
    }

    void markTaskCompleted(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].completed = true;
            cout << "Task marked as completed!" << endl;
        } else {
            cout << "Invalid task index!" << endl;
        }
    }

    void viewAllTasks() {
        if (tasks.empty()) {
            cout << "No tasks to display." << endl;
        } else {
            cout << "Tasks:" << endl;
            for (size_t i = 0; i < tasks.size(); ++i) {
                cout << i + 1 << ". ";
                if (tasks[i].completed) cout << "[X] ";
                else cout << "[ ] ";
                cout << tasks[i].description << endl;
            }
        }
    }

    void removeTask(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks.erase(tasks.begin() + index);
            cout << "Task removed successfully!" << endl;
        } else {
            cout << "Invalid task index!" << endl;
        }
    }
};

int main() {
    TaskManager taskManager;
    int choice;

    do {
        cout << "\nTask Manager Menu:\n";
        cout << "1. Add Task\n";
        cout << "2. Mark Task as Completed\n";
        cout << "3. View All Tasks\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string description;
                cout << "Enter task description: ";
                cin.ignore();
                getline(cin, description);
                taskManager.addTask(description);
                break;
            }
            case 2: {
                int index;
                cout << "Enter task index to mark as completed: ";
                cin >> index;
                taskManager.markTaskCompleted(index - 1);
                break;
            }
            case 3:
                taskManager.viewAllTasks();
                break;
            case 4: {
                int index;
                cout << "Enter task index to remove: ";
                cin >> index;
                taskManager.removeTask(index - 1);
                break;
            }
            case 5:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
