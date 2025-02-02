#include <iostream>
#include <string>
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
    string subject[numSubjects];
    string grade[numSubjects];
    double gradePoint[numSubjects];
    double marks[numSubjects];
    double creditHours[numSubjects];
    double percentage[numSubjects];

    for (int i = 0; i < numSubjects; i++) {
        cout << endl << "Enter the name for subject " << (i + 1) << ": ";
        cin >> subject[i];  // Get name for the subject
        
        cout << "Enter marks for " << subject[i] << ": ";
        cin >> marks[i];  // Get marks for the subject
        
        cout << "Enter credit hours for this subject: ";
        cin >> creditHours[i];  // Get credit hours for the subject

        // Calculate grade point using the formula (marks/maxMarks) * 4
        gradePoint[i] = convertToGradePoint(marks[i], maxMarks);  

        totalGradePoints += gradePoint[i] * creditHours[i];  // Accumulate total grade points
        totalCredits += creditHours[i];  // Accumulate total credits
    }

    // Check for division by zero (no subjects or credits)
    if (totalCredits == 0) {
        cout << "Total credit hours can't be zero." << endl;
    } else {
        double gpa = totalGradePoints / totalCredits;  // Calculate GPA
        string gradeTotal;
        cout << endl << "Your GPA is: " << gpa << endl;

        // Finding Grade depending on GPA
        if (gpa > 3.7) {
             gradeTotal = "A";
        }
        else if (gpa > 3.3) {
            gradeTotal = "A-";
        }
        else if (gpa > 3.0) {
            gradeTotal = "B+";
        }
        else if (gpa > 2.7) {
            gradeTotal = "B";
        }
        else if (gpa > 2.3) {
            gradeTotal = "B-";
        }
        else if (gpa > 2.0) {
            gradeTotal = "C+";
        }
        else if (gpa > 1.7) {
            gradeTotal = "C";
        }   
        else if (gpa > 1.3) {
            gradeTotal = "C-";
        }
        else if (gpa > 1.0) {
            gradeTotal = "D";
        }
        else {
            gradeTotal = "F";
        }
        cout <<"Your overall grade is: " << gradeTotal << endl;
        cout <<"-----------------------------------------------" <<endl;
    }   

    // Display GPA and Grade for each subject
    for (int i = 0; i < numSubjects; i++) {
        percentage[i] = (marks[i] / maxMarks) *100;      
        
        if (percentage[i] >= 90) {
            grade[i] = "A";
        }
        else if (percentage[i] >= 85) {
            grade[i] = "A-";
        }
        else if (percentage[i] >= 80) {
            grade[i] = "B+";
        }
        else if (percentage[i] >= 75) {
            grade[i] = "B";
        }
        else if (percentage[i]>= 70) {
            grade[i] = "B-";
        }
        else if (percentage[i] >= 65) {
            grade[i] = "C+";
        }
        else if (percentage[i] >= 60) {
            grade[i] = "C";
        }
        else if (percentage[i] >= 55) {
            grade[i] = "C-";
        }
        else if (percentage[i] >= 50) {
            grade[i] = "D";
        }
        else{
            grade[i] = "F";
        }
        cout << "GPA for Subject " << (i + 1) << " (" << subject[i] << "): " << gradePoint[i] << " ,Grade: "<< grade[i] <<endl; 
        if (i!= numSubjects-1){
        cout << "-------------------------------" <<endl;
        }
    }
}
