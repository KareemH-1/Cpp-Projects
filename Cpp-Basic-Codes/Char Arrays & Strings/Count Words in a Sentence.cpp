 #include <iostream>
using namespace std;
int main(){
    char str[600];
    gets_s(str);
    int count=0;
    for(int i=0;str[i]!='\0';i++){
        if(str[i]==' '){
            count++;
        }
    }
    count++; //for the last word
    cout<<"The number of words in the sentence is: "<<count<<endl;
}