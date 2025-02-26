#include <iostream>
#include <fstream>

using namespace std;

int main() {
    char default_file_path[] = "Files/Find First name count/list.txt";
    char file_path[200];

    cout << "Enter the text file path (press Enter to use the default path): ";
    cin.getline(file_path, 200);

    if (file_path[0] == '\0') {
        for (int i = 0; default_file_path[i] != '\0'; i++) {
            file_path[i] = default_file_path[i];
            file_path[i + 1] = '\0';
        }
    }

    ifstream file(file_path);
    if (!file) {
        cout << "Error: File not found at '" << file_path << "'." << endl;
        return 1;
    }

    char first_name[50];
    cout << "Enter the first name to count: ";
    cin >> first_name;

    char line[200];
    int count = 0, line_number = 0;

    cout << "\nMatching lines:\n";
    while (file.getline(line, 200)) {
        line_number++;

        // Extract first name from the line before the first space or comma
        char extracted_first_name[50];
        int i = 0;
        while (line[i] != ' ' && line[i] != ',' && line[i] != '\0') {
            extracted_first_name[i] = line[i];
            i++;
        }
        extracted_first_name[i] = '\0'; 

        if (strcmp(extracted_first_name, first_name) == 0) {
            cout << "(" << line_number << ". " << line << ")\n";
            count++;
        }
    }

    cout << "\nThe first name '" << first_name << "' appears " << count << " times in the file." << endl;

    file.close();
    return 0;
}
