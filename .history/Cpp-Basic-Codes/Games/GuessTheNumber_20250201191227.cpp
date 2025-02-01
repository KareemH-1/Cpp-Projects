/*
===============================================
             GUESS THE NUMBER GAME
===============================================
- This game presents mathematical sequences to the player.
- The player must guess the next number in the sequence.
- If the guess is correct, they earn a point and move to the next round.
- If the guess is incorrect, they must try again until they succeed.
- The game consists of 7 rounds with different types of sequences.
*/

#include <iostream>
#include <string>
using namespace std;

// Function to check if the guessed number is correct
void guessNum(int seq, int &ctgood) {
    int guess;
    cin >> guess;
    if (guess == seq) {
        ctgood = 1;  // Correct guess
    } else {
        ctgood = 0;  // Incorrect guess
    }
}

int main() {
    // Define the sequences used in the game
    int seq[7][5] = {
        {1, 5, 10, 16, 23},   // (+4) then (+5) then (+6)...(+n)
        {0, 5, 10, 15, 20},   // Arithmetic sequence (+5)
        {2, 4, 8, 16, 32},    // Geometric sequence (*2)
        {1, 4, 9, 16, 25},    // Square numbers (n^2)
        {400, 200, 100, 50, 25},  // Divide sequence (n/2)
        {1, 1, 2, 3, 5},      // Fibonacci sequence
        {2, 3, 5, 7, 11}      // Prime numbers
    };

    int numrounds = 7;  // Total rounds in the game
    int i = 0, j = 0;
    
    // Display the game title
    cout << "=======================================" << endl;
    cout << "=======> Guess the number game <=======" << endl;
    cout << "=======================================" << endl << endl;
    
    string choice;
    int points = 0;
    int whichround = 1;
    
    for (;;) {  // Infinite loop to control the game flow
        if (whichround - 1 == numrounds) {
            // If all rounds are completed, end the game
            cout << "Congratulations! You finished the game." << endl;
            cout << "You got " << points << " points." << endl;
            break;
        }

        // Ask the player if they want to start or continue
        if (whichround == 1) {
            cout << "Do you want to start the game: ";
            cin >> choice;
            whichround++;
        } else {
            cout << "You got " << points << " points." << endl;
            cout << "Do you wish to continue playing: ";
            cin >> choice;
            whichround++;
        }

        // If the player chooses to quit, exit the game
        if (choice == "No" || choice == "N" || choice == "0" || choice == "no" || choice == "n" || choice == "NO") {
            cout << "You got " << points << " points.";
            break;
        } else {
            // Start the round
            cout << "---------------------------------------" << endl;
            cout << "Round " << whichround - 1 << endl;
            cout << "Guess the number: " << endl;
            cout << "-----------------" << endl;
            
            // Display the first four numbers in the sequence
            for (; j < 4; j++) {
                cout << seq[i][j] << " , ";
            }
            cout << "...." << endl;
            
            int ctgood = 0;
            
            // Loop until the player guesses correctly
            for (;;) {
                guessNum(seq[i][j], ctgood);
                if (ctgood == 1) {
                    cout << "---------------------------------------" << endl;
                    cout << "Correct." << endl;
                    points++;  // Increase points
                    cout << "+1 POINT" << endl;
                    cout << "---------------------------------------" << endl;
                    i++;  // Move to the next sequence
                    j = 0; // Reset j for the next sequence
                    break;
                } else {
                    cout << "Wrong! Try again." << endl;
                }
            }
        }
    }
}
