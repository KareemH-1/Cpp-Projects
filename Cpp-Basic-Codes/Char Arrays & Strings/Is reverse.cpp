#include <iostream>
using namespace std;

int main() {
    string s, t;
    cout << "Enter a string: ";
    cin >> s;

    cout << "Enter another string: ";
    cin >> t;

    int n = s.length();
    if (n != t.length()) {
        cout << "NO";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        if (s[i] != t[n - 1 - i]) {
            cout << "NO";
            return 0;
        }
    }
    
    cout << "YES";
}
