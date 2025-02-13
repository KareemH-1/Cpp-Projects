#include <iostream>
using namespace std;

int main() {
    int arr[3][3], transpose[3][3];

    cout << "Enter the elements of the matrix: " << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }

    // Transposing into a new matrix
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            transpose[j][i] = arr[i][j]; // Swapping row and column
        }
    }

    // Printing the transposed matrix
    cout << "The Transpose of the matrix is: " <<endl << endl;
    for (int i = 0; i < 3; i++) {
        cout << " | ";
        for (int j = 0; j < 3; j++) {
            cout << transpose[i][j] << " ";
        }
        cout <<"|"<< endl;
    }
}
