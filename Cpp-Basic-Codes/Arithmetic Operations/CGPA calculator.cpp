#include <iostream>
using namespace std;

double convertToGradePoint(string grade) {
    if (grade == "A") {
        return 4.0;
    }
    else if (grade == "A-") {
        return 3.67;
    }
    else if (grade == "B+") {
        return 3.33;
    }
    else if (grade == "B") {
        return 3.0;
    } 
    else if (grade == "B-") {
        return 2.67;
    }
    else if (grade == "C+") {
        return 2.33;
    }
    else if (grade == "C") {
        return 2.0;
    }
    else if (grade == "C-") {
        return 1.67;
    }
    else if (grade == "D+") {
        return 1.33;
    }
    else if (grade == "D") {
        return 1.0;
    } 
    else {
        return 0.0; // F grade
    }
}

int main() {
    cout << "CGPA Calculator" << endl;
    cout << "-----------------" << endl;
    cout << "1. Enter (1) for detailed calculation (grades & credit hours for each subject)." << endl;
    cout << "2. Enter (2) for quick input (overall GPA & credit hours per semester)." << endl;

    int choice;
    cin >> choice;

    if (choice == 1) {
        int semester = 1;
        double totalGrades = 0;
        double totalCreditHours = 0;

        while (true) {
            cout << "-----------------" << endl;
            int choice2;
            cout << "Enter 0 to exit or Enter 1 to continue: ";
            cin >> choice2;

            if (choice2 == 0) {
                break;
            }
            else{
            cout << "Enter the number of subjects for semester " << semester << ": ";
            int numSubjects;
            cin >> numSubjects;

            for (int i = 0; i < numSubjects; i++) {
                cout << "Enter the grade for subject " << i + 1 << ": ";
                string grade;
                cin >> grade;

                cout << "Enter the credit hours for subject " << i + 1 << ": ";
                double creditHours;
                cin >> creditHours;

                double gradePoint = convertToGradePoint(grade);
                totalGrades += gradePoint * creditHours;
                totalCreditHours += creditHours;
            }

            semester++;
        }
    }

        if (totalCreditHours > 0) {
            double cgpa = totalGrades / totalCreditHours;
            cout << "Your final CGPA is: " << cgpa << endl;
        } else {
            cout << "No subjects entered. Cannot calculate CGPA." << endl;
        }
    }

    else if (choice == 2) {
        double totalGrades = 0;
        double totalCreditHours = 0;
        int semester = 1;
        while(true){
            int choice2;
            cout << "Enter (1) to continue adding semester grades or enter (0) to stop: ";
            cin >> choice2;
            
            if (choice2 == 0){
                break;
            }

            else if (choice2 == 1) {
                cout <<"Enter the GPA for semester " << semester << ": ";
                double gpa;
                cin >> gpa;

                cout << "Enter the credit hours for semester " << semester << ": ";
                double creditHours;
                cin >> creditHours;
                totalGrades += gpa * creditHours;
                totalCreditHours += creditHours;
                semester++;
            }
        }
        if (totalCreditHours > 0) {
            double cgpa = totalGrades / totalCreditHours;
            cout << "Your final CGPA is: " << cgpa << endl;
        } else {
            cout << "No subjects entered. Cannot calculate CGPA." << endl;
        }
    }   
}