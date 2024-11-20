#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

class ToDoList
{
private:
    vector<pair<string, string>> tasks;

public:
    ToDoList() {}

    void append(string status = "pending")
    {
        string task;
        cout << "Enter Task: ";
        cin.ignore();
        getline(cin, task);

        tasks.push_back(make_pair(task, status));
    }

    void display()
    {
        if (tasks.empty())
        {
            cout << "List is empty" << endl;
            return;
        }
        for (auto &task : tasks)
        {
            cout << task.first << "--" << task.second << endl;
        }
    }

    void mark(string status = "completed")
    {
        string task;
        cout << "Enter Task: ";
        cin.ignore();
        getline(cin, task);

        bool found = false;
        for (auto &taskPair : tasks)
        {
            if (taskPair.first == task)
            {
                taskPair.second = status;
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "Task '" << task << "' not found in the list." << endl;
        }
        else
        {
            cout << "Task '" << task << "' marked as " << status << endl;
        }
    }

    void remove()
    {
        string task;
        cout << "Enter Task to remove: ";
        cin.ignore();
        getline(cin, task);

        auto it = tasks.begin();
        bool found = false;

        while (it != tasks.end())
        {
            if (it->first == task)
            {
                tasks.erase(it);
                found = true;
                break;
            }
            ++it;
        }

        if (!found)
        {
            cout << "Task '" << task << "' not found in the list." << endl;
        }
        else
        {
            cout << "Task '" << task << "' removed from the list." << endl;
        }
    }
};

int main()
{
    string para = R"(
    1. Add Task
    2. Display Tasks
    3. Mark Task
    4. Remove Task
    5. Exit
    )";
    cout << para << endl;

    ToDoList l1;
    int ch;

    while (true)
    {
        cout << "Select operation to perform (1/2/3/4/5): ";
        cin >> ch;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid selection! Please enter a number between 1 and 5." << endl;
            continue;
        }

        if (ch == 5)
        {
            break;
        }

        switch (ch)
        {
        case 1:
            l1.append();
            break;
        case 2:
            l1.display();
            break;
        case 3:
            l1.mark();
            break;
        case 4:
            l1.remove();
            break;
        default:
            cout << "Invalid selection!" << endl;
        }
    }

    return 0;
}
