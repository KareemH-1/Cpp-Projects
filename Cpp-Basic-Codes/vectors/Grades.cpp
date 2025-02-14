#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector <string> names;
    vector <float> scores;
    int choice;

    while(choice != 0){
        cout << "0. Exit" << endl;
        cout << "1. Add a student" << endl;
        cout << "2. Display all students" << endl;
        cout << "3. Remove a student" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 0){ 
            break;
        }

        else if (choice == 1){
            string name;
            cout <<"Enter the student's name: ";
            getline(cin, name);
            names.push_back(name);
            float score;
            cin >> score;
            scores.push_back(score);
         }

        else if (choice == 2){
            for (int i = 0; i < scores.size(); i++){
                for(int j =i ; j < scores.size(); j++){
                    if(scores[i] < scores[j]){
                        float temp = scores[i];
                        scores[i] = scores[j];
                        scores[j] = temp;

                        string temp2 = names[i];
                        names[i] = names[j];
                        names[j] = temp2;
                    }
                }
                    cout << i+1 << ". "<< names[i] << " :" << scores[i] << endl; 
            }
        }

        else if (choice == 3){
            string name;
            cout << "Enter the student's name you want to remove: ";
            getline(cin, name);
            for (int i = 0; i < names.size(); i++){
                if(names[i] == name){
                    names.erase(names.begin() + i);
                    scores.erase(scores.begin() + i);
                }
            } 
        }
    }
}