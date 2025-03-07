#include <iostream>
#include <climits>
using namespace std;

int main() {
	while (true) {
			cout << "===============================================" << endl;
			cout << "==== Choose a data type to show its limits ====" << endl;
			cout << "===============================================" << endl;
			cout << "1. int" << endl;
			cout << "2. long" << endl;
			cout << "3. long long" << endl;
			cout << "4. float" << endl;
			cout << "5. double" << endl;
			cout << "6. long double" << endl;
			cout << "7. char" << endl;
			cout << "8. wchar_t" << endl;
			cout << "9. bool" << endl;
			cout << "10. short" << endl;
			cout << "11. unsigned int" << endl;
			cout << "12. unsigned long" << endl;
			cout << "13. unsigned long long" << endl;
			cout << "14. unsigned char" << endl;
			cout << "15. unsigned short" << endl;
			cout << "-----------------------------------------------" << endl;

			int choice;
			cin >> choice;
			switch (choice) {
			case 1:
				cout << "int: " << INT_MIN << " to " << INT_MAX << endl;
				break;

			case 2:
				cout << "long: " << LONG_MIN << " to " << LONG_MAX << endl;
				break;

			case 3:
				cout << "long long: " << LLONG_MIN << " to " << LLONG_MAX << endl;
				break;

			case 4:
				cout << "float: " << FLT_MIN << " to " << FLT_MAX << endl;
				break;

			case 5:
				cout << "double: " << DBL_MIN << " to " << DBL_MAX << endl;
				break;

			case 6:
				cout << "long double: " << LDBL_MIN << " to " << LDBL_MAX << endl;
				break;

			case 7:
				cout << "char: " << CHAR_MIN << " to " << CHAR_MAX << endl;
				break;

			case 8:
				cout << "wchar_t: " << WCHAR_MIN << " to " << WCHAR_MAX << endl;
				break;

			case 9:
				cout << "bool: " << false << " or " << true << endl;
				break;

			case 10:
				cout << "short: " << SHRT_MIN << " to " << SHRT_MAX << endl;
				break;

			case 11:
				cout << "unsigned int: " << 0 << " to " << UINT_MAX << endl;
				break;

			case 12:
				cout << "unsigned long: " << 0 << " to " << ULONG_MAX << endl;
				break;

			case 13:
				cout << "unsigned long long: " << 0 << " to " << ULLONG_MAX << endl;
				break;

			case 14:
				cout << "unsigned char: " << 0 << " to " << UCHAR_MAX << endl;
				break;

			case 15:
				cout << "unsigned short: " << 0 << " to " << USHRT_MAX << endl;
				break;

			default:
				cout << "Invalid choice." << endl;
				break;
			}
			cout << endl;
	}
}