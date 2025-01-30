#include<iostream>
using namespace std;

int factorial(int n) {
    if(n == 0) {
        return (1);
    } else {
        for(int i = n - 1; i > 0; i--) {
            n =n * i;
        }
    }
}