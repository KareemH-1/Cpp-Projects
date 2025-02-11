#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n], largest, smallest;
    cout << "Enter the numbers in the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    largest = -99999999999;
    smallest = 99999999999;
    int poslargest, possmallest;
    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
            poslargest = i;
        }
        if (arr[i] < smallest) {
            smallest = arr[i];
            possmallest = i;
        }
    }
    cout << "The largest number is: " << largest  << " and its position in the array is " << poslargest << endl;
    cout << "The smallest number is: " << smallest << " and its position in the array is " << possmallest<< endl;
}