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
    int seq[38][5] = {
    {1, 1, 1, 1, 1},           // 1. Sequence of ones
    {0, 5, 10, 15, 20},        // 2. Arithmetic sequence (+5)
    {3, 6, 9, 12, 15},         // 3. Multiples of 3
    {11, 22, 33, 44, 55},      // 4. Multiples of 11
    {5, 10, 20, 40, 80},       // 5. Geometric sequence (*2)
    {2, 4, 8, 16, 32},         // 6. Geometric sequence (*2)
    {1, 4, 9, 16, 25},         // 7. Square numbers (n²)
    {2, 6, 12, 20, 30},        // 8. Quadratic pattern (+4, +6, +8, +10)
    {1, 5, 10, 16, 23},        // 9. Increasing pattern (+4, +5, +6...)
    {2, 3, 5, 7, 11},          // 10. Prime numbers
    {1, 1, 2, 3, 5},           // 11. Fibonacci sequence
    {13, 21, 34, 55, 89},      // 12. Extended Fibonacci
    {1, 3, 7, 15, 31},         // 13. Powers of 2 minus 1 (2^n - 1)
    {400, 200, 100, 50, 25},   // 14. Division pattern (n/2)
    {9, 17, 33, 65, 129},      // 15. Doubling and subtracting one (-1)
    {81, 64, 49, 36, 25},      // 16. Reverse square numbers
    {121, 144, 169, 196, 225}, // 17. Consecutive squared numbers (11², 12²...)
    {100, 95, 90, 85, 80},     // 18. Arithmetic sequence (-5)
    {4, 9, 25, 49, 121},       // 19. Prime squared numbers
    {7, 14, 28, 56, 112},      // 20. Doubling a multiple of 7
    {10, 20, 30, 50, 80},      // 21. Mixed arithmetic (+10, +10, +20, +30)
    {100, 200, 300, 400, 500}, // 22. Simple increasing by 100
    {1, 2, 6, 24, 120},        // 23. Factorial (n!)
    {1, 8, 27, 64, 125},       // 24. Cube numbers (n³)
    {10, 20, 40, 80, 160},     // 25. Doubling with starting number 10
    {1, 4, 13, 40, 121},       // 26. Cubic-like progression
    {1, 2, 4, 8, 16},          // 27. Powers of 2 (2^n)
    {3, 6, 12, 24, 48},        // 28. Doubling multiples of 3
    {2, 4, 8, 16, 32},         // 29. Powers of 2
    {2, 6, 12, 24, 48},        // 30. Doubling multiples of 3
    {1, 3, 6, 10, 15},         // 31. Triangle numbers (n(n+1)/2)
    {1, 4, 9, 16, 25},         // 32. Square numbers (n²)
    {7, 14, 21, 28, 35},       // 33. Linear growth with steps of 7
    {100, 200, 300, 400, 500}, // 34. Simple increasing by 100
    {10, 50, 100, 200, 400},   // 35. Increasing powers of 2 with offsets
    {2, 6, 12, 20, 30},        // 36. Quadratic pattern (n²)
    {2, 4, 16, 256, 65536},    // 37. Exponential (n^n)
    {16, 8, 4 , 2 , 1}         //38. binomial numbers (2^n) where n starts with 0 from left
};


    int numrounds = 38;  // Total rounds in the game
    int i = 0, j = 0;
    
    // Display the game title
    cout << "======================================" << endl;
    cout << "======> Guess the pattern game <======" << endl;
    cout << "======================================" << endl << endl;
    
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
            cout << "---------------------------------";
            cout << "You got " << points << " points.";
            break;
        } else {
            // Start the round
            cout << "---------------------------------------" << endl;
            cout << "Round " << whichround - 1 << endl;
            cout << "Guess the Pattern: " << endl;
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
