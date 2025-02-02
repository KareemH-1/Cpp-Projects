#include <iostream>
using namespace std;
 
int main() {
    int n, count = 0;
    cin >> n;
    
     // Loop through each problem
    for (int i = 0; i < n; i++) {
        int petya, vasya, tonya;
        cin >> petya >> vasya >> tonya; // Read if each person is sure about the solution
 
        
        // If at least two of them are sure (sum >= 2), they will solve the problem
        if (petya + vasya + tonya >= 2) {
            count++; // Increase the count of problems they solve +1
        }
    }
 
    cout << count;
}