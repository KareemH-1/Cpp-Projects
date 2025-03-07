#include <iostream>
using namespace std;

void sum(int k) {
	int ct = 0;
	int x, y, z;
	for (x = 0; x <= k; x++) {
		for (y = 0; y <= k; y++) {
			for (z = 0; z <= k; z++) {
				if (x + y + z == k) {
					cout << x << " " << y << " " << z << endl;
					ct++;
				}
			}
		}
	}

	cout << "There are " << ct << " possibilities for adding 3 numbers to form " << k << endl;
}

void product(int k) {
	int ct = 0;
	int x, y, z;
	for (x = 0; x <= k; x++) {
		for (y = 0; y <= k; y++) {
			for (z = 0; z <= k; z++) {
				if (x * y * z == k) {
					cout << x << " " << y << " " << z << endl;
					ct++;
				}
			}
		}
	}

	cout << "There are " << ct << " possibilities for multiplying 3 numbers to form " << k << endl;
}

int main() {
	int k;
	cout << "Enter a number: ";
	cin >> k;
	string choice; 
	cout << "Enter choice (1 for sum and 2 for product): ";
	cin >> choice;

	if(choice == "sum"|| choice == "Sum" || choice == "1" || choice == "SUM" || choice == "s" || choice == "S") {
		sum(k);
	}
	else if(choice == "product" || choice == "Product" ||choice == "2" || choice == "PRODUCT" || choice == "p" || choice == "P") {
		product(k);
	}
	else{
		cout << "Invalid choice" << endl;
	}

}