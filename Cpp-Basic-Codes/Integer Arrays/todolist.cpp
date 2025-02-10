#include <iostream>
using namespace std;

void display(string todoList[], int size) {
    if (size >0) {
    for (int i = 0; i < size; i++) {
        cout << i + 1 << ". " << todoList[i] << endl;
    }
}
     else if (size == 0) {
        cout << "No tasks in the list." << endl;
    }
}

void remove(string todoList[], int index, int &size) {
    if (index < 1 || index > size) { 
        cout << "Invalid index!" << endl;
        return; 
    }

    for (int i = index - 1; i < size - 1; i++) {
        todoList[i] = todoList[i + 1]; 
    }

    size--;
    cout << "Task removed successfully!" << endl;
}
void add(string todoList[], int &size) {
    cout << "Enter the task you want to add: ";
    cin >> todoList[size]; 
    size++;
}

int main() {
    string todoList[100];
    int size = 0;

    int time =0;
    while (true) {
        int choice;
        if(time>0){
            cout << endl << "---------------------------------" << endl;
        }
        cout << "1. Display the list of tasks" << endl;
        cout << "2. Add a task" << endl;
        cout << "3. Remove a task" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "---------------------------------" << endl;
            cout << "Tasks:" << endl;
            cout << "---------------------------------" << endl;
            display(todoList, size);
        } 
        else if (choice == 2) {
            add(todoList, size);
        } 
        else if (choice == 3) {
            int index;
            cout << "Enter the index of the task you want to remove: ";
            cin >> index;
            remove(todoList, index, size);
        } 
        else if (choice == 4) {
            cout << "Exiting program. Goodbye!" << endl;
            break;
        } 
        else {
            cout << "Wrong choice!Try again ." << endl;
        }
        time++;
    }
}
