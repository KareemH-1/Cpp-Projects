#include <iostream>
using namespace std;

int sumOfDigits(int n) {
    int sum = 0;
    for(;n > 0;) {
        sum += n % 10;
        n /= 10;
    }
    return (sum);
}

int main() {
    int n;
     cout << "Enter a number: ";
    cin >> n;
    cout << "Sum of digits of the number " << n << " is " << sumOfDigits(n) << endl;
}