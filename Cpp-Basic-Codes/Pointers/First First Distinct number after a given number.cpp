#include <bits/stdc++.h>
using namespace std;

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    int outputy;
    int len;
    int isdistinct = 0;

    for (int i = num + 1; ; i++) {
        len = 0;
        int temp = i;

        for (int j = temp; j > 0; j /= 10) {
            len++;
        }

        int* digits = new int[len];
        temp = i;

        for (int j = len - 1; j >= 0; j--) {
            digits[j] = temp % 10;
            temp /= 10;
        }

        isdistinct = 1;
        for (int j = 0; j < len; j++) {
            for (int k = j + 1; k < len; k++) {
                if (digits[j] == digits[k]) {
                    isdistinct = 0;
                    break;
                }
            }
            if (!isdistinct) break;
        }

        delete[] digits;

        if (isdistinct) {
            outputy = i;
            break;
        }
    }

    cout << outputy << "is the first distinct number after " << num << ".";
}
