#include <iostream>
#include <vector>
using namespace std;

class Task
{

public:
    string description;
    bool completed;
    Task(string d, bool c)
    {
        description = d;
        completed = c;
    }
};

class ToDoList
{
    vector<Task> tasks;

public:
    void addTask(string description)
    {
        Task newTask = {description, false};
        tasks.push_back(newTask);
        cout << "Task added: " << description << endl;
    }

    void viewTasks()
    {
        cout << "To Do List: " << endl;
        for (int i = 0; i < tasks.size(); i++)
        {
            cout << i + 1 << ". " << tasks[i].description << endl;
            if (tasks[i].completed)
            {
                cout << "Status: Completed" << endl;
            }
            else
            {
                cout << "Status: Pending" << endl;
            }
        }
    }

    void taskStatus(int index)
    {
        if (index > 0 && index <= tasks.size())
        {
            if (!(tasks[index - 1].completed))
            {
                tasks[index - 1].completed = true;
                cout << "Task marked as completed: " << tasks[index - 1].description << endl;
            }
            else
            {
                cout << "Task already completed!" << endl;
            }
        }
        else
        {
            cout << "Invalid index!" << endl;
        }
    }

    void removeTask(int index)
    {
        if (index > 0 && index <= tasks.size())
        {
            cout << "Task removed: " << tasks[index - 1].description << endl;
            tasks.erase(tasks.begin() + index - 1);
        }
        else
        {
            cout << "Invalid index!" << endl;
        }
    }
};

int main()
{
    ToDoList list;
    int choice, index;
    string desc;
    {
        cout << endl
             << "Menu:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cin.ignore();
            cout << "Enter task description: ";
            getline(cin, desc);
            list.addTask(desc);
            break;

        case 2:
            list.viewTasks();
            break;

        case 3:
            cout << "Enter the number of task that you want to mark as completed: ";
            cin >> index;
            list.taskStatus(index);
            break;

        case 4:
            cout << "Enter the number of task that you want to remove: ";
            cin >> index;
            list.removeTask(index);
            break;

        case 5:
            cout << "Goodbye!" << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    } while (choice != 5);
    return 0;
}