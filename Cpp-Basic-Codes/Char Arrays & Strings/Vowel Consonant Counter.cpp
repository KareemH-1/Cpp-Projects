#include <iostream>
using namespace std;

bool isVowel(char ch) {
    if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'){
        return true;
    }
    else if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
        return true;
    }
    return false;
}

int main() {
    char str[500];
    int vowels = 0, consonants = 0;
    
    cout << "Enter a string: ";
    gets_s(str);
    
    for (int i = 0; str[i] != '\0'; i++) {
        if(str[i] <= 'Z' && str[i] >= 'A'){
            str[i] += 32;
        }
        char ch = str[i];
        if ((ch >= 'a' && ch <= 'z')) {
            if (isVowel(str[i])){
                vowels++;
            }
            else{
                consonants++;
            }
        }
    }
    
    cout << "Vowels: " << vowels << endl;
    cout << "Consonants: " << consonants << endl;

}
