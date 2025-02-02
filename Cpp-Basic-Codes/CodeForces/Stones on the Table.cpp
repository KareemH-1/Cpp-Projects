#include <iostream>
using namespace std;

int main() {
	int num;
	string str;
	cin >> num;
	cin >> str;
	int count = 0;
	
	for (int i = 0; i < num; i++) {
		if (str[i] == str[i + 1]) {
			count++;
		}
	}
	cout << count;
	
}