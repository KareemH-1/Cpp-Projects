#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Function for square
void square(float L, float &Area, float &Per) {
    Area = L * L;
    Per = L * 4;
}

// Function for rectangle
void rectangle(float L, float W, float &Area, float &Per) {
    Area = L * W;
    Per = 2 * (L + W);
}

// Function for right-angled triangle
void rightangletriangle(float base, float height, float &Area, float &Per) {
    Area = (base * height) / 2;
    
    float hypotenuse = sqrt(base * base + height * height);
    Per = base + height + hypotenuse;
}

// Function for normal triangle (equilateral)
void normalTriangle(float base, float height, float &Area, float &Per) {
    Area = (base * height) / 2;
    // Perimeter of an equilateral triangle: 3 * base
    Per = 3 * base;
}

// Function for circle
void circle(float radius, float &Area, float &Per) {
    Area = 3.14159265359 * radius * radius;  // Area = π * r^2
    Per = 2 * 3.14159265359 * radius;        // Perimeter (Circumference) = 2 * π * r
}

int main() {
    cout << "===================================" << endl;
    cout << "     SHAPE METRICS CALCULATOR      " << endl;
    cout << "===================================" << endl << endl;

    int choice;
    string shape;
    float area , per;
    for (;;) {
        cout << "Choose 1 to continue or 0 to stop: ";
        cin >> choice;
        cout << "-----------------------------------" << endl << endl;
        if (choice == 0) {
            break;
        }
        else if (choice == 1) {
            cout << "=============================================" << endl;
            cout << " Choose a shape from the following options: " << endl;
            cout << "-------------------------------------------" << endl;
            cout << "   1. Square" << endl;
            cout << "   2. Rectangle" << endl;
            cout << "   3. Right-Angled Triangle" << endl;
            cout << "   4. Equilateral Triangle" << endl;
            cout << "   5. Circle" << endl;
            cout << "=============================================" << endl;

            cin >> shape;

            if (shape == "Square" || shape == "square") {
                float L;
                cout << "Enter the length of the square: ";
                cin >> L;
                square(L, area, per);
                cout << "-------------------------------------------" << endl;
                cout << "Area of square equals " << area << endl;
                cout << "Perimeter of square equals " << per << endl << endl;
            }
            else if (shape == "rectangle" || shape == "Rectangle") {
                float L, W;
                cout << "Enter the length of the rectangle: ";
                cin >> L;
                cout << "Enter the width of the rectangle: ";
                cin >> W;
                rectangle(L, W, area, per);
                cout << "-------------------------------------------" << endl;
                cout << "Area of rectangle equals " << area << endl;
                cout << "Perimeter of rectangle equals " << per << endl << endl;
            }
            else if (shape == "right-angled triangle" || shape == "Right-angled triangle" || shape == "right angle triangle" || shape == "Right angle triangle" || shape == "right triangle" || shape == "Right triangle") {
                float base, height;
                cout << "Enter the base of the triangle: ";
                cin >> base;
                cout << "Enter the height of the triangle: ";
                cin >> height;
                rightangletriangle(base, height, area, per);
                cout << "-------------------------------------------" << endl;
                cout << "Area of right-angled triangle equals " << area << endl;
                cout << "Perimeter of right-angled triangle equals " << per << endl << endl;
            }
            else if (shape == "equilateral triangle" || shape == "Equilateral triangle" || shape == "triangle" || shape == "Triangle" || shape == "Equilateral" || shape == "equilateral") {
                float base, height;
                cout << "Enter the base of the normal triangle: ";
                cin >> base;
                cout << "Enter the height of the normal triangle: ";
                cin >> height;
                normalTriangle(base, height, area, per);
                cout << "-------------------------------------------" << endl;
                cout << "Area of equilateral triangle equals " << area << endl;
                cout << "Perimeter of equilateral triangle equals " << per << endl << endl;
            }
            else if (shape == "circle" || shape == "Circle") {
                float radius;
                cout << "Enter the radius of the circle: ";
                cin >> radius;
                circle(radius, area, per);
                cout << "-------------------------------------------" << endl;
                cout << "Area of circle equals " << area << endl;
                cout << "Perimeter (Circumference) of circle equals " << per << endl << endl;
            }
        }
        else {
            cout << "Invalid choice." << endl;
        }
    }

    return 0;
}
