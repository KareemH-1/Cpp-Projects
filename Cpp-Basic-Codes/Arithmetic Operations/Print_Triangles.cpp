#include <iostream>
using namespace std;
 
int main()
{
    for(;;){

    int choice;
    cout << "Enter 1 to continue or 0 to exit: ";
    cin >> choice;

    if (choice == 0){
        break;
    }
    cout << endl;
    cout << "=============================" << endl<<endl;
     int n;
    cout << "Enter the number of rows: ";
    cin >> n;
    cout << endl;
    cout << "-----------------------------" << endl;
    char shape;
    cout << "Enter shape of component: ";
    cin>> shape;
    cout << endl;
    cout << "-----------------------------" << endl << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++)
            cout << shape;
        cout << endl << endl;
        }
    }
}