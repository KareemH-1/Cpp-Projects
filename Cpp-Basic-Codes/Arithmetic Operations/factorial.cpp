#include<iostream>
using namespace std;

int factorial(int n) {
    int result = 1;
    for (int i = n; i > 0; i--) {
        result *= i; 
    }
    return result; 
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Factorial of the number " << n << " is " << factorial(n) << endl;
}