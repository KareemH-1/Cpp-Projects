#include <iostream>
#include <conio.h> // For _getch() to capture keypress instantly
using namespace std;

// Enum for movement directions
enum Direction { UP, DOWN, LEFT, RIGHT };

// Struct for player
struct Player {
    int x, y;  // Position in the grid
    int score;
};

// Grid size
const int GRID_SIZE = 5;
char grid[GRID_SIZE][GRID_SIZE];

void initializeGrid(Player &p) {

    int i , j ;

    for ( i = 0 ; i < GRID_SIZE ; i++ ) {
        
        for ( j = 0 ; j < GRID_SIZE ; j++ ) {
            grid[i][j] = '.';
        }
    }

    // Place player on the grid
    grid[p.y][p.x] = '#';
}

// Function to display the grid
void displayGrid() {
    system("cls"); // Clear screen

    int i , j ;

    for ( i = 0 ; i < GRID_SIZE ; i++ ) {

        for ( j = 0 ; j < GRID_SIZE ; j++ ) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to move the player
void movePlayer(Player &p, Direction dir) {

    // Remove player from old position
    grid[p.y][p.x] = '.';

    if ( dir == UP ) {

        if ( p.y > 0 ) {
            p.y--;
        }
    }
    
    else if ( dir == DOWN ) {

        if ( p.y < GRID_SIZE - 1 ) {
            p.y++;
        }
    }
    
    else if ( dir == LEFT ) {

        if ( p.x > 0 ) {
            p.x--;
        }
    }
    
    else if ( dir == RIGHT ) {

        if ( p.x < GRID_SIZE - 1 ) {
            p.x++;
        }
    }

    // Update player position
    grid[p.y][p.x] = '#';
    p.score++; // Increase score on each move
}

int main() {
    Player player = {2, 2, 0}; // Start in the center (2,2)
    initializeGrid(player);

    cout << "Use W (up), S (down), A (left), D (right) to move. Press 'Q' to quit.\n";

    while ( true ) {
        displayGrid();
        cout << "Score: " << player.score << endl;

        // Get key
        char input = _getch();

        if ( input == 'W' || input == 'w' ) {
            movePlayer(player, UP);
        }
        
        else if ( input == 'S' || input == 's' ) {
            movePlayer(player, DOWN);
        }
        
        else if ( input == 'A' || input == 'a' ) {
            movePlayer(player, LEFT);
        }
        
        else if ( input == 'D' || input == 'd' ) {
            movePlayer(player, RIGHT);
        }
        
        else if ( input == 'Q' || input == 'q' ) {
            break; // Quit the game
        }
    }

    cout << "Game Over! Final Score: " << player.score << endl;

}
