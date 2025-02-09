//Generate Fibonacci numbers up to an input number.
#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter the number of Fibonacci numbers to generate: ";
    cin >> n;
    int a = 0, b = 1;
    cout << "Fibonacci sequence: " << a << " " << b;
    for (int i = 2; i < n; i++) {
        int next = a + b;
        cout << " " << next;
        a = b;
        b = next;
    }
}