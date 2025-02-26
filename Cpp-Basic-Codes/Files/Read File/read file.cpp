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
        //read all the lines in the text file
        while (getline(file, read)) { //while getline returns true (there is a line to read) it will print the line
            cout << read;
          }
    }
    else if (!file.is_open()) {
        cout << "File failed to open." << endl;
    }
    file.close();
}