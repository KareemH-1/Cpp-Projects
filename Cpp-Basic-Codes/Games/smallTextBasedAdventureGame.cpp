#include <iostream>
#include <string>
using namespace std;

// Function to display the introduction
void displayIntroduction() {
    cout << "Welcome to the Adventure Game!" << endl;
    cout << "You find yourself in a mysterious forest. What will you do?" << endl;
}

// Function to handle the first room of the game
void firstRoom() {
    int choice;
    cout << "You are standing at a crossroad. Do you want to go left or right?" << endl;
    cout << "1. Left \n2. Right" << endl;
    cin >> choice;

    if (choice == 1) {
        cout << "You walk into a dark cave and find a treasure chest! Congratulations!" << endl;
    } else if (choice == 2) {
        cout << "You walk into a dense forest and encounter a wild animal! Try to fight or run." << endl;
        int action;
        cout << "1. Fight \n2. Run" << endl;
        cin >> action;
        if (action == 1) {
            cout << "You fight the animal and win! You find a key." << endl;
        } else {
            cout << "You run away safely, but no treasure found." << endl;
        }
    } else {
        cout << "Invalid choice. Please choose 1 or 2." << endl;
        firstRoom();  // Recursion for invalid choice
    }
}

// Function to handle the second room after finding the key
void secondRoom() {
    int choice;
    cout << "You use the key and open a hidden door leading to a dark room." << endl;
    cout << "There is a mysterious figure inside. Do you talk to them or run away?" << endl;
    cout << "1. Talk\n2. Run" << endl;
    cin >> choice;

    if (choice == 1) {
        cout << "The figure introduces themselves as a guide. They offer to help you escape the forest." << endl;
        cout << "Do you accept their offer?" <<endl;
        cout << "1.Yes \n2. No" <<endl;
        int choice2;
        cin>> choice2;

        if(choice2 == 1){
            cout << "They start following you. \n | Ally added! |"<<endl;
            cout << "You both leave the room together." << endl;
        }
        else if (choice ==2){
            cout << "mysterious figure: okay then!" <<endl;
            cout << "The mysterious figure disappears." <<endl;
            cout << "You leave the room in frustration." <<endl;
        }
        else {
        cout << "Invalid choice. Please choose 1 or 2." << endl;
        secondRoom();  // Recursion for invalid choice
    }



    } else if (choice == 2) {
        cout << "You decide to run, but you find yourself back at the starting point!" << endl;
        firstRoom();  // Recursion for running away and returning to start
    } else {
        cout << "Invalid choice. Please choose 1 or 2." << endl;
        secondRoom();  // Recursion for invalid choice
    }
}

// Main game loop
int main() {
    displayIntroduction();
    firstRoom();  // Call the first room function to start the game

    secondRoom();  // Progress to the second room after the first one

    char playAgain;
    cout << "Do you want to play again? (y/n): ";
    cin >> playAgain;

    if (playAgain == 'y' || playAgain == 'Y') {
        main();  // Recursion for restarting the game
    } else {
        cout << "Thanks for playing! Goodbye!" << endl;
    }
}
