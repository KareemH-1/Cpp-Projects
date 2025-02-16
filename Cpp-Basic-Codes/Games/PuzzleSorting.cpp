#include <iostream>
#include <ctime>

using namespace std;

void display(int arr[][10], int level) {
    cout << endl << "-------------------" <<endl;
    for (int i = 0; i < level; i++) {
        for (int j = 0; j < level; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << "-------------------"<<endl;
}

bool isSorted(int arr[][10], int level) {
    int expected = 0; // Start from 0

    for (int i = 0; i < level; i++) {
        for (int j = 0; j < level; j++) {
            if (arr[i][j] != expected) {
                return false; // If it's not in order, return false
            }
            expected++; // Increase expected number
        }
    }
    return true; // If loop completes, it's sorted
}

void randomFilling(int arr[][10], int level) {
    int used[100] = { 0 }; // Track used numbers
    int num, unique;

    for (int i = 0; i < level; i++) {
        for (int j = 0; j < level; j++) {
            unique = 0;
            while (unique == 0) {
                num = rand() % (level * level);
                if (used[num] == 0) { // Check uniqueness
                    unique = 1;
                    used[num] = 1;
                }
            }
            arr[i][j] = num;
        }
    }
}

void incrementLvl(int arr[][10], int& level) {
    if (isSorted(arr, level) && level < 10) {
        cout << "You win! \nScore: " << level - 1 << endl;
        level++;
        randomFilling(arr, level);
    }
}

void move(int arr[][10], int level) {
    int posZI = -1, posZJ = -1;

    for (int i = 0; i < level; i++) {
        for (int j = 0; j < level; j++) {
            if (arr[i][j] == 0) {
                posZI = i;
                posZJ = j;
            }
        }
    }

    string choice;
    cout << "Enter direction to move zero: \n1. Up \n2. Down \n3. Left \n4. Right" << endl;
    cin >> choice;

    if ((choice == "Up" || choice == "up" || choice == "u" || choice == "U" || choice == "1") && posZI > 0) {
        arr[posZI][posZJ] = arr[posZI - 1][posZJ];
        arr[posZI - 1][posZJ] = 0;
    }
    else if ((choice == "Down" || choice == "down" || choice == "d" || choice == "D" || choice == "2") && posZI < level - 1) {
        arr[posZI][posZJ] = arr[posZI + 1][posZJ];
        arr[posZI + 1][posZJ] = 0;
    }
    else if ((choice == "Left" || choice == "left" || choice == "l" || choice == "L" || choice == "3") && posZJ > 0) {
        arr[posZI][posZJ] = arr[posZI][posZJ - 1];
        arr[posZI][posZJ - 1] = 0;
    }
    else if ((choice == "Right" || choice == "right" || choice == "r" || choice == "R" || choice == "4") && posZJ < level - 1) {
        arr[posZI][posZJ] = arr[posZI][posZJ + 1];
        arr[posZI][posZJ + 1] = 0;
    }
}

int main() {
    srand(time(0));

    int level = 2;
    int arr[10][10] = { 0 };

    randomFilling(arr, level);

    while (!isSorted(arr, level)) {
        display(arr, level);
        move(arr, level);
        incrementLvl(arr, level);
    }

    cout << "Congratulations! You completed all levels!\n";
}
