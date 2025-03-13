#include <bits/stdc++.h>
using namespace std;

#define print(x) cout << x << endl
#define input(x) getline(cin, x)
#define def(name, param) void name(param)
#define list(type, name, size) type name[size]
#define len(array) (sizeof(array) / sizeof(array[0]))
#define range(start, stop, step, arr, size)  \
    int index = 0;                           \
    for (int i = start; i < stop; i += step) \
        arr[index++] = i;                    \
    size = index;
#define enumerate(arr, size)        \
    for (int i = 0; i < size; i++)  \
        cout << "Index: " << i << " Value: " << arr[i] << endl;

def(square, int x) {
    print("Square of " + to_string(x) + " is " + to_string(x * x));
}

int main() {
    print("Hello, World!");

    string name;
    print("Enter your name:");
    input(name);
    print("Hello, " + name);

    square(5);

    list(int, numbers, 5) = { 1, 2, 3, 4, 5 };
    print("Length of list: " + to_string(len(numbers)));

    int r[10], size;
    range(1, 10, 2, r, size);
    print("Range output:");
    for (int i = 0; i < size; i++) {
        print(r[i]);
    }

    print("Enumerate output:");
    enumerate(numbers, len(numbers));
}
