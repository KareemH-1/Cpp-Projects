//Find the Least Common Multiple and Greatest Common Divisor of two numbers.
#include <iostream>
using namespace std;

int LCM(int a, int b){
    if(a > b){
        for(int i = a ; ;i+=a){
          if(i % b == 0 && i % a == 0){
            return i;
          }  
        } 
    }
    else{
        for(int i = b ; ;i+=b){
            if(i % b == 0 && i % a == 0){
              return i;
            }  
        }
    }
}

int GCD(int a, int b) {
    if (a < b) {
        for (int i = a; i > 0; i--) {
            if (a % i == 0 && b % i == 0) {
                return i;
            }
        }
    } else {    
        for (int i = b; i > 0; i--) {
            if (a % i == 0 && b % i == 0) {
                return i;
            }
        }
    }
    return 1; //common divisor of any numbers
}
int main(){
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    cout << "The LCM of " << a << " and " << b << " is: " << LCM(a, b) << endl;
    cout << "The GCD of " << a << " and " << b << " is: " << GCD(a, b) << endl;
}