#include <iostream>
 
using namespace std;
 
int main() {
	long long n, k; //used long long to hold bigger numbers as specified in the question
	cin >> n >> k;
	long long odd = (n + 1) / 2; // Calculate the number of odd numbers
 
	if (k <= odd) {
    // If k is within the odd numbers
		cout << 2 * k - 1;
	}
	else {
    // If k is within the even numbers
		cout << 2 * (k - odd);
	}
}