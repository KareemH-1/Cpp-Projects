#include <iostream>
using namespace std;
int main()
{
    int num, sumEven = 0, sumOdd = 0;
    cout << "Enter the number: ";
    cin >> num;
    while (num > 0)
    {
        int reminder = num % 10;
        if (reminder % 2 == 0)
        {
            sumEven = sumEven + reminder;
        }
        else
        {
            sumOdd = sumOdd + reminder;
        }
        num = num / 10;
    }
    cout << "Sum of even digits: " << sumEven << endl;
    cout << "Sum of odd digits: " << sumOdd << endl;
}