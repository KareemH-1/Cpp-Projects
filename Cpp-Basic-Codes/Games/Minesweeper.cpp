#include <iostream>
#include <ctime>
using namespace std;

void buildBoard(char board[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            board[i][j] = '#';  // Hidden cells
        }
    }
}

void displayBoard(char board[10][10]) {
    cout << "    ";
    for (int i = 0; i < 10; i++) {
        cout << (i + 1) << "   ";
    }
    cout << endl << endl;

    for (int i = 0; i < 10; i++) {
        cout << (i + 1) << "  ";
        for (int j = 0; j < 10; j++) {
            cout << board[i][j] << "   ";
        }
        cout << endl << endl;
    }
}

// Generate mines on a separate mine board
void placeMines(char mineBoard[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (rand() % 5 == 0) {  // 20% chance of placing a mine
                mineBoard[i][j] = '*';  // Mine
            } else {
                mineBoard[i][j] = '0';  // Empty space
            }
        }
    }
}

// Count adjacent mines for a given cell
int countMines(char mineBoard[10][10], int row, int col) {
    int count = 0;
    int directions[8][2] = {
        {-1, -1},{-1, 0},{-1, 1},  // Top-left, Top, Top-right
        {0, -1},         {0, 1},   // Left,       Right
        {1, -1}, {1, 0}, {1, 1}    // Bottom-left, Bottom, Bottom-right
    };

    for (int i = 0; i < 8; i++) {
        int newRow = row + directions[i][0];
        int newCol = col + directions[i][1];

        if (newRow >= 0 && newRow < 10 && newCol >= 0 && newCol < 10) {
            if (mineBoard[newRow][newCol] == '*') {
                count++;
            }
        }
    }
    return count;
}

// Reveal the chosen cell
bool revealCell(char board[10][10], char mineBoard[10][10], int row, int col, int &lives) {
    if (mineBoard[row][col] == '*') {
        lives--;
        cout << "You hit a mine! Lives left: " << lives << endl;
        return false;
    } else {
        int mineCount = countMines(mineBoard, row, col);
        board[row][col] = '0' + mineCount;
        return true;
    }
}

int main() {
    srand(time(0));
    char board[10][10];       // Visible board
    char mineBoard[10][10];   // Hidden mines
    int lives = 3;
    
    buildBoard(board);
    placeMines(mineBoard);
    
    while (lives > 0) {
        displayBoard(board);

        int row, col;
        cout << "Enter row (1-10): ";
        cin >> row;
        cout << "Enter column (1-10): ";
        cin >> col;
        row--; col--;  // Convert to zero-based index

        if (row < 0 || row >= 10 || col < 0 || col >= 10) {
            cout << "Invalid input. Try again." << endl;
            continue;
        }

        if (!revealCell(board, mineBoard, row, col, lives)) {
            if (lives == 0) {
                cout << "Game Over! You lost all your lives." << endl;
                break;
            }
        }
    }

    cout << "Final Board:" << endl;
    displayBoard(mineBoard);  // Show the mine board when the game ends
}
