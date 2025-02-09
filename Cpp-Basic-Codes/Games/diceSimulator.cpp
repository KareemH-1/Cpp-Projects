#include <iostream>
#include <ctime>   // For time()

using namespace std;

// Function to roll a single die
int rollDie() {
    return (rand() % 6) + 1; // Generates a number between 1 and 6
}

// Function to display dice faces
void printDice(int value) {
    if (value == 1) {
        cout << " ------- "<<endl;
        cout << "|       |"<<endl;
        cout << "|   O   |"<<endl;
        cout << "|       |"<<endl;
        cout << " ------- "<<endl;
    } 
    else if (value == 2) {
        cout << " ------- "<<endl;
        cout << "| O     |"<<endl;
        cout << "|       |"<<endl;
        cout << "|     O |"<<endl;
        cout << " ------- "<<endl;
    } 
    else if (value == 3) {
        cout << " ------- "<<endl;
        cout << "| O     |"<<endl;
        cout << "|   O   |"<<endl;
        cout << "|     O |"<<endl;
        cout << " ------- "<<endl;
    } 
    else if (value == 4) {
        cout << " ------- "<<endl;
        cout << "| O   O |"<<endl;
        cout << "|       |"<<endl;
        cout << "| O   O |"<<endl;
        cout << " ------- "<<endl;
    } 
    else if (value == 5) {
        cout << " ------- "<<endl;
        cout << "| O   O |"<<endl;
        cout << "|   O   |"<<endl;
        cout << "| O   O |"<<endl;
        cout << " ------- "<<endl;
    } 
    else if (value == 6) {
        cout << " ------- "<<endl;
        cout << "| O   O |"<<endl;
        cout << "| O   O |"<<endl;
        cout << "| O   O |"<<endl;
        cout << " ------- "<<endl;
    }
}


int main() {
    srand(time(0)); 

    char choice;
    cout << "Welcome to the Dice Simulator!" <<endl;
    while (choice == 'y' || choice == 'Y'|| choice == '1') {
        int roll = rollDie();
        cout << "You rolled: " << roll << endl;
        printDice(roll);

        cout << "Do you want to roll again? (Y/N): ";
        cin >> choice;
    }

    cout << "Goodbye!";
}