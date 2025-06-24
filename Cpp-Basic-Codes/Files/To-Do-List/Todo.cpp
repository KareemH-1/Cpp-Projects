#include <bits/stdc++.h>
#include <windows.h>
#include <fstream>
using namespace std;

void welcomeScreen() {
    cout << "======================================" << endl;
    cout << "||       WELCOME TO TO-DO LIST      ||" << endl;
    cout << "======================================" << endl;
    cout << "||                                  ||" << endl;
    cout << "||         1. Start To-Do List      ||" << endl;
    cout << "||         2. Exit                  ||" << endl;
    cout << "======================================" << endl;
    cout << "||    Please enter your choice:     ||" << endl;
    cout << "======================================" << endl;
}

void mainMenuScreen() {
    cout << "======================================" << endl;
    cout << "||         TO-DO MAIN MENU          ||" << endl;
    cout << "======================================" << endl;
    cout << "||                                  ||" << endl;
    cout << "||        1. View Tasks             ||" << endl;
    cout << "||        2. Add Task               ||" << endl;
    cout << "||        3. Edit Task              ||" << endl;
    cout << "||        4. Remove Task            ||" << endl;
    cout << "||        5. Quit                   ||" << endl;
    cout << "||                                  ||" << endl;
    cout << "======================================" << endl;
}

vector<string> table;
string filepath = "./list.txt";

void loadFromFile() {
    table.clear();
    ifstream in(filepath);
    if (!in) {
        cout << "No saved file found at \"" << filepath << "\". Starting a new list.\n";
        Sleep(1000);
        return;
    }
    string line;
    while (getline(in, line)) {
        table.push_back(line);
    }
}

void saveToFile() {
    ofstream out(filepath);
    for (auto& task : table) {
        out << task << "\n";
    }
}

void add(string task) {
    table.push_back(task);
}

void deleteT(int index) {
    table.erase(table.begin() + index);
}

void edit(string New, int index) {
    table[index] = New;
}

int main() {
    welcomeScreen();
    int choice;
    cin >> choice;
    cin.ignore(256, '\n');

    while (choice != 1 && choice != 2) {
        cout << "Invalid choice. Please enter 1 to Start or 2 to Exit: ";
        cin >> choice;
        cin.ignore(256, '\n');
    }
    if (choice != 1) return 0;

    cout << "Default file path is: " << filepath << "\n";
    cout << "Use default? (y/n): ";
    char c;
    cin >> c;
    cin.ignore(256, '\n');
    if (c == 'n' || c == 'N') {
        cout << "Enter full file path (including filename): ";
        getline(cin, filepath);
    }

    loadFromFile();

    bool exitFlag = false;
    while (!exitFlag) {
        system("cls");
        mainMenuScreen();

        char choice2;
        cin >> choice2;
        cin.ignore(256, '\n');
        system("cls");

        switch (choice2) {
        case '5': case 'Q': case 'q':
            exitFlag = true;
            break;

        case '1': case 'V': case 'v': {
            cout << "TO-DO List:\n================================\n\n";
            if (table.empty()) {
                cout << "No tasks. Add one!\n\n";
            }
            else {
                for (int i = 0; i < (int)table.size(); ++i)
                    cout << (i + 1) << ". " << table[i] << "\n";
            }
            cout << "\nPress any key to go back...";
            cin.get();
            break;
        }

        case '2': case 'A': case 'a': {
            cout << "Enter a new task: ";
            string s;
            getline(cin, s);
            add(s);
            saveToFile();
            cout << "Task added.\n";
            Sleep(800);
            break;
        }

        case '3': case 'E': case 'e': {
            if (table.empty()) {
                cout << "No tasks to edit.\n";
                Sleep(800);
                break;
            }
            cout << "Choose task number to edit:\n";
            for (int i = 0; i < (int)table.size(); ++i)
                cout << (i + 1) << ". " << table[i] << "\n";
            int idx;
            cin >> idx;
            cin.ignore(256, '\n');
            if (idx >= 1 && idx <= (int)table.size()) {
                cout << "Enter new text: ";
                string s;
                getline(cin, s);
                edit(s, idx - 1);
                saveToFile();
                cout << "Task updated.\n";
            }
            else {
                cout << "Invalid number.\n";
            }
            Sleep(800);
            break;
        }

        case '4': case 'R': case 'r': {
            if (table.empty()) {
                cout << "No tasks to remove.\n";
                Sleep(800);
                break;
            }
            cout << "Choose task number to remove:\n";
            for (int i = 0; i < (int)table.size(); ++i)
                cout << (i + 1) << ". " << table[i] << "\n";
            int idx;
            cin >> idx;
            cin.ignore(256, '\n');
            if (idx >= 1 && idx <= (int)table.size()) {
                deleteT(idx - 1);
                saveToFile();
                cout << "Task removed.\n";
            }
            else {
                cout << "Invalid number.\n";
            }
            Sleep(800);
            break;
        }

        default:
            break;
        }
    }

    return 0;
}
