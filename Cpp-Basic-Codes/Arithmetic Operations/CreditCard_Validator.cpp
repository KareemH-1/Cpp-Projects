#include <iostream>
#include <string>

using namespace std;

bool validateCreditCard(string& cardNumber) {
    int sum = 0;
    bool doubleDigit = false;

    for (int i = cardNumber.length() - 1; i >= 0; i--) {
        int digit = cardNumber[i] - 48;  // 48 is the ascii value of 0 , since the number will be a string , it still needs to be converted to an integer number by subtracting it with 48 (48 for zero , 49 for 1 , 50 for 2 and so on..)

        if (doubleDigit == true) {
            digit *= 2;
            if (digit > 9) {
                digit -= 9;
            }
        }

        sum += digit;
        doubleDigit = !doubleDigit;
    }

     if(sum % 10 == 0){
        return true;
     }
     else {
        return false;
     }
}

int main() {
    string cardNumber;
    cout << "Enter the credit card number: ";
    cin >> cardNumber;

    if (validateCreditCard(cardNumber) == true) {
        cout << "Valid credit card number!" << endl;
    } else {
        cout << "Invalid credit card number!" << endl;
    }
}
