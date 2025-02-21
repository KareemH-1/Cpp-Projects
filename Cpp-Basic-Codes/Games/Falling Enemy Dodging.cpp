#include <iostream>
#include <conio.h>  // For _getch() and _kbhit()
#include <ctime>    // For randomization
#include <windows.h> // For Sleep()

using namespace std;

// Enum for movement directions
enum Direction { UP, DOWN, LEFT, RIGHT };

// Struct for player
struct Player {
    int x, y;
    int score;
    int HP;
};

// Grid size
const int GRID_SIZE_LENGTH = 25;
const int GRID_SIZE_WIDTH = 30;
char grid[GRID_SIZE_LENGTH][GRID_SIZE_WIDTH];

// Initialize the grid
void initializeGrid(Player& p) {
    for (int i = 0; i < GRID_SIZE_LENGTH; i++) {
        for (int j = 0; j < GRID_SIZE_WIDTH; j++) {
            grid[i][j] = ' ';
        }
    }

    // Create borders
    for (int j = 0; j < GRID_SIZE_WIDTH; j++) {
        grid[0][j] = '#';
        grid[GRID_SIZE_LENGTH - 1][j] = '#';
    }
    for (int i = 0; i < GRID_SIZE_LENGTH; i++) {
        grid[i][0] = '#';
        grid[i][GRID_SIZE_WIDTH - 1] = '#';
    }

    // Place player on the grid
    grid[p.y][p.x] = '@';
}

// Display the grid
void displayGrid(const Player& p) {
    system("cls"); // Clear screen (Windows only)
    for (int i = 0; i < GRID_SIZE_LENGTH; i++) {
        for (int j = 0; j < GRID_SIZE_WIDTH; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Score: " << p.score << "  |  HP: " << p.HP << endl;
}

// Move the player
void movePlayer(Player& p, Direction dir) {
    grid[p.y][p.x] = ' '; // Clear current position

    if (dir == UP && p.y > 1) p.y--;
    else if (dir == DOWN && p.y < GRID_SIZE_LENGTH - 2) p.y++;
    else if (dir == LEFT && p.x > 1) p.x--;
    else if (dir == RIGHT && p.x < GRID_SIZE_WIDTH - 2) p.x++;

    grid[p.y][p.x] = '@';
}

// Spawn new enemies randomly at the top
void spawnEnemy() {
    int enemyCount = rand() % 3 + 2;  // Randomly spawn 2 to 5 enemies per cycle
    for (int i = 0; i < enemyCount; i++) {
        int x = rand() % (GRID_SIZE_WIDTH - 2) + 1;
        if (grid[1][x] == ' ') grid[1][x] = '*';
    }
}

// Move enemies downward
void moveEnemiesDown(Player& p) {
    for (int i = GRID_SIZE_LENGTH - 2; i > 0; i--) {
        for (int j = 1; j < GRID_SIZE_WIDTH - 1; j++) {
            if (grid[i][j] == '*') {
                grid[i][j] = ' '; // Clear old position

                if (i + 1 < GRID_SIZE_LENGTH - 1) {
                    if (grid[i + 1][j] == '@') { // If enemy hits player
                        p.HP--;
                        if (p.HP <= 0) {
                            system("cls");
                            cout << "Game Over! You lost all HP.\n";
                            cout << "Final Score: " << p.score << endl;
                            exit(0);
                        }
                    }
                    else {
                        grid[i + 1][j] = '*';
                    }
                }
            }
        }
    }
}

// Remove enemies that reach the bottom and increase score
void deleteEnemy(Player& p) {
    for (int i = 1; i < GRID_SIZE_WIDTH - 1; i++) {
        if (grid[GRID_SIZE_LENGTH - 2][i] == '*') {
            grid[GRID_SIZE_LENGTH - 2][i] = ' '; // Remove enemy
            p.score++; // Increase score
        }
    }
}

int main() {
    srand(time(0));
    Player player = { 15, 20, 0, 10 };
    initializeGrid(player);

    cout << "Use W (up), S (down), A (left), D (right) to move. Press 'Q' to quit.\n";

    int frameCounter = 0;
    while (true) {
        if (frameCounter % 5 == 0) { // Spawn enemies every 5 cycles
            spawnEnemy();
        }
        moveEnemiesDown(player);
        deleteEnemy(player);

        displayGrid(player);

        // Non-blocking player movement
        if (_kbhit()) {
            char input = _getch();
            if (input == 'W' || input == 'w') movePlayer(player, UP);
            else if (input == 'S' || input == 's') movePlayer(player, DOWN);
            else if (input == 'A' || input == 'a') movePlayer(player, LEFT);
            else if (input == 'D' || input == 'd') movePlayer(player, RIGHT);
            else if (input == 'Q' || input == 'q') break;
        }

        Sleep(100); // Adjust game speed
        frameCounter++;
    }

}
