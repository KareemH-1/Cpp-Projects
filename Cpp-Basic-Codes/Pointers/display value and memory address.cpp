#include<iostream>
using namespace std;

int main(){
    int val;
    cout << "Enter a number: ";
    cin>> val;

    int *ptr = &val;
    
    cout << "Way1: \nValue: " << val << endl;
    cout << "Way2: \nValue: " << *ptr << endl <<endl;
    cout << "way1: \nMemory Address: " << ptr << endl;
    cout << "way2: \nMemory Address: " << &val << endl;
}
