#include <iostream>
using namespace std;

void capitalize(char X[]) {
       if (X[0] >= 'a' && X[0] <= 'z') {
           X[0] = X[0] - 32;
       }
}

int main() {
    char X[100];
    cout << "Enter a string: ";
    gets(X);
    capitalize(X);
    cout << "After capitalization: ";
    cout << X << endl;
}