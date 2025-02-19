#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of the matrix: ";
    cin >> n;

    int matrix[n][n];
    cout << "Enter the elements of the matrix: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

     // Variables to store the maximum triangle sum and its position
     int maxSum = 0;
     int bestRow = -1, bestCol = -1, bestSize = -1;
 
     // go over possible triangle base sizes (only odd sizes from 3 to 19)
     for (int sizeBase = 3; sizeBase <= 19; sizeBase += 2) {
         
         int height = (sizeBase - 1) / 2;  // Calculate the height of each size
         
         // go through all possible top positions of the triangle
         for (int i = 0; i + height < 20; i++) {
             for (int j = 0; j + sizeBase <= 20; j++) {
 
                 int sum = 0;  // Variable to store the current triangle sum
                 int center = j + sizeBase / 2;  // Calculate the center column of the base
 
                 // Iterate over the rows of the triangle
                 for (int q = 0; q <= height; q++) {
                     int left = center - q;  // left of the current row
                     int right = center + q; // right of the current row
 
                     // Ensure boundaries are within the matrix
                     if (left >= 0 && right < 20) {
                         for (int col = left; col <= right; col++) {
                             sum += matrix[i + q][col];  // Add values to the sum
                         }
                     }
                 }
 
                 // Update maximum sum and store the best triangle position
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
 