#include <iostream>
using namespace std;

int main(){
	string name;
	int choice;
	int candidates = 1;
	int maxvotes =-99999999999;
	int posmax;
	string maxname;
	for (;;) {
		int votes = 0;
		if (candidates > 2) {
			cout << "\nDo you want to add another candidate? ( (1) for yes, (0) for no)" << endl;
			cin>>choice;
			if (choice == 0) {
				break;
			}
		}
		cout << "Enter the name of the candidate number " << candidates << ": ";
		cin >> name;
		cout << "Enter the number of votes for candidate (" <<candidates <<") "<< name << ": ";
		cin >> votes;
		if(votes > maxvotes) {
			maxvotes = votes;
			maxname = name;
			posmax = candidates;
		}
		candidates++;
	}

	cout << "\n-----------------------" << endl;
	cout << "The winning candidate is candidate ("<<posmax <<") " << maxname << " with " << maxvotes << " votes." << endl;

}