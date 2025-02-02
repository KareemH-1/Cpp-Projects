#include <iostream>
#include <string>
using namespace std;
 
int main() {
    int n;
    cin >> n;
 
        // Loop through each word
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word; 

        // If the word length is greater than 10:
        if (word.length() > 10) {
            // Word: first letter + number of middle letters + last letter
            cout << word.front() << word.length() - 2 << word.back() << "\n";
        }
        else {
            // If word length is 10 or less, print it as is
            cout << word << endl;
        }
    }
}