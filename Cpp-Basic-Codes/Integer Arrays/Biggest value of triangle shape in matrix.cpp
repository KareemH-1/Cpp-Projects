#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of the matrix: ";
    cin >> n;

    int matrix[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    int maxSum = 0;
    int bestRow = -1, bestCol = -1, bestSize = -1;


    for (int sizeBase = 3; sizeBase < n; sizeBase += 2) {

        int height = (sizeBase - 1) / 2;  
        for (int i = 0; i + height < n; i++) { 
            for (int j = 0; j + sizeBase <= n; j++) {

                int sum = 0;
                int center = j + sizeBase / 2;

                for (int q = 0; q <= height; q++) {
                    int left = center - q;
                    int right = center + q;


                    if (left >= 0 && right < n) {
                        for (int col = left; col <= right; col++) {
                            sum += matrix[i + q][col];
                        }
                    }
                }


                if (sum > maxSum) {
                    maxSum = sum;
                    bestRow = i;
                    bestCol = j;
                    bestSize = sizeBase;
                }
            }
        }
    }

    cout << "Max Triangle Sum: " << maxSum << endl;
    cout << "Top-left corner of base: (" << bestRow << ", " << bestCol << ")" << endl;
    cout << "Base size: " << bestSize << endl;
}
