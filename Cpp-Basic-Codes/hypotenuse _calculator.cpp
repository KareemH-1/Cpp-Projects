#include<iostream>
#include <cmath>
using namespace std;

float hypotenuse(float base, float perpendicular) {
   int output;
   int under_root = (base * base) + (perpendicular * perpendicular);
    output = sqrt(under_root);
    return (output);
}