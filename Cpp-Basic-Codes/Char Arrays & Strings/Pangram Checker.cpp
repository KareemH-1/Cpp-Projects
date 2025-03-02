#include <iostream>
#include <string>
using namespace std;

int main() {
    char alphapet[26] = {'a' , 'b' , 'c' , 'd' , 'e' , 'f' , 'g' , 'h' , 'i' , 'j' , 'k' , 'l' , 'm' , 'n' , 'o' , 'p' , 'q' , 'r' , 's' , 't' , 'u' , 'v' , 'w' , 'x' , 'y' , 'z'};
    int found[26] = {0};

    cout << "Please enter a string: ";
    string s;
    cin >> s;

    if (s.length() < 26) {
        cout << "NO" << endl;
    }

	else {
		for (int i = 0; i < s.length(); i++) {
			if (s[i] >= 'A' && s[i] <= 'Z') {
				s[i] = s[i] + 32;
			}
		}
		for (int i = 0; i < s.length(); i++) {
			for (int j = 0; j < 26; j++) {
				if (s[i] == alphapet[j]) {
					found[j] = 1;
				}
			}
		}
		int ctgood = 1;
		for (int i = 0; i < 26; i++) {
			if (found[i] == 0) {
				ctgood = 0;
				break;
			}
		}
		if (ctgood == 0) {
			cout << "NO" << endl;

		}
		else {
			cout << "YES" << endl;
		}
	}

}
