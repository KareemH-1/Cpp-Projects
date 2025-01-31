// Geometric Calculator  
// This program allows users to compute the area and perimeter of various shapes.  
// Users select a shape, provide necessary dimensions, and receive calculated results.  
// Supported shapes include circles, rectangles, and triangles.  

#include <iostream>
#include <string>
using namespace std;


int main(){
    cout << "==================================="<<endl;
    cout << "     SHAPE METRICS CALCULATOR      "<<endl;
    cout << "==================================="<<endl<<endl;

    int choice;
    string shape;
    for (;;){
        cout << "Choose 1 to continue or 0 to stop.";
        cin>> choice;
        if (choice == 0 ){
            break;
        }
        else if(choice ==1 ){

        }
        else{
            cout << "Invalid choice.";
        }
    }
}