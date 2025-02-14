#include <iostream>
using namespace std;

void encryption(char x[]) 
{
	for (int i = 0; x[i] != '\0'; i++) 
	{
		if (x[i] == 'a') 
		{
			x[i] = '#';
		}
		else if (x[i] == 'A') 
		{
			x[i] = '@';
		}
		else if (x[i] == 'e') 
		{
			x[i] = '3';
		}
		else if (x[i] == 'E') 
		{
			x[i] = '8';
		}
		else if (x[i] == 'i') 
		{
			x[i] = '1';
		}
		else if (x[i] == 'I') 
		{
			x[i] = '!';
		}
		else if (x[i] == 'o') 
		{
			x[i] = '0';
		}
		else if (x[i] == 'O') 
		{
			x[i] = '*';
		}
		else if (x[i] == 's') 
		{
			x[i] = '5';
		}
		else if (x[i] == 'S') 
		{
			x[i] = '$';
		}
		else if (x[i] == 'g') 
		{
			x[i] = '&';
		}
		else if (x[i] == 'B') 
		{
			x[i] = '%';
		}
		else if (x[i] == 'l') 
		{
			x[i] = '|';
		}
		else if (x[i] == 't') 
		{
			x[i] = '^';
		}
	}
}

void decryption(char x[]) 
{
	for (int i = 0; x[i] != '\0'; i++) 
	{
		if (x[i] == '#') 
		{
			x[i] = 'a';
		}
		else if (x[i] == '@') 
		{
			x[i] = 'A';
		}
		else if (x[i] == '3') 
		{
			x[i] = 'e';
		}
		else if (x[i] == '8') 
		{
			x[i] = 'E';
		}
		else if (x[i] == '1') 
		{
			x[i] = 'i';
		}
		else if (x[i] == '!') 
		{
			x[i] = 'I';
		}
		else if (x[i] == '0') 
		{
			x[i] = 'o';
		}
		else if (x[i] == '*') 
		{
			x[i] = 'O';
		}
		else if (x[i] == '5') 
		{
			x[i] = 's';
		}
		else if (x[i] == '$') 
		{
			x[i] = 'S';
		}
		else if (x[i] == '&') 
		{
			x[i] = 'g';
		}
		else if (x[i] == '%') 
		{
			x[i] = 'B';
		}
		else if (x[i] == '|') 
		{
			x[i] = 'l';
		}
		else if (x[i] == '^') 
		{
			x[i] = 't';
		}
	}
}



int main() {
	int choice;
	cout << "Enter 1. to encrypt a sentence \nEnter 2. to decrypt a sentence" <<endl;
	cin >> choice;
	if (choice == 1) {
		char x[500];
		cout << "Please enter a sentence: ";
		cin >> ws;
		gets_s(x);
		encryption(x);
		cout << "Here is the encrypted sentence: \n" << x <<endl;
	}
	else if (choice == 2) {
		char x[500];
		cout << "Please enter a sentence: ";
		cin >> ws;
		gets_s(x);
		decryption(x);
		cout << "Here is the decrypted sentence: \n" << x <<endl;
	}
	else {
		cout << "Invalid choice! try again" <<endl;
		main();
	}
	
}