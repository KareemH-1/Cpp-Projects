#include <iostream>
#include <string>

using namespace std;

// Function to validate the credit card using the Luhn algorithm
bool validateCreditCard(string& cardNumber) {
    int sum = 0; 
    bool doubleDigit = false;  // Flag to track whether we should double the digit

    // Loop through the card number from right to left
    for (int i = cardNumber.length() - 1; i >= 0; i--) {
        int digit = cardNumber[i] - 48;  // 48 is the ascii value of 0 , since the number will be a string , it still needs to be converted to an integer number by subtracting it with 48 (48 for zero , 49 for 1 , 50 for 2 and so on..)


        // If the current digit should be doubled
        if (doubleDigit == true) {
            digit *= 2;  // Double the digit
            if (digit > 9) {
                digit -= 9;  // If doubling results in a number > 9, subtract 9
            }
        }

        sum += digit;  // Add the digit to the sum
        doubleDigit = !doubleDigit;  // Alternate the doubleDigit flag (true to false and false to true)
    }

    // Check if the sum is divisible by 10 (Luhn's algorithm)
    if (sum % 10 == 0) {
        return true;  // Valid card number
    } else {
        return false;  // Invalid card number
    }
}

int main() {
    string cardNumber;  // Variable to store the user's credit card number
    cout << "Enter the credit card number: "; 
    cin >> cardNumber;

    // Check if the entered card number is valid
    if (validateCreditCard(cardNumber) == true) {
        cout << "Valid credit card number!" << endl;  // Output if valid
    } else {
        cout << "Invalid credit card number!" << endl;  // Output if invalid
    }
}
