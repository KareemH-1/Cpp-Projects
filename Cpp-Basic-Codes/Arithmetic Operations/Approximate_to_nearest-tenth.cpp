#include<iostream>
#include<cmath>
using namespace std;

int main(){
    float number;
    cout << "Enter a number: ";
    cin >> number;
    number = round(number * 10) / 10;
    cout << "The number rounded to the nearest tenth is: " << number;
}