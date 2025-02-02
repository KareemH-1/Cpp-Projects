#include <iostream>
using namespace std;
 
int main() {
    int w;
    cin >> w;
    
    // Check if the weight is greater than 2 and is an even number
    if (w > 2 && w % 2 == 0) {
        cout << "YES" << endl; // If both conditions are met, they can split the watermelon
    }
    else {
        cout << "NO" << endl; // Otherwise, they can't split it as required
    }