#include <iostream>
using namespace std;
 
int main() {
	int M, N , area;
	cin >> M >> N;
	area = M * N;
	int dominos;
	if (area % 2 != 0) {
		area = area-1;
	}
	dominos = area / 2;
	cout << dominos;
}