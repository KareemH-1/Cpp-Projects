#include<iostream>
#include <cmath>
using namespace std;

float hypotenuse(float base, float perpendicular) {
   float output;
   float under_root = (base * base) + (perpendicular * perpendicular);
    output = sqrt(under_root);
    return (output);
}

int main() {
    float base, perpendicular;
    cout << "Enter the base of the triangle: ";
    cin >> base;
    cout << "Enter the perpendicular of the triangle: ";
    cin >> perpendicular;
    cout << "Hypotenuse of the triangle is: " << hypotenuse(base, perpendicular);
}