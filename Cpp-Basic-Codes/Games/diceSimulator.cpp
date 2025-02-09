#include <iostream>
#include <ctime>   // For time()

using namespace std;

// Function to roll a single die
int rollDie() {
    return (rand() % 6) + 1; // Generates a number between 1 and 6
}

int main() {
    srand(time(0)); // Seed random number generator with current time

    int numRolls;
    cout << "Welcome to the Dice Simulator!"<<endl;
    cout << "How many times would you like to roll the dice? ";
    cin >> numRolls;

    if (numRolls <= 0) {
        cout << "Invalid number of rolls! Exiting..."<<endl;
        return 1;
    }

    cout << "Rolling the dice..."<<endl;
    for (int i = 0; i < numRolls; i++) {
        cout << "Roll " << (i + 1) << ": " << rollDie() << endl;
    }

    cout << "GoodBye!";
}
