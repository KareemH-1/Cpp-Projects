#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Student {
    string name;
    string id;
    string year;
    float gpa;
    string courses;
};

vector<Student> students;
char default_file_path[] = "Files/Student_DataBase/database.txt";

void loadStudents(string& file_path) {
    ifstream file(file_path);
    if (!file) {
        cout << "Error: File not found at '" << file_path << "'.\n";
        return;
    }
    students.clear();
    string line;
    while (getline(file, line)) {
        Student s;
        int pos = 0;
        pos = line.find(" | "); s.name = line.substr(0, pos); line.erase(0, pos + 3);
        pos = line.find(" | "); s.id = line.substr(0, pos); line.erase(0, pos + 3);
        pos = line.find(" | "); s.year = line.substr(0, pos); line.erase(0, pos + 3);
        pos = line.find(" | "); s.gpa = stof(line.substr(0, pos)); line.erase(0, pos + 3);
        s.courses = line;
        students.push_back(s);
    }
    file.close();
}

void saveStudents(string& file_path) {
    ofstream file(file_path);
    if (!file) {
        cout << "Error: Could not open file for writing.\n";
        return;
    }
    for (int i = 0; i < students.size(); i++) {
        string student_data = students[i].name + " | " + students[i].id + " | " + students[i].year + " | " + to_string(students[i].gpa) + " | " + students[i].courses + "\n";
        file.write(&student_data[0], student_data.length());
    }
    file.close();
}

void addStudent(string &file_path) {
    Student s;
    
    cout << "Enter student name: ";
    cin.ignore();
    getline(cin, s.name);
    
    cout << "Enter student ID: "; cin >> s.id;
    cout << "Enter year: "; cin >> s.year;
    cout << "Enter GPA: "; cin >> s.gpa;
    
    cout << "Enter courses: ";
    cin.ignore();
    getline(cin, s.courses);
    
    students.push_back(s);
    saveStudents(file_path);
    cout << "Student added successfully!\n";
}

void sortStudents(int option) {
    for (int i = 0; i < students.size() - 1; i++) {
        for (int j = 0; j < students.size() - i - 1; j++) {
            bool shouldSwap = false;
            if (option == 1 && students[j].gpa < students[j + 1].gpa) shouldSwap = true;
            else if (option == 2 && students[j].id > students[j + 1].id) shouldSwap = true;
            else if (option == 3 && students[j].id < students[j + 1].id) shouldSwap = true;
            else if (option == 4 && students[j].name > students[j + 1].name) shouldSwap = true;
            else if (option == 5 && students[j].year > students[j + 1].year) shouldSwap = true;
            if (shouldSwap) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void displayStudents() {
    if (students.empty()) {
        cout << "No students available.\n";
        return;
    }
    
    int choice;
    cout << "\nDisplay Options:\n";
    cout << "1. Greatest GPA\n";
    cout << "2. ID (Ascending)\n";
    cout << "3. ID (Descending)\n";
    cout << "4. Name (Alphabetically)\n";
    cout << "5. Year\n";
    cout << "6. Search by Course\n";
    cout << "7. Search by Year\n";
    cout << "8. Search by Name\n";
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore();
    
    if (choice >= 1 && choice <= 5) {
        sortStudents(choice);
    } else if (choice == 6 || choice == 7 || choice == 8) {
        string search;
        cout << "Enter search term: ";
        getline(cin, search);
        int count = 0;
        for (int i = 0; i < students.size(); i++) {
            bool found = false;
            for (int j = 0; j < students[i].courses.size(); j++) {
                if (students[i].courses[j] == search[0]) {
                    found = true;
                    for (int k = 1; k < search.size(); k++) {
                        if (j + k >= students[i].courses.size() || students[i].courses[j + k] != search[k]) {
                            found = false;
                            break;
                        }
                    }
                    if (found) break;
                }
            }
            if ((choice == 6 && found) ||
                (choice == 7 && students[i].year == search) ||
                (choice == 8 && students[i].name == search)) {
                cout << students[i].name << " | " << students[i].id << " | " << students[i].year << " | " << students[i].gpa << " | " << students[i].courses << endl;
                count++;
            }
            if(!found){
                cout << "No students found.\n";
            }
        }
        cout << "Total found: " << count << "\n";
        return;
    }
    cout << "\nStudents:\n--------------------------\n";
    for (int i = 0; i < students.size(); i++) {
        cout << students[i].name << " | " << students[i].id << " | " << students[i].year << " | " << students[i].gpa << " | " << students[i].courses << endl;
    }
}

void removeStudent(string& file_path) {
    string id;
    cout << "Enter student ID to remove: "; cin >> id;
    vector<Student> updated_students;
    for (int i = 0; i < students.size(); i++) {
        if (students[i].id != id) {
            updated_students.push_back(students[i]);
        }
    }
    if (updated_students.size() != students.size()) {
        students = updated_students;
        saveStudents(file_path);
        cout << "Student removed successfully!\n";
    }
    else {
        cout << "Student ID not found.\n";
    }
}

int main() {
    string file_path;
    cout << "Enter the text file path (press Enter to use the default path): ";
    getline(cin, file_path);
    if (file_path.empty()) file_path = default_file_path;
    loadStudents(file_path);

    int choice = -1;
    while (choice != 0) {
        cout << "\nMenu:\n------\n0. Exit\n1. Add a student\n2. Display students\n3. Remove a student\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
        case 0: cout << "Goodbye!\n"; break;
        case 1: addStudent(file_path); break;
        case 2: displayStudents(); break;
        case 3: removeStudent(file_path); break;
        default: cout << "Invalid choice. Please try again.\n"; break;
        }
    }
}
