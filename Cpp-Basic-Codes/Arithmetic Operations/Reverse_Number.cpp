#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int reverse = 0;
    int lastdigit;

    for(;n>0;){
        lastdigit = n%10;
        reverse = reverse*10 + lastdigit;
        n = n/10;
    }
    cout << "The reverse of the number is: " << reverse << endl;
}