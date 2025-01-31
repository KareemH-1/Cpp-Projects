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

// Function for ellipse
void ellipse(float a, float b, float &Area, float &Per) {
    Area = 3.14159265359 * a * b;  // Area = π * a * b
    Per = 2 * 3.14159265359 * sqrt((a * a + b * b) / 2);  // Approximate Perimeter of ellipse
}

// Function for semi-circle
void semicircle(float radius, float &Area, float &Per) {
    Area = (3.14159265359 * radius * radius) / 2;  // Area = π * r^2 / 2
    Per = 3.14159265359 * radius + 2 * radius;     // Perimeter = π * r + 2 * r (straight edge + curved edge)
}

// Function for pentagon (regular)
void pentagon(float s, float &Area, float &Per) {
    Area = (5 * s * s) / (4 * tan(3.14159265359 / 5));  // Area of regular pentagon
    Per = 5 * s;  // Perimeter = 5 * side length
}

// Function for hexagon (regular)
void hexagon(float s, float &Area, float &Per) {
    Area = (3 * sqrt(3) * s * s) / 2;  // Area of regular hexagon
    Per = 6 * s;  // Perimeter = 6 * side length
}

// Function for octagon (regular)
void octagon(float s, float &Area, float &Per) {
    Area = 2 * (1 + sqrt(2)) * s * s;  // Area of regular octagon
    Per = 8 * s;  // Perimeter = 8 * side length
}


// Function for sector of a circle
void sectorOfCircle(float radius, float angle, float &Area, float &Per) {
    Area = (3.14159265359 * radius * radius * angle) / 360;  // Area = π * r^2 * (angle / 360)
    Per = 2 * radius + 2 * (3.14159265359 * radius * angle) / 360;  // Perimeter = 2r + arc length
}

// Function for lune (area between two intersecting circles)
void lune(float radius1, float radius2, float angle, float &Area, float &Per) {
    Area = (3.14159265359 * radius1 * radius1 * angle / 360) - (3.14159265359 * radius2 * radius2 * angle / 360);  // Lune area formula
    Per = 2 * (3.14159265359 * radius1 * angle / 360);  // Perimeter is approximately the arc length
}

// Function for heart shape
void heartShape(float a, float &Area, float &Per) {
    Area = 3.14159265359 * a * a * (16 / 15);  // Approximate formula for heart-shaped area
    Per = 2 * 3.14159265359 * a;  // Perimeter approximation
}

// Function for kite
void kite(float d1, float d2, float side, float &Area, float &Per) {
    Area = (d1 * d2) / 2;  // Area of kite = (Diagonal1 * Diagonal2) / 2
    Per = 2 * (side + side);  // Perimeter = 2 * (side1 + side2)
}

// Function for annulus (area between two concentric circles)
void annulus(float radius1, float radius2, float &Area, float &Per) {
    Area = 3.14159265359 * (radius1 * radius1 - radius2 * radius2);  // Area of annulus
    Per = 2 * 3.14159265359 * (radius1 + radius2);  // Perimeter = circumference of both circles
}

