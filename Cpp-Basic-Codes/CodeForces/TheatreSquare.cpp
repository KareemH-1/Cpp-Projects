#include <iostream>
 
using namespace std;
 
int main() {
    long long n, m, a;
    cin >> n >> m >> a;
 
    long long length, width;
    long long total =0;
 
    if (n % a == 0) {
        length = n / a;
    }
    else {
        length = (n / a) + 1;
    }
 
    if (m % a == 0) {
        width = m / a;
    }
    else {
        width = (m / a) + 1;
    }
 
    total = length * width;
 
    cout << total << endl;
}