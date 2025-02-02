#include <iostream>

using namespace std;

// Function to convert percentage to a 4.0 scale
double convertToGradePoint(double percentage) {
    if (percentage >= 90) {
        return (4.0);
    }
    else if (percentage >= 85) {
        return (3.7);
    }
    else if (percentage >= 80) {
        return (3.3);
    }
    else if (percentage >= 75) {
        return (3.0);
    }
    else if (percentage >= 70) {
        return (2.7);
    }
    else if (percentage >= 65) {
        return (2.3);
    }
    else if (percentage >= 60) {
        return (2.0);
    }
    else if (percentage >= 55) {
        return (1.7);
    }
    else if (percentage >= 50) {
        return (1.0);
    }
    else{
        return(0); //failing grade
    }
}

int main() {
    int numSubjects;  
    cout << "Enter number of subjects: ";
    cin >> numSubjects;  // Get the number of subjects

    double maxMarks;
    cout << "Enter maximum marks for the subjects: ";
    cin >> maxMarks;  // Get the maximum marks for the subjects

    double totalGradePoints = 0, totalCredits = 0;

    for (int i = 0; i < numSubjects; i++) {
        double marks, creditHours;
        cout << endl << "Enter marks for subject " << (i + 1) << ": ";
        cin >> marks;  // Get marks for the subject
        cout << "Enter credit hours for this subject: ";
        cin >> creditHours;  // Get credit hours for the subject

        double percentage = (marks / maxMarks) * 100;  // Calculate percentage for the subject
        double gradePoint = convertToGradePoint(percentage);  // Convert percentage to GPA

        totalGradePoints += gradePoint * creditHours;  // Accumulate total grade points
        totalCredits += creditHours;  // Accumulate total credits
    }

    // Check for division by zero (no subjects or credits)
    if (totalCredits == 0) {
        cout << "Total credit hours can't be zero." << endl;
    } else {
        double gpa = totalGradePoints / totalCredits;  // Calculate GPA
        cout << endl << "Your GPA is: " << gpa << endl; 
    }
}