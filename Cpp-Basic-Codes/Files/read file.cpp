#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    string path = "Files/read file.cpp";
    string read;
    ifstream file;
    file.open(path);
    if (file.is_open()) {
        cout << "File successfully opened." << endl;
        getline(file, read);
        cout << read;
    }
    else if (!file.is_open()) {
        cout << "File failed to open." << endl;
    }
    file.close();
}