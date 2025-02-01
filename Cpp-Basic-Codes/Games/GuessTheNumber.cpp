#include <iostream>
#include <ctime>
#include <string>
using namespace std;

// Function to generate a random number between 1 and diff variable.
int randomnum(int diff) {
    return (rand() % diff) + 1;
}

int main() {
    srand(time(0)); //initializing the random number generator with a starting value (the seed) so that it produces different random numbers each time the program runs.

    // Display game title and instructions
    cout << "===========================================" << endl;
    cout << "       Welcome to the Guessing Game!       " << endl;
    cout << "===========================================" << endl;
    cout << "Instructions: Try to guess the randomly generated number." << endl;
    cout << "With each correct guess, the difficulty increases!" << endl;
    cout << "Enter your guesses and receive hints until you get it right!" << endl;
    cout << "Type 'no' when asked to quit the game." << endl;
    cout << "===========================================\n\n";

    string choice = "yes"; // Ensures the game starts
    int points = 0; // Tracks the player's score
    int whichRound = 1; // Tracks the round number
    int diff = 10; // Initial difficulty level

    for (;;) { // Infinite loop for game rounds
        if (whichRound != 1) {
            cout << "-----------------------------------------" << endl;
            cout << "You currently have " << points << " points." << endl;
            cout << "Do you want to continue playing? (yes/no): ";
            cin >> choice;
        }

        // Check if the player wants to quit
        if (choice == "No" || choice == "N" || choice == "0" || choice == "no" || choice == "n" || choice == "NO") {
            cout << "-----------------------------------------" << endl;
            cout << "Game Over! You scored " << points << " points." << endl;
            break;
        }

        // Start a new round
        cout << "=========================================" << endl;
        cout << "               Round " << whichRound << "               " << endl;
        cout << "=========================================" << endl;

        int num = randomnum(diff); // Generate a new random number

        for (;;) { // Loop until correct guess
            int enteredNum;
            cout << "\nEnter your guess (1 - " << diff << "): ";
            cin >> enteredNum;


            if (enteredNum == num) {
                cout << endl << "=========================================" << endl;
                cout << "         Correct! +1 POINT!          " << endl;
                cout << "=========================================" << endl;
                points++;
                diff *= 10; // Increase difficulty for next round
                break;
            }
            else if (enteredNum < num) {
                cout << "Try a higher number!" << endl;
            }
            else {
                cout << "Try a lower number!" << endl;
            }
        }

        whichRound++; // Move to the next round
    }
}
