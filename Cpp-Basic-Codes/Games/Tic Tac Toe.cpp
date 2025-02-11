#include<iostream>
using namespace std;

void fill(char x[3][3]) {
	for (int r = 0; r < 3; r++) {
		for (int c = 0; c < 3; c++) {
			x[r][c] = '#';
		}
	}
}

void display(char x[3][3]) {
	cout << "-------" << endl;
	for (int r = 0; r < 3; r++) {
		for (int c = 0; c < 3; c++) {
			cout << x[r][c] << "  ";
		}
		if (r < 2) {
			cout << endl << endl;
		}
		else
		{
			cout << endl;
		}
	}
	cout <<"-------" << endl <<endl;
}

void play(char x[3][3], char player) {
	int row, col;
	cout << "Enter the row and col: ";
	cin >> row >> col;
	cout << endl;
	if ((x[row - 1][col - 1] == '#') && row-1 <= 3 && col-1 <= 3) {
		x[row - 1][col - 1] = player;
	}
	else {
		cout << "Invalid move , try again!" << endl;
		play(x, player);
	}
}
bool checkwin(char x[3][3] , char player) {
	
	if (x[0][0] ==player && x[1][1] == player && x[2][2] == player) {
		return true;
	}
	else if (x[0][2] == player && x[1][1] == player && x[2][0] == player) {
		return true;
	}
	for (int i = 0; i < 3; i++) {
		if (x[i][0] == player && x[i][1] == player && x[i][2] == player) {
			return true;
		}
		if (x[0][i] == player && x[1][i] == player && x[2][i] == player) {
			return true;
		}
	}
	return false;
}

int main() {
	char board[3][3];
	fill(board);
	display(board);
	int whichplayer = 1;
	for (int i = 0; i < 9; i++) {
		bool x = checkwin(board, 'X');
		bool o = checkwin(board, 'O');
		if (x == true) {
			cout << "----------------" << endl;
			cout << "X wins!" << endl;
			break;
		}
		else if (o == true) {
			cout << "----------------" << endl;
			cout << "O wins!" << endl;
			break;
		}
		else {
			if (whichplayer == 1) {
				cout << "Player " << whichplayer << " (X) " << " turn ";
				play(board, 'X');
				whichplayer = 2;
			}
			else {
				cout << "Player " << whichplayer << " (O) " << " turn ";
				play(board, 'O');
				whichplayer = 1;
			}
			display(board);
		}
	}
}