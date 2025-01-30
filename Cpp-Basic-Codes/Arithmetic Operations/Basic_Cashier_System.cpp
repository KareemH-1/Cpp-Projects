#include <iostream>
using namespace std;

int main(){

cout << "Cashier System" << endl;
cout << "_____________________________________________" << endl << endl;
int choice;

  for(;;){
    cout << "Please enter 1 to continue or 0 to stop: ";
    cin>> choice;
     cout << "--------------------------------------------" <<endl;
    if(choice == 0){
        break;
    }
    else if (choice == 1){

    int max = -999999999;
    int min = 9999999999;
    int posmax =-1 , posmin = -1;
    int price;
    int total =0 , count =0;
    cout << endl;

    cout << "Input price as -1 to stop counting the bill" << endl;
    cout << "--------------------------------------------" <<endl;
    for(int i=1; ;i++){
        cout << "item #"<< i <<" Enter the price of the product: ";
        cin>> price;
        if (price ==-1){
            break;
        }   
        count++;
        total = total + price;

        if (price>max){
            max = price;
            posmax = i;
        }

        if (price<min){
            min = price;
            posmin =i;
        }

    }
    
    cout << "========================================================="<< endl <<endl; 
    cout << "The total bill equals: " << total << endl;
    cout << "The amount of items bought: "<< count << endl;
    cout << "The most expensive item is the item number: "<<posmax << " and it costs: " << max <<endl; 
    cout << "The cheapest item is the item number: "<<posmin << " and it costs: " << min <<endl << endl;
    cout << "========================================================="<< endl <<endl; 
      }
      else {
        cout << "Wrong choice";
        break;
      }
    }
}
