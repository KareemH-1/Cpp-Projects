#include <iostream>
using namespace std;

int main(){
    string s , t;
    cout << "Enter a string: ";
    cin >> s ;
    cout << "Enter another string: ";
    cin >> t;

    string temp;
    int j=0;
    for(int i = t.length()-1; i>=0; i--){
        temp[j] = t[i];
        j++;
    }
    if(s == temp){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}