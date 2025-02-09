#include <iostream>
using namespace std;

// Fill the board
void buildBoard(char board[6][7]) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            board[i][j] = '#'; 
        }
    }
}

void printBoard(char board[6][7]) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Checks if there isn't a piece in the column then drops the piece if there is not
void dropPiece(char board[6][7], int col, char piece) {
    for (int i = 5; i >= 0; i--) {
        if (board[i][col] == '#') {
            board[i][col] = piece;
            break;
        }
    }
}

bool checkWin(char board[6][7], char piece) {
    // Check horizontal
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {  // Max j = 3 to avoid going off range
            if (board[i][j] == piece && board[i][j + 1] == piece &&
                board[i][j + 2] == piece && board[i][j + 3] == piece)
                return true;
        }
    }

    // Check vertical
    for (int i = 0; i < 3; i++) {  // Max i = 2 to avoid going off range
        for (int j = 0; j < 7; j++) {
            if (board[i][j] == piece && board[i + 1][j] == piece &&
                board[i + 2][j] == piece && board[i + 3][j] == piece)
                return true;
        }
    }

    // Check diagonal (top-left to bottom-right)
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == piece && board[i + 1][j + 1] == piece &&
                board[i + 2][j + 2] == piece && board[i + 3][j + 3] == piece)
                return true;
        }
    }

    // Check diagonal (bottom-left to top-right)
    for (int i = 3; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == piece && board[i - 1][j + 1] == piece &&
                board[i - 2][j + 2] == piece && board[i - 3][j + 3] == piece)
                return true;
        }
    }

    return false;
}

int main() {
    char board[6][7];
    buildBoard(board);

    int currentPlayer = 1;
    char currentPiece;
    int column;
    bool gameWon = false;

    for ( ; gameWon != true; ) {
        printBoard(board);

        // Set currentPiece using if-else
        if (currentPlayer == 1) {
            currentPiece = 'X';
        } else {
            currentPiece = 'O';
        }

        // Player input
        bool isusableColumn = false;

        for(; isusableColumn == false;) {
            cout << "Player " << currentPlayer << " (" << currentPiece << ") - Choose a column (1-7): ";
            cin >> column;

            
            column--;  // Subtract 1 for user friendly column input

            if (column < 0 || column > 6) {
                cout << "Invalid column! Try again." << endl;
            } else {
                isusableColumn = true;
            }
        }

        dropPiece(board, column, currentPiece);

        if (checkWin(board, currentPiece) == true) {
            printBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            gameWon = true;
        } else {
            // Switching players
            if (currentPlayer == 1) {
                currentPlayer = 2;
            } else {
                currentPlayer = 1;
            }
        }
    }
}
