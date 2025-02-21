#include <iostream>
#include <conio.h> // For _getch() to capture keypress instantly
#include <ctime>   // To randomize fall location
#include <windows.h> // For Sleep() to control game speed
using namespace std;

// Enum for movement directions
enum Direction { UP, DOWN, LEFT, RIGHT };

// Struct for player
struct Player {
    int x, y;  // Position in the grid
    int score;
    int HP;
};

// Grid size
const int GRID_SIZE_LENGTH = 25;
const int GRID_SIZE_WIDTH = 30;
char grid[GRID_SIZE_LENGTH][GRID_SIZE_WIDTH];

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

// Function to display the grid
void displayGrid() {
    system("cls"); // Clear screen (Windows only)
    for (int i = 0; i < GRID_SIZE_LENGTH; i++) {
        for (int j = 0; j < GRID_SIZE_WIDTH; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to move the player
void movePlayer(Player& p, Direction dir) {
    grid[p.y][p.x] = ' ';

    if (dir == UP && p.y > 1) p.y--;
    else if (dir == DOWN && p.y < GRID_SIZE_LENGTH - 2) p.y++;
    else if (dir == LEFT && p.x > 1) p.x--;
    else if (dir == RIGHT && p.x < GRID_SIZE_WIDTH - 2) p.x++;

    grid[p.y][p.x] = '@';
}

// Spawn enemy function at random positions
void spawnEnemy() {
    for (int i = 0; i < 5; i++) {  // Spawn up to 5 enemies at a time
        int x = rand() % (GRID_SIZE_WIDTH - 2) + 1;
        if (grid[1][x] == ' ') grid[1][x] = '*'; // Place enemy at the top row
    }
}

// Move enemies down
void moveEnemiesDown() {
    for (int i = GRID_SIZE_LENGTH - 2; i > 0; i--) {
        for (int j = 1; j < GRID_SIZE_WIDTH - 1; j++) {
            if (grid[i][j] == '*') {
                grid[i][j] = ' '; // Remove from current position
                if (i + 1 < GRID_SIZE_LENGTH - 1) grid[i + 1][j] = '*'; // Move enemy down
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

// Check if enemy hits player
void damagePlayer(Player& p) {
    if (grid[p.y][p.x] == '*') { // If enemy hits player
        p.HP--;
        grid[p.y][p.x] = '@';
        if (p.HP <= 0) { // If HP reaches 0
            system("cls");
            cout << "Game Over! You lost all HP.\n";
            cout << "Final Score: " << p.score << endl;
            exit(0); // End game
        }
    }
}

int main() {
    srand(time(0));
    Player player = { 15, 20, 0, 10 };
    initializeGrid(player);

    cout << "Use W (up), S (down), A (left), D (right) to move. Press 'Q' to quit.\n";

    int enemySpawnCounter = 0;

    while (true) {
        if (enemySpawnCounter % 5 == 0) { // Spawn enemies every few cycles
            spawnEnemy();
        }
        moveEnemiesDown();
        deleteEnemy(player); // Score increases when enemy reaches bottom
        damagePlayer(player);

        displayGrid();
        cout << "Score: " << player.score << endl;
        cout << "HP: " << player.HP << endl;

        // Check if key is pressed
        if (_kbhit()) {
            char input = _getch();
            if (input == 'W' || input == 'w') movePlayer(player, UP);
            else if (input == 'S' || input == 's') movePlayer(player, DOWN);
            else if (input == 'A' || input == 'a') movePlayer(player, LEFT);
            else if (input == 'D' || input == 'd') movePlayer(player, RIGHT);
            else if (input == 'Q' || input == 'q') break;
        }

        enemySpawnCounter++;
        Sleep(200); // Control game speed
    }

}
