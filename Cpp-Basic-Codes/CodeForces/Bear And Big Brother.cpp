#include <iostream>
using namespace std;

int main() {
    int a, b;
    int years = 0;

    cin >> a >> b;  

    // multiplying a by 3 and b by 2 until both are equal to each others
    while (a <= b) { 
        a = a * 3;
        b = b * 2; 
        years++;    
    }


    cout << years;  
}
