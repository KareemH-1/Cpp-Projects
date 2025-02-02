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
}

int main() {
    int numSubjects;
    cout << "Enter number of subjects: ";
    cin >> numSubjects;

    double maxMarks;
    cout << "Enter maximum marks for the subjects: ";
    cin >> maxMarks;

    double totalGradePoints = 0, totalCredits = 0;

    for (int i = 0; i < numSubjects; i++) {
        double marks, creditHours;
        cout << endl << "Enter marks obtained for subject " << (i + 1) << ": ";
        cin >> marks;
        cout << "Enter credit hours for this subject: ";
        cin >> creditHours;
        cout << "-------------------------------------------" << endl;
        double percentage = (marks / maxMarks) * 100;
        double gradePoint = convertToGradePoint(percentage);

        totalGradePoints += gradePoint * creditHours;
        totalCredits += creditHours;
    }

    if (totalCredits == 0) {
        cout << "total credit hours cant be equal to zero" << endl;
    }
    else {
        double gpa = totalGradePoints / totalCredits;
        cout << endl << "Your GPA is: " << gpa << endl;
    }


}
