#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int x[n];
    cout << "Enter the elements of the array: ";

    for(int i=0; i<n; i++){
        cin >> x[i];
    }
    int temp;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(x[i] > x[j]){
                temp = x[i];
                x[i] = x[j];
                x[j] = temp;
            }
        }
    }
    cout << "The array arranged in ascending order is: ";
    for(int i=0; i<n; i++){
        if (i == n-1){
            cout << x[i]<<endl;
            break;
        }
        else{
            cout << x[i] << " | ";
        }
    }
}