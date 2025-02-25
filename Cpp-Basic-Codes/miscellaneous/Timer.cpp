#include <iostream>
#include <thread>
#include <chrono>
using namespace std;
int main() {
  
        cout << "==========================" << endl;
        cout << "           Timer          " << endl;
		cout << "==========================" << endl;
        cout << "Enter (Q to Quit) or (S to start)" << endl;
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
			for (;;) {
				

				cout << hours << " : " << minutes << " : " << dispSeconds << endl;
				this_thread::sleep_for(chrono::seconds(1)); //sleep for 1 second
				seconds++; //after 1 second of sleeping , increment the seconds variable
				dispSeconds++; // increment the displaying Seconds variable
				if (seconds % 60 == 0) { //if condition to check if seconds are divisible by 60 and if they are then increment minutes and readdress disseconds to 0
					minutes++;
					dispSeconds = 0;
				}
				if (minutes % 60 == 0 && minutes !=0) {
					hours++;
					minutes = 0;
				}
				
				system("cls"); //clear screen everytime
			}
		}
		
		else {
			cout << "Invalid input!" << endl;
			return 0;
		}
}
