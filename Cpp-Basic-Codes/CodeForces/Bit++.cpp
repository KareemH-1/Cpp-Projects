#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n;  // Input the number of operations
    int x = 0;

    // Loop through each operation
    for (int i = 0; i < n; i++) {
        cin >> s;  // Input the operation

        // Adjust x based on the operation
        if (s == "X++" || s == "++X") {
            x++;  // Increase x by 1
        }
        if (s == "X--" || s == "--X") {
            x--;  // Decrease x by 1
        }
    }

    cout << x;  // Output the final value of x
}
