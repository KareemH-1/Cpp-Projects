#include <iostream>
using namespace std;

int countrep(char arr[], char y[]) {
    int count = 0;
    int arraylength = 0;

    for (int i = 0; arr[i] != '\0'; i++) {
        arraylength++;
    }

    int lengthword = 0;

    for (int i = 0; y[i] != '\0'; i++) {
        lengthword++;
    }

    for (int i = 0; i < arraylength; i++) {
        if (i == 0 || arr[i - 1] == ' ') {
            int j = 0;
            int start = i;

            while (arr[i] == y[j] && y[j] != '\0') {
                i++;
                j++;
            }

            if (j == lengthword && (arr[i] == ' ' || arr[i] == '\0')) {
                count++;
            }

            i = start;
        }
    }

    return count;
}

int main() {
    char arr[500];
    
    for (;;) {
        cout << "This program will count the number of times a word is repeated in an array of characters." << endl;
        cout << "-----------------" << endl;
        cout << "Enter 0 to exit or Enter 1 to continue: ";
        int choice;
        cin >> choice;
        
        if (choice == 0) {
            break;
        } else if (choice == 1) {
            cout << "-----------------" << endl;
            cout << "Please enter the values for the array: ";
            cin.ignore();
            gets_s(arr, 500);
            
            cout << endl << "-----------------" << endl;
            char y[100];
            cout << "Please enter the word to search for its repetition: ";
            gets_s(y, 100);
            
            cout << "-----------------" << endl;
            cout << "The word is repeated " << countrep(arr, y) << " times." << endl;
            cout << "================================================================" << endl <<endl;
        }
    }
}
