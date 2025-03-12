#include <bits/stdc++.h>
using namespace std;

int main() {
	cout << "How many numbers you want to order: ";
	int n;
	cin >> n;
	cout << "Please enter " << n << " unordered numbers: ";
	float * arr = new float[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	cout << "\n";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
    delete [] arr;
}
