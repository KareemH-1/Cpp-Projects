#include <iostream>

using namespace std;

// Function to convert marks to GPA directly
double convertToGradePoint(double marks, double maxMarks) {
    return ((marks / maxMarks) * 4);
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

        // Calculate grade point using the formula (marks/maxMarks) * 4
        double gradePoint = convertToGradePoint(marks, maxMarks);  

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

    return 0;
}
