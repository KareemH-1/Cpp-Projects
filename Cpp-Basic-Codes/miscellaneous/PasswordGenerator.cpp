#include<bits/stdc++.h>
using namespace std;
int main(){
    srand(time(0));
    int length;
    cout << "Enter the length of the password: ";
    cin>> length;

    string *password = new string[length];
    for(int i=0; i<length; i++){
        int numOrChar = rand() % 2;
        if(numOrChar == 0){
            password[i] = char(rand() % 26 + 'a');
        }
        else{
            password[i] = char(rand() % 10 + '0');
        }
    }
    cout << "The generated password is: " << *password;
    delete[]password;
}