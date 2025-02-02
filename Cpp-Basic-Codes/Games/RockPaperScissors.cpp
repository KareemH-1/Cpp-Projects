#include <iostream>
#include <ctime> // Include ctime library for rand() and srand()
#include <string>
using namespace std;

// Function to generate a random number between 1 and 3, where:
// 1 = Rock, 2 = Paper, 3 = Scissors
int randomnum() {
    return ((rand() % 3) + 1); // Generate a number between 1 and 3
}

int main() {
    srand(time(0)); // Initialize the random number generator with a seed based on the current time

    // Display game title and instructions
    cout << "===========================================" << endl;
    cout << "         Rock-Paper-Scissors Game!         " << endl;
    cout << "===========================================" << endl << endl;
    cout << "Instructions:" << endl;
    cout << " - Type 'Rock' (or 'r', 'R', or '1') for Rock" << endl;
    cout << " - Type 'Paper' (or 'p', 'P', or '2') for Paper" << endl;
    cout << " - Type 'Scissors' (or 's', 'S', or '3') for Scissors" << endl;
    cout << "Try to match the opponent's move to score a point!" << endl;


    int points = 0; // Tracks the player's score
    int whichRound = 1; // Tracks the round number
    string choice = "yes"; // Ensures the game starts
    string move; // Variable to store the player's input (Rock, Paper, or Scissors)
    string oppmove; // Variable to store the computer's move (Rock, Paper, or Scissors)

    for (;;) { // Infinite loop to keep the game going
        if (whichRound != 1) { // Check if it's not the first round
            cout << "-----------------------------------------" << endl;
            cout << "You currently have " << points << " points." << endl;
            cout << "Do you want to continue playing? (yes/no): ";
            cin >> choice; // Ask the user if they want to continue
        }

        // If the player chooses to quit the game
        if (choice == "No" || choice == "N" || choice == "0" || choice == "no" || choice == "n" || choice == "NO") {
            cout << "-----------------------------------------" << endl;
            cout << "Game Over! You scored " << points << " points." << endl;
            break; // Exit the game loop
        }

        // Start a new round
        cout << "=========================================" << endl;
        cout << "Round " << whichRound << endl;
        cout << "-----------------------------------------" << endl;

        int generatedNum = randomnum(); // Generate the opponent's move (random number between 1 and 3)

        // Assign the computer's move based on the generated number
        if (generatedNum == 1) {
            oppmove = "Rock"; // 1 means Rock
        }
        else if (generatedNum == 2) {
            oppmove = "Paper"; // 2 means Paper
        }
        else if (generatedNum == 3) {
            oppmove = "Scissors"; // 3 means Scissors
        }

        cout << "Please enter your move: ";
        cin >> move; // Get the player's input

        // Check if the player's move is the same as the opponent's move
        if (oppmove == "Rock" && (move == "Rock" || move == "rock" || move == "r" || move == "R" || move == "1")) {
            cout << "The opponent chose " << oppmove << "." << endl;
            cout << "=========================================" << endl;
            cout << "           Correct! +1 POINT!            " << endl;
            cout << "=========================================" << endl;
            points++; // Increment points for a correct answer
        }
        else if (oppmove == "Paper" && (move == "Paper" || move == "paper" || move == "p" || move == "P" || move == "2")) {
            cout << "The opponent chose " << oppmove << "." << endl;
            cout << "=========================================" << endl;
            cout << "           Correct! +1 POINT!            " << endl;
            cout << "=========================================" << endl;
            points++; // Increment points for a correct answer
        }
        else if (oppmove == "Scissors" && (move == "scissors" || move == "Scissors" || move == "S" || move == "s" || move == "3")) {
            cout << "The opponent chose " << oppmove << "." << endl;
            cout << "=========================================" << endl;
            cout << "           Correct! +1 POINT!            " << endl;
            cout << "=========================================" << endl;
            points++; // Increment points for a correct answer
        }
        else {
            cout << "Wrong! It was " << oppmove << "!" << endl; // Display the opponent's move if the player is wrong
        }

        whichRound++; // Increment to the next round
    }
}