// Function for parabola
void parabola(float a, float b, float &Area, float &Per) {
    // Simplified area of parabola using integral approximation
    Area = (1 / 3.0) * a * b * b;  // Approximation for the area under a parabola y = ax^2
    Per = 2 * sqrt(a * b);  // Approximation for perimeter formula (non-standard, for approximation purposes)
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
            cout << "   9. Ellipse" << endl;
            cout << "   10. Semi-Circle" << endl;
            cout << "   11. Pentagon (Regular)" << endl;
            cout << "   12. Hexagon (Regular)" << endl;
            cout << "   13. Octagon (Regular)" << endl;
            cout << "   14. Sector of Circle" << endl;
            cout << "   15. Lune" << endl;
            cout << "   16. Heart Shape" << endl;
            cout << "   17. Kite" << endl;
            cout << "   18. Annulus" << endl;
            cout << "   19. Parabola" << endl;
            cout << "=============================================" << endl;
            cout << "Choose a shape from the previous table: ";
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

              else if (shape == "ellipse" || shape == "Ellipse" || shape == "9" || shape == "elipse" || shape == "elliptical") {
                float a, b;
                cout << "Enter the semi-major axis of the ellipse: ";
                cin >> a;
                cout << "Enter the semi-minor axis of the ellipse: ";
                cin >> b;
                ellipse(a, b, area, per);
                cout << "-------------------------------------------" << endl;
                cout << "Area of ellipse equals " << area << endl;
                cout << "Perimeter of ellipse equals " << per << endl << endl;
            }

            else if (shape == "semi-circle" || shape == "Semi-circle" || shape == "10" || shape == "semi circle") {
                float radius;
                cout << "Enter the radius of the semi-circle: ";
                cin >> radius;
                semicircle(radius, area, per);
                cout << "-------------------------------------------" << endl;
                cout << "Area of semi-circle equals " << area << endl;
                cout << "Perimeter of semi-circle equals " << per << endl << endl;
            }

            else if (shape == "pentagon" || shape == "Pentagon" || shape == "11" || shape == "penta" || shape == "regular pentagon") {
                float s;
                cout << "Enter the side length of the pentagon: ";
                cin >> s;
                pentagon(s, area, per);
                cout << "-------------------------------------------" << endl;
                cout << "Area of pentagon equals " << area << endl;
                cout << "Perimeter of pentagon equals " << per << endl << endl;
            }

              else if (shape == "hexagon" || shape == "Hexagon" || shape == "12" || shape == "hexa" || shape == "regular hexagon") {
                float s;
                cout << "Enter the side length of the hexagon: ";
                cin >> s;
                hexagon(s, area, per);
                cout << "-------------------------------------------" << endl;
                cout << "Area of hexagon equals " << area << endl;
                cout << "Perimeter of hexagon equals " << per << endl << endl;
            }

            else if (shape == "octagon" || shape == "Octagon" || shape == "13" || shape == "octa" || shape == "regular octagon") {
                float s;
                cout << "Enter the side length of the octagon: ";
                cin >> s;
                octagon(s, area, per);
                cout << "-------------------------------------------" << endl;
                cout << "Area of octagon equals " << area << endl;
                cout << "Perimeter of octagon equals " << per << endl << endl;
            }
            

             else if (shape == "sector of circle" || shape == "Sector of Circle" || shape == "14" || shape == "sector" || shape == "Sector") {
                float radius, angle;
                cout << "Enter the radius of the circle: ";
                cin >> radius;
                cout << "Enter the central angle (in degrees): ";
                cin >> angle;
                sectorOfCircle(radius, angle, area, per);
                cout << "-------------------------------------------" << endl;
                cout << "Area of sector equals " << area << endl;
                cout << "Perimeter of sector equals " << per << endl << endl;
            }

            else if (shape == "lune" || shape == "Lune" || shape == "15") {
                float radius1, radius2, angle;
                cout << "Enter the radius of the first circle: ";
                cin >> radius1;
                cout << "Enter the radius of the second circle: ";
                cin >> radius2;
                cout << "Enter the angle (in degrees): ";
                cin >> angle;
                lune(radius1, radius2, angle, area, per);
                cout << "-------------------------------------------" << endl;
                cout << "Area of lune equals " << area << endl;
                cout << "Perimeter of lune equals " << per << endl << endl;
            }

            else if (shape == "heart shape" || shape == "Heart Shape" || shape == "16" || shape == "Heart" || shape == "heart") {
                float a;
                cout << "Enter the size parameter for the heart shape: ";
                cin >> a;
                heartShape(a, area, per);
                cout << "-------------------------------------------" << endl;
                cout << "Area of heart shape equals " << area << endl;
                cout << "Perimeter of heart shape equals " << per << endl << endl;
            }

            else if (shape == "kite" || shape == "Kite" || shape == "17") {
                float d1, d2, side;
                cout << "Enter the first diagonal of the kite: ";
                cin >> d1;
                cout << "Enter the second diagonal of the kite: ";
                cin >> d2;
                cout << "Enter the length of the side of the kite: ";
                cin >> side;
                kite(d1, d2, side, area, per);
                cout << "-------------------------------------------" << endl;
                cout << "Area of kite equals " << area << endl;
                cout << "Perimeter of kite equals " << per << endl << endl;
            }

            else if (shape == "annulus" || shape == "Annulus" || shape == "18") {
                float radius1, radius2;
                cout << "Enter the outer radius of the annulus: ";
                cin >> radius1;
                cout << "Enter the inner radius of the annulus: ";
                cin >> radius2;
                annulus(radius1, radius2, area, per);
                cout << "-------------------------------------------" << endl;
                cout << "Area of annulus equals " << area << endl;
                cout << "Perimeter of annulus equals " << per << endl << endl;
            }

            else if (shape == "parabola" || shape == "Parabola" || shape == "19") {
                float a, b;
                cout << "Enter the coefficient a for the parabola: ";
                cin >> a;
                cout << "Enter the coefficient b for the parabola: ";
                cin >> b;
                parabola(a, b, area, per);
                cout << "-------------------------------------------" << endl;
                cout << "Area under parabola equals " << area << endl;
                cout << "Perimeter of parabola equals " << per << endl << endl;
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
