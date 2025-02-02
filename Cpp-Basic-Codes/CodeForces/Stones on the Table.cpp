#include <iostream>
using namespace std;

int main() {
	int num;
	string str;
	cin >> num;
	cin >> str;
	int count = 0; // Start the counter with 0 to track how many stones need to be removed
	
    // Loop through the string and compare each stone with the next one
	for (int i = 0; i < num; i++) {
	  if (str[i] == str[i + 1]) {  // If two consecutive stones have the same color
      count++;  // Increment the counter
      }
	}
	cout << count;
	
}