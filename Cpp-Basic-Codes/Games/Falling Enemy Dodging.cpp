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

void displayGrid(const Player& p, int level) {
    setCursorPosition(0, 0);
    cout << "Use W (up), S (down), A (left), D (right) to move. Press 'Q' to quit.\n\n";
    for (int i = 0; i < GRID_SIZE_LENGTH; i++) {
        for (int j = 0; j < GRID_SIZE_WIDTH; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Level: " << level << "  |  Score: " << p.score << "  |  HP: " << p.HP << endl;
}

void movePlayer(Player& p, Direction dir) {
    int oldX = p.x, oldY = p.y;

    if (dir == UP && p.y > 1) p.y--;
    else if (dir == DOWN && p.y < GRID_SIZE_LENGTH - 2) p.y++;
    else if (dir == LEFT && p.x > 1) p.x--;
    else if (dir == RIGHT && p.x < GRID_SIZE_WIDTH - 2) p.x++;

    if (grid[p.y][p.x] == '*') {
        p.HP--;
        if (p.HP <= 0) {
            system("cls");
            cout << "Game Over! You lost all HP.\n";
            cout << "Final Score: " << p.score << endl;
            exit(0);
        }
    }

    if (grid[p.y][p.x] == 'H') {
        p.HP++;
        grid[p.y][p.x] = ' ';
    }

    if (oldX == p.x && oldY == p.y) return;

    setCursorPosition(2 * oldX, oldY + 2);
    cout << ' ';

    grid[oldY][oldX] = ' ';
    grid[p.y][p.x] = '@';

    setCursorPosition(2 * p.x, p.y + 2);
    cout << '@';
}

void spawnEnemy(int level) {
    int minEnemies = 1 + level / 2;
    int maxEnemies = 2 + level;
    int enemyCount = rand() % (maxEnemies - minEnemies + 1) + minEnemies;

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
            if (grid[i][j] == '*' || grid[i][j] == 'H') {
                char temp = grid[i][j];
                grid[i][j] = ' ';
                setCursorPosition(2 * j, i + 2);
                cout << ' ';

                if (i + 1 < GRID_SIZE_LENGTH - 1) {
                    if (grid[i + 1][j] == '@') {
                        if (temp == '*') {
                            p.HP--;
                            if (p.HP <= 0) {
                                system("cls");
                                cout << "Game Over! You lost all HP.\n";
                                cout << "Final Score: " << p.score << endl;
                                exit(0);
                            }
                        }
                        else if (temp == 'H') {
                            p.HP++;
                        }
                        setCursorPosition(2 * j, i + 3);
                        cout << '@';
                    }
                    else {
                        grid[i + 1][j] = temp;
                        setCursorPosition(2 * j, i + 3);
                        cout << temp;
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

void spawnHpItem() {
    if (rand() % 8 == 0) {
        int x = rand() % (GRID_SIZE_WIDTH - 2) + 1;
        if (grid[1][x] == ' ') {
            grid[1][x] = 'H';
            setCursorPosition(2 * x, 3);
            cout << 'H';
        }
    }
}

int getLevel(int score) {
    if (score >= 1000) return 10;
    if (score >= 750) return 9;
    if (score >= 500) return 8;
    if (score >= 400) return 7;
    if (score >= 250) return 6;
    if (score >= 100) return 5;
    if (score >= 50) return 4;
    if (score >= 25) return 3;
    if (score >= 10) return 2;
    return 1;
}

void displayWinScreen() {
    system("cls");
    cout << "===========================" << endl;
    cout << "        YOU WIN!           " << endl;
    cout << "===========================" << endl;
    cout << "Final Score: 1000" << endl;
    exit(0);
}

int main() {
    srand(time(0));
    Player player = { 15, 20, 0, 10 };
    initializeGrid(player);
    displayGrid(player, 1);

    int frameCounter = 0;
    while (true) {
        int level = getLevel(player.score);

        if (level == 10) {
            displayWinScreen();
        }

        if (frameCounter % (7 - level / 2) == 0) {
            spawnEnemy(level);
            spawnHpItem();
        }

        moveEnemiesDown(player);
        deleteEnemy(player);
        setCursorPosition(0, GRID_SIZE_LENGTH + 2);
        cout << "Level: " << level << "  |  Score: " << player.score << "  |  HP: " << player.HP << "   ";

        if (_kbhit()) {
            char input = _getch();
            if (input == 'W' || input == 'w') movePlayer(player, UP);
            else if (input == 'S' || input == 's') movePlayer(player, DOWN);
            else if (input == 'A' || input == 'a') movePlayer(player, LEFT);
            else if (input == 'D' || input == 'd') movePlayer(player, RIGHT);
            else if (input == 'Q' || input == 'q') break;
        }

        Sleep(150 - level * 8);
        frameCounter++;
    }
}
