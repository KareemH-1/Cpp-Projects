#include <iostream>
using namespace std;

void read(float &num) {
    cout << "Enter number: ";
    cin >> num;
}
void operate(char &op) {
    cout << "Enter operator ( + , - , * , / , ^ ): ";
    cin >> op;
}
void calculate(float num1, float num2, char op) {
    if (op == '+') {
        cout << num1 << op << num2 << " = "<< num1 + num2;
    }
    else if (op == '-') {
        cout << num1 << op << num2 << " = " <<  num1 - num2;
    }
    else if (op == '*') {
        cout << num1 << op << num2 << " = " << num1 * num2;
    }
    else if (op == '/') {
       cout << num1 << op << num2 << " = " << num1 / num2;
    }
    else if (op == '^') {
        float result = 1;
        for (int i = 0; i < num2; i++) {
            result *= num1;
        }
        cout << num1 << op << num2 << " = " << result;
    }

    else {
        cout << "Invalid operator";
    }
}

int main() {
    float num1 , num2;
    char op;

    for (;;) {
        cout << "Basic Calculator" << endl;
        cout << "-----------------" << endl;
        cout << "Enter 0 to exit or Enter 1 to continue" << endl;
        int choice;
        cin >> choice;
        if (choice == 0) {
            break;
        }
        else if (choice == 1) {
        read(num1);
        operate(op);
        read(num2);
        calculate(num1, num2, op);
        cout << endl <<"-----------------" << endl;
        }
        else {
            cout << "Invalid choice" << endl;
        }
     }
}