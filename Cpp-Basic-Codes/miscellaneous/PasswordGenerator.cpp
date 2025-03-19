#include<bits/stdc++.h>
using namespace std;
int main(){
    srand(time(0));
    int length;
    cout << "Enter the length of the password: ";
    cin>> length;

    char *password = new char[length];
    char symbols[]= {'!','@','#','$','%','&','*'};
    for(int i=0; i<length; i++){
        int numOrCharOrSymbol = rand() % 3;
        if(numOrCharOrSymbol == 0){
            password[i] = char(rand() % 26 + 'a');
        }
        else if(numOrCharOrSymbol == 1){
            password[i] = char(rand() % 10 + '0');
        }
        else{
            password[i] = symbols[rand() % 7];
        }
    }
    cout << "The generated password is: ";
    for(int i=0; i<length; i++){
        cout << password[i];
    }
    delete[]password;
}