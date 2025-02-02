#include <iostream>
 
using namespace std;
 
int main() {
    long long n, m, a;  //used long long to hold bigger numbers as specified in the question
    cin >> n >> m >> a;
 
    long long length, width;
    long long total =0;
 
    // If n is not divisible by a, we need one extra flagstone to cover the remainder
    if (n % a == 0) {
        length = n / a;
    } else {
        length = (n / a) + 1; // Round up by adding 1 flagstone
    }

    // If m is not divisible by a, we need one extra flagstone to cover the remainder
    if (m % a == 0) {
        width = m / a;
    } else {
        width = (m / a) + 1; // Round up by adding 1 flagstone
    }

    // Multiply the number of flagstones for length and width to get the total
    total = length * width;

 
    cout << total << endl;
}