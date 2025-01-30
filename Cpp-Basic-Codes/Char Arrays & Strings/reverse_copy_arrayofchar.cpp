#include<iostream>
using namespace std;

void reverse_copy(char x[] , char y[]){
    int length =0;
    for(int i =0 ; x[i] != '\0' ; i++){
        length++;
    }
    int j =0;
    for(int i = length-1 ; i >= 0 ; i--){
        y[j] = x[i];
        j++;
    }
}

void display(char y[]){
    for(int i =0 ; y[i] != '\0' ; i++){
        cout<<y[i];
    }
}

int main (){
    char x[600];
    char y[600];
    cout<<"Enter the string : ";
    gets(x);
    reverse_copy(x,y);
    cout<<"The reverse of the string is : ";
    display(y);
}
