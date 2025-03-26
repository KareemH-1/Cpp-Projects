// This code lets the user input a matrix size then finds a square of -1's and copies whats before them in each row to another matrix and displays input
#include <bits/stdc++.h>
using namespace std;


int main() {
	int n;
	cin >> n;

	int** x = new int* [n];

	for (int i = 0; i < n; i++) {
		x[i] = new int[n];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> x[i][j];
		}
	}
	int ct = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != n - 1 && j!= n - 1) {
				if (x[i][j] == -1 && x[i][j + 1] == -1 && x[i + 1][j] ==-1 && x[i + 1][j + 1] ==-1) {
					ct++;
				}
			}
		}
	}
	
	int** y = new int* [ct * 2];
	int *size = new int[ct * 2];

	int k = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != n - 1 && j != n - 1) {
				if (x[i][j] == -1 && x[i][j + 1] == -1 && x[i + 1][j] == -1 && x[i + 1][j + 1] == -1) {
					size[k] = j;
					size[k + 1] = j;
					for (int a = 0; a < 2; a++) {
						y[k] = new int[j];
						for (int b = 0; b < j; b++) {
							if (a == 0) {
								y[k][b] = x[i][b];
							}
							else {
								y[k][b] = x[i + 1][b];
							}
						}
						k++;
					}
				}
			}
		}
	}

	for (int i = 0; i < ct * 2; i++) {
		for (int j = 0; j < size[i]; j++) {
			cout << y[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < n; i++) {
		delete[] x[i];
	}
	delete[] x;
	for (int i = 0; i < ct * 2; i++) {
		delete[] y[i];
	}
	delete[] y;
	delete[] size;


}

