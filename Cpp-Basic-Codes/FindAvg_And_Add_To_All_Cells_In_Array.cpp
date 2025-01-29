#include <iostream>
using namespace std;


void Read(float x[] , int n);
float FindAvg(float x[] , int n);
void AddAvg(float x[] , float Avg , int n);
void Display(float X[] , int n);

int main(){
    int n;
    cout << "Please input the number of cells in the array: ";
    cin>> n;

    float X[n];
    Read(X,n);
    float avg = FindAvg(X , n);
    AddAvg(X, avg , n);
    Display(X , n);

}

void Read(float x[] , int n){
      cout<< endl<< "Please enter the value of the each cell: ";
    for (int i =0 ; i<n; i++){
        cin>> x[i];
    }
}

float FindAvg(float x[] , int n){
    float total=0;
    for (int i =0 ; i<n ; i++){
        total = total + x[i];
    }
    float avg = total/n;
    return(avg);
}

void AddAvg(float x[] , float Avg , int n){
    for (int i =0 ; i< n ; i++){
        x[i] += Avg;
    }
}

void Display(float X[] , int n){
    cout << "Here is the array after adding the average to all of its cells: ";
    for (int i =0 ; ; i++){
       if (i == n-1){
            cout << X[i] << endl;
            break;
        }
         else{
        cout << X[i] << " | ";
        }
    }
}