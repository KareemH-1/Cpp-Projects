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
        }
    }
}
