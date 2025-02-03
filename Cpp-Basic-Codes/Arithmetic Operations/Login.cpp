#include<iostream>
using namespace std;

int main() {
    string username, password;
    cout << "=========================" << endl;
    cout << "==>   Registration   <==" << endl;
    cout << "=========================" << endl;

    cout << "Please create a username: ";
    cin >> username;
    cout << "Please create a password: ";
    cin >> password;

    cout << "-------------------------------------------------------" <<endl;
    cout << "Try logging in" << endl;
    cout << "---------------" << endl;
    
    string loginUser, loginPass;
    int attempts = 3;  // Limit the number of attempts

    while (attempts > 0) {
        cout << "\nPlease enter username: ";
        cin >> loginUser;
        cout << "Please enter password: ";
        cin >> loginPass;

        // Validate username and password
        if (loginUser != username && loginPass != password) {
            cout << "Both username and password are incorrect. You have " << --attempts << " attempts left." << endl;
        } else if (loginUser != username) {
            cout << "Incorrect username. You have " << --attempts << " attempts left." << endl;
        } else if (loginPass != password) {
            cout << "Incorrect password. You have " << --attempts << " attempts left." << endl;
        } else {
            cout << "Login successful! Welcome, " << username << "!" << endl;
            break;  // Exit the loop if login is successful
        }

        if (attempts == 0) {
            cout << "Sorry, you've used all your attempts!" << endl;
            return 0; // close the programme if the user fails to enter their credentials
        }
    }

    char changeChoice;
    while (true) {
        cout << endl<< "Would you like to change your username or password? (y/n): ";
        cin >> changeChoice;

        if (changeChoice == 'y' || changeChoice == 'Y' || changeChoice == 1) {
            int changeOption;
            cout << "Select an option: \n1. Change Username \n2. Change Password \nYour choice: ";
            cin >> changeOption;

            if (changeOption == 1) {
                cout << "Enter new username: ";
                cin >> username;
                cout << "Username changed successfully!" << endl;
            } else if (changeOption == 2) {
                cout << "Enter new password: ";
                cin >> password;
                cout << "Password changed successfully!" << endl;
            } else {
                cout << "Invalid choice. Please select 1 or 2." << endl;
            }
        } else if (changeChoice == 'n' || changeChoice == 'N') {
            cout << "Exiting... Thank you!" << endl;
            break; // Exit the loop if the user doesn't want to change their username/password
        } else {
            cout << "Invalid input. Please enter 'y' or 'n'." << endl;
        }
    }
}
