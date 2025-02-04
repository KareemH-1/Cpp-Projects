#include <iostream>
using namespace std;

int main() {
    int numStudents;
    
    // Ask for the number of students
    cout << "Enter number of students: ";
    cin >> numStudents;

    // Declare arrays for storing student names and grades
    string names[numStudents];
    float grades[numStudents];
    
    // Input student names and grades
    for(int i = 0; i < numStudents; i++) {
        cout << "Enter name of student " << i+1 << ": ";
        cin >> names[i];
        cout << "Enter grade for " << names[i] << ": ";
        cin >> grades[i];
    }
    
    // Output the students' names and their grades
    cout << "\nStudent Grades:\n";
    for(int i = 0; i < numStudents; i++) {
        cout << names[i] << ": " << grades[i] << endl;
    }

    // Calculate the average grade
    float sum = 0;
    for(int i = 0; i < numStudents; i++) {
        sum += grades[i];
    }
    float average = sum / numStudents;
    
    // Display the average grade
    cout << "\nAverage Grade: " << average << endl;

    return 0;
}
