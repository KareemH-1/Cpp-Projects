//armstrong number is a number where each of its digits raised to the power of number of digits equals the number , for example: 1^3 + 5^3 + 3^3 = 153
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int number;
    cout << "Please enter the number: ";
    cin >> number;

    int total = 0, count = 0;

     int temp = number;

    // Count the number of digits

    while (temp > 0) {
        temp /= 10;  // Divide by 10 to reduce the number
        count++;     // Increment digit count
    }

    temp = number;  // Reset emp to original number
    // Calculate the sum of each digit raised to the power of 'count'
    for(;temp > 0;) {
        int digit = temp % 10;  // Get the last digit
        total += pow(digit, count);  // Add the digit raised to the power of 'count'
        temp /= 10;  // Remove the last digit
    }

    // Check if the number is an Armstrong number
    if (total == number) {
        cout << "The number you entered (" << number << ") is an Armstrong number." << endl;
    } else {
        cout << "The number you entered (" << number << ") isn't an Armstrong number." << endl;
    }
}
