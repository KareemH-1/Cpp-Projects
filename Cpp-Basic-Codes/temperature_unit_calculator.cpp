#include<iostream>
using namespace std;

float fahrenheitToCelsius(float fahrenheit) {
    return ((fahrenheit - 32) * 5 / 9);
}
float celsiusToFahrenheit(float celsius) {
    return ((celsius * 9 / 5) + 32);
}


float kelvinToCelsius(float kelvin) {
    return (kelvin - 273.15);
}
float celsiusToKelvin(float celsius) {
    return (celsius + 273.15);
}

float kelvinToFahrenheit(float kelvin) {
    return ((kelvin - 273.15) * 9 / 5 + 32);
}
float fahrenheitToKelvin(float fahrenheit) {
    return ((fahrenheit - 32) * 5 / 9 + 273.15);
}

int main() {
    float temperature;
    int choice;
    cout << "Enter the temperature: ";
    cin >> temperature;
    cout << "Enter the unit of temperature: \n 1. Fahrenheit \n 2. Celsius \n 3. Kelvin" << endl;
    cin >> choice;
     if(choice == 1) {
        cout << "Temperature in Celsius: " << fahrenheitToCelsius(temperature) << endl;
        cout << "Temperature in Kelvin: " << fahrenheitToKelvin(temperature) << endl;
    } else if(choice == 2) {
        cout << "Temperature in Fahrenheit: " << celsiusToFahrenheit(temperature) << endl;
        cout << "Temperature in Kelvin: " << celsiusToKelvin(temperature) << endl;
    } else if(choice == 3) {
        cout << "Temperature in Celsius: " << kelvinToCelsius(temperature) << endl;
        cout << "Temperature in Fahrenheit: " << kelvinToFahrenheit(temperature) << endl;
    } else {
        cout << "Invalid choice" << endl;
    }
}