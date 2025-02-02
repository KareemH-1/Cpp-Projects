#include <iostream>
#include <ctime> //used ctime library to use rand & srand functions to choose a number inbetween a range 
#include <string>
using namespace std;

// Function to generate a random number between 1 and 3 , 1 resembles rock , 2 for paper and 3 for scissors.
int randomnum() {
    return ((rand() % 3) + 1);
}

int main() {
    srand(time(0)); //initializing the random number generator with a starting value (the seed) so that it produces different random numbers each time the program runs.
   

    // Display game title and instructions
    cout << "===========================================" << endl;
    cout << "         Rock-Paper-Scissors Game!         " << endl;

    int points = 0; // Tracks the player's score
    int whichRound = 1; // Tracks the round number
    string choice = "yes"; // Ensures the game starts
    string move; //The player's input
    string oppmove; //the game's move;

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
        cout << "Round " << whichRound << endl;
        cout << "-----------------------------------------" << endl;

         int generatedNum = randomnum(); // Generate a random number between (1-3)
         
         if(generatedNum == 1){
            oppmove = "Rock";
         }
         else if (generatedNum ==2){
            oppmove = "Paper";
         }
         else if(generatedNum == 3){
            oppmove = "Scissors";
         }

         cout << "Please enter your move: ";
         cin>>move;

        
          if (oppmove == "Rock" && (move == "Rock" || move == "rock" || move == "r" || move == "R" || move =="1")) {
                cout << "The opponent chose " << oppmove << "." << endl;
                cout << "=========================================" << endl;
                cout << "           Correct! +1 POINT!            " << endl;
                cout << "=========================================" << endl;
                points++;

            }
             else if (oppmove == "Paper" && (move == "Paper" || move == "paper" || move == "p" || move == "P" || move =="2")) {
                cout << "The opponent chose " << oppmove << "." << endl;
                cout << "=========================================" << endl;
                cout << "           Correct! +1 POINT!            " << endl;
                cout << "=========================================" << endl;
                points++;
  
            }
             else if (oppmove == "Scissors" && (move == "scissors" || move == "Scissors" || move == "S" || move == "s" || move =="3")) {
                cout << "The opponent chose " << oppmove << "." << endl;

                cout << "=========================================" << endl;
                cout << "           Correct! +1 POINT!            " << endl;
                cout << "=========================================" << endl;
                points++;

            }
            else{
                cout << "Wrong it was " << oppmove << "!" << endl;
            }
               whichRound++; // Move to the next round
     }
}