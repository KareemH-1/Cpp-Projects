#include <iostream>
#include <thread>
#include <chrono>
#include <conio.h>  // For _kbhit() and _getch() (Windows-only)

using namespace std;

int main() {
    cout << "==========================" << endl;
    cout << "           Timer          " << endl;
    cout << "==========================" << endl;
    cout << "Enter (Q to Quit) or (S to Start)" << endl;

    char choice;
    cin >> choice;

    if (choice == 'Q' || choice == 'q') {
        cout << "Quitting..." << endl;
        return 0;
    } 
    else if (choice == 'S' || choice == 's') {
        cout << "Starting..." << endl;
        this_thread::sleep_for(chrono::seconds(1));
        system("cls");

        int seconds = 0, minutes = 0, hours = 0;
        int dispSeconds = 0;
        bool paused = false;

        for (;;) {
            system("cls"); // Clear screen before displaying options and timer
            cout << "==========================" << endl;
            cout << "       Timer Running      " << endl;
            cout << "==========================" << endl;
            cout << "[P] Pause  |  [C] Continue  |  [Q] Quit" << endl;
            cout << "--------------------------------------" << endl;
            
            if (paused) { 
                cout << "\nPaused. Press 'C' to continue..." << endl;
            } else {
                cout <<endl<< hours << " : " << minutes << " : " << dispSeconds << endl;
            }

            if (_kbhit()) { // Check if a key is pressed
                char key = _getch(); // Get the key

                if (key == 'p' || key == 'P') { // If user presses 'p', pause the timer
                    paused = true;
                } 
                else if (key == 'c' || key == 'C') { // If user presses 'c', resume the timer
                    paused = false;
                } 
                else if (key == 'q' || key == 'Q') { // If user presses 'q', quit the program
                    cout << "\nQuitting..." << endl;
                    return 0;
                }
            }

            if (!paused) { // Run the timer only when it's not paused
                this_thread::sleep_for(chrono::seconds(1)); // Sleep for 1 second
                seconds++; // After 1 second of sleeping, increment the seconds variable
                dispSeconds++; // Increment the displaying Seconds variable

                if (seconds % 60 == 0) { // If seconds are divisible by 60, increment minutes and reset dispSeconds
                    minutes++;
                    dispSeconds = 0;
                }
                if (minutes % 60 == 0 && minutes != 0) { // If minutes are divisible by 60, increment hours and reset minutes
                    hours++;
                    minutes = 0;
                }
            }
        }
    } 
    else {
        cout << "Invalid input!" << endl;
        return 0;
    }
}
