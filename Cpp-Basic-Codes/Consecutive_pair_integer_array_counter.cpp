#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the values of the elements of the array: ";
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int count = 0;
    for(int i = 0; i < n-1; i++) {
        if(arr[i] == arr[i+1]) {
            count++;
        }
    }
    cout << "===============================================" << endl;
    cout << "Number of consecutive repeated numbers: "<<count << endl;
}