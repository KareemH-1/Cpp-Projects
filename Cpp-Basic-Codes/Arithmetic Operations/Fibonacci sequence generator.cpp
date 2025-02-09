#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of Fibonacci numbers to generate: ";
    cin >> n;

    if (n <= 0) {
        cout << "Please enter a positive number." << endl;
        return 0; //exit code if user enters a negative number or zero
    }

    int a = 0, b = 1;
    
     if (n == 1) {
        cout << "Fibonacci sequence: " << a << endl;
        return 0; //exits code if user enters 1 after displaying the first number in sequence (0)
    }

    cout << "Fibonacci sequence: " << a << " " << b;
    
    for (int i = 2; i < n; i++) {
        int next = a + b;
        cout << " " << next;
        a = b;
        b = next;
    }
}