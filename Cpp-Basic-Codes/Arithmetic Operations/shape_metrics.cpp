// Geometric Calculator  
// This program allows users to compute the area and perimeter of various shapes.  
// Users select a shape, provide necessary dimensions, and receive calculated results.  
// Supported shapes include circles, rectangles, and triangles.  


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

// Function for rhombus
void rhombus(float d1, float d2, float &Area, float &Per) {
    Area = (d1 * d2) / 2;  // Area = (Diagonal1 * Diagonal2) / 2
    Per = 4 * d1;           // Perimeter = 4 * side length (assuming all sides are equal)
}

// Function for parallelogram
void parallelogram(float base, float height, float &Area, float &Per) {
    Area = base * height;  // Area = base * height
    Per = 2 * (base + height);  // Perimeter = 2 * (base + height)
}

// Function for trapezium
void trapezium(float a, float b, float height, float &Area, float &Per) {
    Area = ((a + b) * height) / 2;  // Area = (a + b) * height / 2
    Per = a + b + height + sqrt(height * height + (b - a) * (b - a));  // Perimeter = sum of sides
}

int main() {
    cout << "===================================" << endl;
    cout << "     SHAPE METRICS CALCULATOR      " << endl;
    cout << "===================================" << endl << endl;

    int choice;
    string shape;
    float area, per;
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
            cout << "   6. Rhombus" << endl;
            cout << "   7. Parallelogram" << endl;
            cout << "   8. Trapezium" << endl;
            cout << "=============================================" << endl;

            cin >> shape;

            if (shape == "Square" || shape == "square" || shape == "1" || shape == "sq" || shape == "Square Shape" || shape == "s") {
                float L;
                cout << "Enter the length of the square: ";
                cin >> L;
                square(L, area, per);
                cout << "-------------------------------------------" << endl;
                cout << "Area of square equals " << area << endl;
                cout << "Perimeter of square equals " << per << endl << endl;
            }


            else if (shape == "rectangle" || shape == "Rectangle" || shape == "2" || shape == "rect" || shape == "Rectangle Shape" || shape == "r") {
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


            else if (shape == "right-angled triangle" || shape == "Right-angled triangle" || shape == "right angle triangle" || shape == "Right angle triangle" || shape == "right triangle" || shape == "Right triangle" || shape == "3" || shape == "rt triangle") {
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


            else if (shape == "equilateral triangle" || shape == "Equilateral triangle" || shape == "triangle" || shape == "Equilateral" || shape == "equilateral" || shape == "4" || shape == "eq triangle") {
                float base, height;
                cout << "Enter the base of the normal triangle: ";
                cin >> base;
                cout << "Enter the height of the normal triangle: ";
                cin >> height;
                normalTriangle(base, height, area, per);
                cout << "Area of equilateral triangle equals " << area << endl;
                cout << "Perimeter of equilateral triangle equals " << per << endl << endl;
            }


            else if (shape == "circle" || shape == "Circle" || shape == "5" || shape == "circ" || shape == "Circle Shape" || shape == "c") {
                float radius;
                cout << "Enter the radius of the circle: ";
                cin >> radius;
                circle(radius, area, per);
                cout << "Area of circle equals " << area << endl;
                cout << "Perimeter (Circumference) of circle equals " << per << endl << endl;
            }


            else if (shape == "rhombus" || shape == "Rhombus" || shape == "6" || shape == "rhombus shape" || shape == "rhm" || shape == "diamond") {
                float d1, d2;
                cout << "Enter the first diagonal of the rhombus: ";
                cin >> d1;
                cout << "Enter the second diagonal of the rhombus: ";
                cin >> d2;
                rhombus(d1, d2, area, per);
                cout << "-------------------------------------------" << endl;
                cout << "Area of rhombus equals " << area << endl;
                cout << "Perimeter of rhombus equals " << per << endl << endl;
            }


            else if (shape == "parallelogram" || shape == "Parallelogram" || shape == "7" || shape == "parallelogram shape" || shape == "para") {
                float base, height;
                cout << "Enter the base of the parallelogram: ";
                cin >> base;
                cout << "Enter the height of the parallelogram: ";
                cin >> height;
                parallelogram(base, height, area, per);
                cout << "-------------------------------------------" << endl;
                cout << "Area of parallelogram equals " << area << endl;
                cout << "Perimeter of parallelogram equals " << per << endl << endl;
            }


            else if (shape == "trapezium" || shape == "Trapezium" || shape == "8" || shape == "trap" || shape == "Trapezoid" || shape == "trapezoid") {
                float a, b, height;
                cout << "Enter the first base of the trapezium: ";
                cin >> a;
                cout << "Enter the second base of the trapezium: ";
                cin >> b;
                cout << "Enter the height of the trapezium: ";
                cin >> height;
                trapezium(a, b, height, area, per);
                cout << "-------------------------------------------" << endl;
                cout << "Area of trapezium equals " << area << endl;
                cout << "Perimeter of trapezium equals " << per << endl << endl;
            }
            else {
                cout << "Invalid choice , try again." << endl;
            }
        }
        else {
            cout << "Invalid choice." << endl;
        }
    }

}
