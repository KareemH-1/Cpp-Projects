#include <iostream>
using namespace std;
 
int main() {
	int M, N , area;
	cin >> M >> N;
	area = M * N;  // Calculate the total number of squares on the board
    int dominos; 

    // If the area is odd, reduce it by 1 because we can't fit a domino in the last square
    if (area % 2 != 0) {
        area = area - 1;
    }

    // Each domino covers 2 squares, so the maximum number of dominoes is half the area
    dominos = area / 2;
	cout << dominos;
}