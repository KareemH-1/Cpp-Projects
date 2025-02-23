#include <iostream>
#include <conio.h>
#include <ctime>
#include <windows.h>

using namespace std;

enum Direction { UP, DOWN, LEFT, RIGHT };

struct Player {
    int x, y;
    int score;
    int HP;
};

const int GRID_SIZE_LENGTH = 25;
const int GRID_SIZE_WIDTH = 30;
char grid[GRID_SIZE_LENGTH][GRID_SIZE_WIDTH];

void setCursorPosition(int x, int y) {
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void initializeGrid(Player& p) {
    for (int i = 0; i < GRID_SIZE_LENGTH; i++) {
        for (int j = 0; j < GRID_SIZE_WIDTH; j++) {
            grid[i][j] = ' ';
        }
    }
    for (int j = 0; j < GRID_SIZE_WIDTH; j++) {
        grid[0][j] = '#';
        grid[GRID_SIZE_LENGTH - 1][j] = '#';
    }
    for (int i = 0; i < GRID_SIZE_LENGTH; i++) {
        grid[i][0] = '#';
        grid[i][GRID_SIZE_WIDTH - 1] = '#';
    }
    grid[p.y][p.x] = '@';
}

void displayGrid(const Player& p) {
    setCursorPosition(0, 0);
    cout << "Use W (up), S (down), A (left), D (right) to move. Press 'Q' to quit.\n\n";
    for (int i = 0; i < GRID_SIZE_LENGTH; i++) {
        for (int j = 0; j < GRID_SIZE_WIDTH; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Score: " << p.score << "  |  HP: " << p.HP << endl;
}

void movePlayer(Player& p, Direction dir) {
    int oldX = p.x, oldY = p.y;

    if (dir == UP && p.y > 1) p.y--;
    else if (dir == DOWN && p.y < GRID_SIZE_LENGTH - 2) p.y++;
    else if (dir == LEFT && p.x > 1) p.x--;
    else if (dir == RIGHT && p.x < GRID_SIZE_WIDTH - 2) p.x++;

    // Check if player moved into an enemy
    if (grid[p.y][p.x] == '*') {
        p.HP--;
        if (p.HP <= 0) {
            system("cls");
            cout << "Game Over! You lost all HP.\n";
            cout << "Final Score: " << p.score << endl;
            exit(0);
        }
    }

    // Check if player stepped on an HP item
    if (grid[p.y][p.x] == 'H') {
        p.HP++;  // Increase HP
        grid[p.y][p.x] = ' ';  // Remove the HP item
    }

    if (oldX == p.x && oldY == p.y) return;

    // Clear old position
    setCursorPosition(2 * oldX, oldY + 2);
    cout << ' ';

    // Update player position in grid
    grid[oldY][oldX] = ' ';
    grid[p.y][p.x] = '@';

    // Print new player position
    setCursorPosition(2 * p.x, p.y + 2);
    cout << '@';
}

void spawnEnemy() {
    int enemyCount = rand() % 3 + 2;
    for (int i = 0; i < enemyCount; i++) {
        int x = rand() % (GRID_SIZE_WIDTH - 2) + 1;
        if (grid[1][x] == ' ') {
            grid[1][x] = '*';
            setCursorPosition(2 * x, 3);
            cout << '*';
        }
    }
}

void moveEnemiesDown(Player& p) {
    for (int i = GRID_SIZE_LENGTH - 2; i > 0; i--) {
        for (int j = 1; j < GRID_SIZE_WIDTH - 1; j++) {
            if (grid[i][j] == '*') {
                grid[i][j] = ' ';
                setCursorPosition(2 * j, i + 2);
                cout << ' ';

                if (i + 1 < GRID_SIZE_LENGTH - 1) {
                    if (grid[i + 1][j] == '@') {
                        p.HP--;
                        if (p.HP <= 0) {
                            system("cls");
                            cout << "Game Over! You lost all HP.\n";
                            cout << "Final Score: " << p.score << endl;
                            exit(0);
                        }
                        setCursorPosition(2 * j, i + 3);
                        cout << '@';
                    }
                    else {
                        grid[i + 1][j] = '*';
                        setCursorPosition(2 * j, i + 3);
                        cout << '*';
                    }
                }
            }
        }
    }
}

void deleteEnemy(Player& p) {
    for (int i = 1; i < GRID_SIZE_WIDTH - 1; i++) {
        if (grid[GRID_SIZE_LENGTH - 2][i] == '*') {
            grid[GRID_SIZE_LENGTH - 2][i] = ' ';
            setCursorPosition(2 * i, GRID_SIZE_LENGTH);
            cout << ' ';
            p.score++;
        }
    }
}

// HP item spawn function
void spawnHpItem() {
    if (rand() % 5 == 0) {  // 1/5 chance to spawn an HP item
        int x = rand() % (GRID_SIZE_WIDTH - 2) + 1;

        if (grid[1][x] == ' ') {  // Ensure it spawns at the top row
            grid[1][x] = 'H';
            setCursorPosition(2 * x, 3);
            cout << 'H';
        }
    }
}

void moveHpItemsDown(Player& p) {
    for (int i = GRID_SIZE_LENGTH - 2; i > 0; i--) {
        for (int j = 1; j < GRID_SIZE_WIDTH - 1; j++) {
            if (grid[i][j] == 'H') {
                grid[i][j] = ' ';
                setCursorPosition(2 * j, i + 2);
                cout << ' ';

                if (i + 1 < GRID_SIZE_LENGTH - 1) {
                    if (grid[i + 1][j] == '@') {  // Player collects HP
                        p.HP++;
                        setCursorPosition(2 * j, i + 3);
                        cout << '@';
                    }
                    else {
                        grid[i + 1][j] = 'H';
                        setCursorPosition(2 * j, i + 3);
                        cout << 'H';
                    }
                }
            }
        }
    }
}


int main() {
    srand(time(0));
    Player player = { 15, 20, 0, 10 };
    initializeGrid(player);
    displayGrid(player);

    int frameCounter = 0;
    while (true) {
        if (frameCounter % 5 == 0) {
            spawnEnemy();
            spawnHpItem();
        }
        moveEnemiesDown(player);
        moveHpItemsDown(player);
        deleteEnemy(player);

        setCursorPosition(0, GRID_SIZE_LENGTH + 2);
        cout << "Score: " << player.score << "  |  HP: " << player.HP << "   ";

        if (_kbhit()) {
            char input = _getch();
            if (input == 'W' || input == 'w') movePlayer(player, UP);
            else if (input == 'S' || input == 's') movePlayer(player, DOWN);
            else if (input == 'A' || input == 'a') movePlayer(player, LEFT);
            else if (input == 'D' || input == 'd') movePlayer(player, RIGHT);
            else if (input == 'Q' || input == 'q') break;
        }

        Sleep(100);
        frameCounter++;
    }

}
