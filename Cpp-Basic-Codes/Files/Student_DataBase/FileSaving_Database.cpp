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

void displayStudents() {
    if (students.empty()) {
        cout << "No students available.\n";
        return;
    }
    cout << "\nStudents:" << endl << "--------------------------" <<endl;
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
        cout << "\nMenu:\n------\n0. Exit\n1. Add a student\n2. Display all students (sorted by GPA)\n3. Remove a student\nEnter your choice: ";
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
