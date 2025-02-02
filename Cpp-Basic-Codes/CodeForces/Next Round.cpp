#include <iostream>
using namespace std;
 
int main() {
    int n, k;
    cin >> n >> k;  
    int scores[n];  
 
 
    for (int i = 0; i < n; i++) {
        cin >> scores[i];
    }
 
    // The score of the k place participant, which is the threshold for advancing
    int threshold = scores[k - 1];

    int count = 0;  // Counter to keep track of how many participants advance

    // Loop through the scores and count how many participants advance
    for (int i = 0; i < n; i++) {
        if (scores[i] >= threshold && scores[i] > 0) {
            count++;  // If the score is equal to or greater than the threshold and positive, the count increases by 1
        }
    }
 
    cout << count;
}