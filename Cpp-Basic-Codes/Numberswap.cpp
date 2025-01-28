#include<iostream>

using namespace std;

void way1 (int a, int b){
    a = a + b;
    b = a - b;
    a = a - b;
    cout << "a: " << a << " b: " << b << endl;
}
void way2 (int a, int b){
    a = a * b;
    b = a / b;
    a = a / b;
    cout << "a: " << a << " b: " << b << endl;
}
void way3 (int a, int b){
    int c = a;
    a = b;
    b = c;
    cout << "a: " << a << " b: " << b << endl;
}

int main () {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    way1(a, b);
    way2(a, b);
    way3(a, b);
}