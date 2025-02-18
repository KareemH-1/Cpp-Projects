#include <iostream>
using namespace std;

int main() {
	int C, Y;
	cout << "Enter number of clubs: ";
	cin >> C;
	cout << "Enter number of years: ";
	cin >> Y;
	int mat[C][Y];
	for (int i = 0; i < C; i++) {
		for (int j = 0; j < Y; j++) {
			cout << "Enter rank of year " << j+1 << " for club number " << i+1<< ": ";
			cin >> mat[i][j];
			for (;;) {
				if (mat[i][j] <= 0) {
					cout << "Invalid input. try again! \n" << "Enter rank of year " << j+1 << " for club number " << i+1 << ": ";
					cin >> mat[i][j];
				}
				else if (mat[i][j] > C) {
					cout << "Invalid rank. try again! \n" << "Enter rank of year " << j + 1 << " for club number " << i + 1 << ": ";
					cin >> mat[i][j];
				}
				else {
					break;
				}
			}
		}
		cout << endl;
	}

	int selectClub;
	cout << "Enter a club: ";
	cin >> selectClub;
	for (;;) {
		if (selectClub > C || selectClub < 0) {
			cout << "Invalid input. try again! \n" << "Select a club again: ";
			cin>> selectClub;
		}
		else {
			break;
		}
	}
	
	int max = 99999999;
	int posmax;
	for (int j = 0; j < Y; j++) {
		if (mat[selectClub][j] < max) {
			max = mat[selectClub][j];
			posmax = j;
		}
	}

	cout << "The maximum rank of club " << selectClub << " is " << max << " and was achieved on year " << posmax+1 << endl;

	for (int i = 0; i < C; i++) {
		int count = 0;
		for (int j = 0; j < Y; j++) {

			if (mat[i][j] == 1) {
				count++;
			}
		}
		if (count == 1) {
			cout << "Club " << i+1 << " got first rank " << count << " time" <<endl;
		}
		else if (count == 1) {
			cout << "Club " << i+1 << " got first rank " << count << " times" <<endl;
		}
	}

	int max2=-9999999999;
	int posmax2;
	for (int i = 0; i < C; i++) {
		int count = 0;
		for (int j = 0; j < Y; j++) {
			if (mat[i][j] == 1) {
				count++;
			}
		}
		if (count > max2) {
			max2 = count;
			posmax2 = i;
		}
	}

	cout << "Club of the century is club " << posmax2+1 << " and it achieved " << max2 << " 1st place wins.";

}