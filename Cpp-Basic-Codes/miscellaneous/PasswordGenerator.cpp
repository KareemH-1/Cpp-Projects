#include<bits/stdc++.h>
using namespace std;

int main() {
    srand(time(0));
    int length;
    cout << "Enter the length of the password: ";
    cin >> length;

    bool includeUppercase, includeLowercase, includeNumbers, includeSymbols;
    cout << "Include uppercase letters? (1 for yes, 0 for no): ";
    cin >> includeUppercase;
    cout << "Include lowercase letters? (1 for yes, 0 for no): ";
    cin >> includeLowercase;
    cout << "Include numbers? (1 for yes, 0 for no): ";
    cin >> includeNumbers;
    cout << "Include symbols? (1 for yes, 0 for no): ";
    cin >> includeSymbols;

    if (!includeUppercase && !includeLowercase && !includeNumbers && !includeSymbols) {
        cout << "Error: You must include at least one character set!" << endl;
        return 1;
    }

    char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
    char numbers[] = "0123456789";
    char symbols[] = "!@#$%^&*()_+-=:,.<>?";

    string possibilities = "";
    if (includeUppercase) possibilities += uppercase;
    if (includeLowercase) possibilities += lowercase;
    if (includeNumbers) possibilities += numbers;
    if (includeSymbols) possibilities += symbols;

    char* password = new char[length + 1];

    for (int i = 0; i < length; i++) {
        int randomIndex = rand() % possibilities.length();
        password[i] = possibilities[randomIndex];
    }

    password[length] = '\0';

    cout << "The generated password is: " << password << endl;

    delete[] password;
}