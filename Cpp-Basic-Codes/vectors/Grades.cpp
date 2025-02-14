#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> names;
    vector<float> scores;
    int choice = -1; // Initialize to avoid garbage value

    while (choice != 0) {
        cout << "\nMenu: " << endl;
        cout << "------" << endl;
        cout << "0. Exit" <<endl;
        cout << "1. Add a student" <<endl;
        cout << "2. Display all students (sorted by grade)" <<endl;
        cout << "3. Remove a student" <<endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore leftover newline

        if (choice == 1) {
            string name;
            float score;

            cout << "Enter the student's name: ";
            getline(cin, name);

            cout << "Enter the student's grade: ";
            cin >> score;
            cin.ignore(); // Ignore newline after input

            names.push_back(name);
            scores.push_back(score);
        }

        else if (choice == 2) {
            if (names.empty()) {
                cout << "No students to display." <<endl;
            } else {
                for (int i = 0; i < scores.size() - 1; i++) {
                    for (int j = 0; j < scores.size() - 1 - i; j++) {
                        if (scores[j] < scores[j + 1]) { // Sort in descending order (from highest to lowest grades)
                            // Swap grades
                            float tempScore = scores[j];
                            scores[j] = scores[j + 1];
                            scores[j + 1] = tempScore;

                            // Swap corresponding names
                            string tempName = names[j];
                            names[j] = names[j + 1];
                            names[j + 1] = tempName;
                        }
                    }
                }

                cout << "\n Students sorted by grade (Highest to Lowest): " << endl;
                for (int i = 0; i < names.size(); i++) {
                    cout << i + 1 << ". " << names[i] << " : " << scores[i] << endl;
                }
            }
        }

        else if (choice == 3) {
            if (names.empty()) {
                cout << "No students to remove." << endl;
                continue;
            }

            string name;
            cout << "Enter the student's name to remove: ";
            getline(cin, name);

            bool found = false;
            for (int i = 0; i < names.size(); i++) {
                if (names[i] == name) {
                    names.erase(names.begin() + i);
                    scores.erase(scores.begin() + i);
                    found = true;
                    cout << "Student removed successfully." << endl;
                    break;
                }
            }

            if (!found) {
                cout << "Student not found." << endl;
            }
        }

        else if (choice == 0) {
            cout << "Exiting program." <<endl;
        }

        else {
            cout << "Invalid choice! Please try again." <<endl;
        }
    }
}
