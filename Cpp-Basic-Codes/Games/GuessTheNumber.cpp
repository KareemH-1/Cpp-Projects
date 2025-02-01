#include <iostream>
#include <string>
using namespace std;

void guessNum( int seq, int &ctgood) {
	int guess;
	cin >> guess;
	if (guess == seq) {
		ctgood = 1;
	}
	else {ctgood = 0;}
}
int main() {
	int seq[3][5] = {
		{1,5,10,16,23},
		{0,5,10,15,20},
		{2,4,8,16, 32}
	};

	int numrounds = 3;
	int i = 0, j = 0;
	cout << "=======================================" <<endl;
	cout << "=======> Guess the number game <=======" <<endl;
	cout << "=======================================" <<endl<< endl;
	string choice;
	int points = 0;
	int whichround =1;
	for (;;) {
		if (whichround-1 == numrounds) {
			cout << "Congratulations! You finished the game." << endl;
			cout << "You got " << points << " points" << endl;
			break;

		}

		else if (whichround == 1) {
				cout << "Do you want to start the game:";
				cin >> choice;
				whichround++;
			 }
		 
		else {
			cout << "You got " << points << " points" << endl;
			cout << "Do you to wish to continue playing: ";
			cin >> choice;
			whichround++;
		} if (choice == "No" || choice == "N" || choice == "0" || choice == "no" || choice == "n" || choice == "NO") {
			cout << "You got " << points << "points.";
			break;
		  }
		else {
			cout << "---------------------------------------" << endl;
			cout << "Round. " << whichround-1 <<endl;
			cout << "Guess the number: " << endl;
			cout << "-----------------" << endl;
			for (; j < 4;j++ ) {
				cout << seq[i][j] << " , ";
			}
			cout << "...."<< endl;
			

			int ctgood =0;
			for (;;) {
				guessNum(seq[i][j], ctgood);

				if (ctgood == 1) {
					cout << "---------------------------------------" << endl;
					cout << "Correct." << endl;
					points++;
					cout << "+1 POINT" << endl;
					cout << "---------------------------------------" << endl;
					i++;
					j = 0;
					break;
				}
				else {
					cout << "Wrong try again." << endl;
				}
			}

		}

	}
}