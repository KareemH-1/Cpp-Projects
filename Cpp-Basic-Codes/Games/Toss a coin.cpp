#include <iostream>
#include <ctime>

using namespace std;
// Function to generate a random number between 1 and 2, where:
// 1 heads and 2 = tails
int randomnum() {
    return ((rand() % 2) + 1); // Generate a number between 1 and 2
}

int main() {
    srand(time(0)); // Initialize the random number generator with a seed based on the current time

    // Display game title and instructions
    cout << "===========================================" << endl;
    cout << "              Heads Or Tails!              " << endl;
    cout << "===========================================" << endl << endl;
    string choice;
    int firstround=1;
    while(true){

        if (firstround ==1){
            cout << "Do you wish to toss the coin now (Yes/No)?  :";
            cin>> choice;
            firstround=0;
        }
        else{
            cout << "Do you want to continue tossing the coin( Yes/No)? :";
            cin>> choice;
        }

        if (choice == "N" || choice == "n" || choice == "No" || choice == "not" || choice == "no" || choice == "NO" || choice == "0"  ){
            break;
        } 
        else{
            int move = randomnum();

            if(move == 1){
                cout << "Its Heads!" << endl;
                cout << "===========================================" << endl;
            }
            else{
                cout<< "Its Tails!" <<endl;
                cout << "===========================================" << endl;
            }
        }
    }
        cout<< "The game has ended!" <<endl;
}