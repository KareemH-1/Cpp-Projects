#include <iostream>
using namespace std;

float Area (float r) {
    return (3.14 * r * r);
}

float Circumference (float r) {
    return (2 * 3.14 * r);
}

int main() {
    float r;
    
    for(;;){
        int choice;
        float r;
        cout << "Welcome to the Area and Circumference calculator!" << endl;
        cout << "================================================" << endl;
        cout << "Enter 0 to exit the program." << endl;
        cout << "----------------------------" << endl;
        cout << "Enter 1 to calculate the area of the circle" << endl;
        cout << "----------------------------" << endl;
        cout << "Enter 2 to calculate the circumference of the circle" << endl;
        cout << "----------------------------" << endl;
        cout << "Enter 3 to calculate both the area and circumference of the circle" << endl;
        cout << "----------------------------" << endl;
        cout << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 0){
            break;
        }
        else{
        cout << "Enter the radius of the circle: ";
        cin >> r;
        if (choice == 1){
        cout << "Area of the circle is: " << Area(r) << endl;
        cout << endl;
        }
        else if (choice == 2){
        cout << "Circumference of the circle is: " << Circumference(r) << endl;
        cout << endl;
        }
        else if (choice == 3){
        cout << "Area of the circle is: " << Area(r) << endl;
        cout << "Circumference of the circle is: " << Circumference(r) << endl;
        cout << endl;
        }
       }
       cout << "================================================" << endl;
       cout << endl;
    }
}