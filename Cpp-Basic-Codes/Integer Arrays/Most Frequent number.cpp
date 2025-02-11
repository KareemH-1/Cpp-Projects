#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the numbers in the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int maxCount = 0;
    int mostFrequent;

    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            mostFrequent = arr[i];
        }
    }

    cout << "The most frequent number is: " << mostFrequent << " and it is repeated "<< maxCount << " times." << endl;
}