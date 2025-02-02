#include <iostream>
using namespace std;

void decimalToBinary(int n) {
    int binary[8];  // Array to store binary digits
    int i = 0;

    // Convert the number to binary by dividing by 2
    for (i = 0; i < 8; i++) {
        binary[i] = n % 2;  // Store remainder , 1 or 0
        n = n / 2;          // Divide by 2
    }

    // Print binary digits from the last stored to the first
    cout << "Binary: ";
    for (int j = 7; j >= 0; j--) {
        cout << binary[j];  // Print binary from left to right
    }
    cout << endl;
}

int main() {
    int num;
    cout << "Enter a decimal number (0-255): ";
    cin >> num;

    if (num < 0 || num > 255) {
        cout << "Please enter a number between 0 and 255.";
    }

    decimalToBinary(num);
}
