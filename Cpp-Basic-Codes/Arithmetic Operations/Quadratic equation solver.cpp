#include <iostream>
#include <cmath>
using namespace std;


void display(double a, double b, double c){
    cout<<"Your equation is: "<<a<<"x^2 + "<<b<<"x + "<<c<<" = 0"<<endl;
}

int main(){
    double a, b, c;
    cout << "Enter coefficients a, b, and c: ";
    cin >> a >> b >> c;
    display(a, b, c);

    // Calculate the discriminant
    double D = (b * b) - (4 * a * c);

      // Check the nature of the roots
      if (D > 0) {
        double root1 = (-b + sqrt(D)) / (2 * a);
        double root2 = (-b - sqrt(D)) / (2 * a);
        cout << "Roots are real and different: " << root1 << " and " << root2 << endl;
    } 
    else if (D == 0) {
        double root = -b / (2 * a);
        cout << "Roots are real and the same: " << root << endl;
    } 
    else {
        double realPart = -b / (2 * a);
        double imaginaryPart = sqrt(-D) / (2 * a);
        cout << "Roots are complex: " << realPart << " + " << imaginaryPart << "i and " 
             << realPart << " - " << imaginaryPart << "i" << endl;
    }

}