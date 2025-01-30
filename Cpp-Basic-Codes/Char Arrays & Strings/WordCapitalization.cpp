#include <iostream>
using namespace std;

void capitalize(char X[]) {
   for (int i=0; X[i] != '\0'; i++) {
       if (X[i] >= 'a' && X[i] <= 'z') {
           X[i] = X[i] - 32;
       }
   }
}

int main() {
    char X[100];
    cout << "Enter a string: ";
    gets(X);
    capitalize(X);
    cout << "After whole capitalization: ";
    cout << X << endl;
}