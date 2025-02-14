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
    cout << "way2: \nMemory Address: " << &val;

    cout << "\n \n";

    cout << "Enter an array of 5 numbers ";
    int testarr[5];
    for (int i = 0; i < 5; i++) {
        cin >> testarr[i];
    }
    int *ptr1 = testarr; //being first index by default
    cout << "Memory Address of first index: " << ptr1 << endl;
    cout << "Memory Address of second index: " << ptr1 + 1 << endl;
    cout << "Memory Address of third index: " << ptr1 + 2 << endl;
    cout << "Memory Address of fourth index: " << ptr1 + 3 << endl;
    cout << "Memory Address of fifth index: " << ptr1 + 4 << endl;

}
