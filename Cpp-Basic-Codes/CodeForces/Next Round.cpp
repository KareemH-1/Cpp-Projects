#include <iostream>
using namespace std;
 
int main() {
    int n, k;
    cin >> n >> k;  
    int scores[n];  
 
 
    for (int i = 0; i < n; i++) {
        cin >> scores[i];
    }
 
    int threshold = scores[k - 1];
 
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (scores[i] >= threshold && scores[i] > 0) {
            count++;
        }
    }
 
    cout << count;
}