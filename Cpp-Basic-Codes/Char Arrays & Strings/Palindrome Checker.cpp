#include<iostream>
using namespace std;

int main(){
    string s;
    cout << "Enter a string: ";
    cin>>s;
    int length =s.length()-1;
    int ctgood;

    for(int i =0; i<length ; i++){
        if(s[i]!=s[length]){
            ctgood=0;
            break;
        }
        length--;
    }

    if(ctgood==1){
        cout<<"Palindrome";
    }
    else{
        cout<<"Not Palindrome";
    }
}