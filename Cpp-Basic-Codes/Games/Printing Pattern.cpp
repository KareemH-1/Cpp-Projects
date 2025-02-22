#include <iostream>
using namespace std;

int main() {
    long long n;
    cout << "Enter a value to display";
    cin >> n;
    long long size = 2 * n - 1;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int top = i;
            int left = j;
            int right = size - 1 - j;
            int bottom = size - 1 - i;

            int minDist =99999999;
            if (top < minDist) {
                minDist = top;
            }
            if (left < minDist) {
                minDist = left;
            }
            if (right < minDist) {
                minDist = right;
            }
            if (bottom < minDist) {
                minDist = bottom;
            }
            cout << (n - minDist) << " ";
        }
        cout << endl;
    }


}
