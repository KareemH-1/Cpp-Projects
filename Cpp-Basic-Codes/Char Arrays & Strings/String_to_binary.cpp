#include <iostream>
using namespace std;

int main() {
    string input;
    cout << "Enter a string: ";
    cin>> input;
    
    //find the length of the string
    int length = 0;
    for(;input[length] != '\0';) {
        length++;
    }

    for (int i = 0; i < length; i++) {
        char ch = input[i];  // Get the current character
        int asciiValue = int(ch);  // Get ASCII value of the character

        // Convert the ASCII value to binary using modulus and division
        for (int j = 7; j >= 0; j--) {  // We need 8 bits for each character
            int bit = asciiValue % 2;   // Get the least significant bit (0 or 1)
            cout << bit; 
            asciiValue = asciiValue / 2;  // Divide the number by 2 to get the next bit
        }

        cout << " ";  // Print a space between binary values of each character
    }
    cout << endl;
}
