#include <iostream>
#include <ctime>

using namespace std;

// Function to display the game rules
void displayRules() {
    cout << "========================================" << endl;
    cout << "            NUMBER PUZZLE GAME          " << endl;
    cout << "========================================" << endl;
    cout << " Rules: " << endl;
    cout << " - The numbers are arranged in a grid with one empty space (0)." << endl;
    cout << " - Your goal is to arrange the numbers in order from 0 to N*N - 1." << endl;
    cout << " - You can move the empty space by entering one of the following:" << endl;
    cout << "   1. Up (Move zero up)" << endl;
    cout << "   2. Down (Move zero down)" << endl;
    cout << "   3. Left (Move zero left)" << endl;
    cout << "   4. Right (Move zero right)" << endl;
    cout << " - The game starts at level 2 and increases when you complete a level." << endl;
    cout << "========================================" << endl;
}

// Function to display the grid
void display(int arr[][10], int level) {
    cout << "\n-------------------" << endl;
    for (int i = 0; i < level; i++) {
        for (int j = 0; j < level; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << "-------------------\n";
}

// Function to check if the grid is sorted in ascending order
bool isSorted(int arr[][10], int level) {
    int expected = 0;
    for (int i = 0; i < level; i++) {
        for (int j = 0; j < level; j++) {
            if (arr[i][j] != expected) {
                return false;
            }
            expected++;
        }
    }
    return true;
}

// Function to fill the grid with random unique numbers
void randomFilling(int arr[][10], int level) {
    int used[100] = { 0 };
    int num, unique;

    for (int i = 0; i < level; i++) {
        for (int j = 0; j < level; j++) {
            unique = 0;
            while (unique == 0) {
                num = rand() % (level * level);
                if (used[num] == 0) {
                    unique = 1;
                    used[num] = 1;
                }
            }
            arr[i][j] = num;
        }
    }
}

// Function to increment level when a level is completed
void incrementLvl(int arr[][10], int& level) {
    if (isSorted(arr, level) && level < 10) {
        cout << "You win!\nScore: " << level - 1 << "\n";
        level++;
        randomFilling(arr, level);
    }
}

// Function to move zero in the grid
void move(int arr[][10], int level) {
    int posZI = -1, posZJ = -1;

    // Find position of zero
    for (int i = 0; i < level; i++) {
        for (int j = 0; j < level; j++) {
            if (arr[i][j] == 0) {
                posZI = i;
                posZJ = j;
            }
        }
    }

    string choice;
    cout << "Enter direction to move zero: \n";
    cout << "1. Up\n2. Down\n3. Left\n4. Right\n";
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
    else {
        cout << "Invalid move. Try again.\n";
    }
}

int main() {
    srand(time(0));

    displayRules(); // Show game rules at the beginning

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
