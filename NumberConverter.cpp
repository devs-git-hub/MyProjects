#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>

using namespace std;

// Function to convert decimal to binary
string decimalToBinary(int decimal) {
    string binary = "";
    while (decimal > 0) {
        binary = to_string(decimal % 2) + binary;
        decimal /= 2;
    }
    return binary;
}

// Function to convert binary to decimal
int binaryToDecimal(string binary) {
    int decimal = 0;
    int size = binary.length();
    for (int i = size - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += (1 << (size - i - 1));
        }
    }
    return decimal;
}

// Function to convert decimal to octal
string decimalToOctal(int decimal) {
    string octal = "";
    while (decimal > 0) {
        octal = to_string(decimal % 8) + octal;
        decimal /= 8;
    }
    return octal;
}

// Function to convert octal to decimal
int octalToDecimal(string octal) {
    int decimal = 0;
    int size = octal.length();
    for (int i = size - 1; i >= 0; i--) {
        decimal += (octal[i] - '0') * pow(8, size - i - 1);
    }
    return decimal;
}

// Function to convert decimal to hexadecimal
string decimalToHexadecimal(int decimal) {
    stringstream ss;
    ss << hex << decimal;
    return ss.str();
}

// Function to convert hexadecimal to decimal
int hexadecimalToDecimal(string hexadecimal) {
    int decimal;
    stringstream ss;
    ss << hex << hexadecimal;
    ss >> decimal;
    return decimal;
}

int main() {
    int choice, decimal;
    string input;

    cout << "Number Converter:" << endl;
    cout << "1. Decimal to Binary" << endl;
    cout << "2. Binary to Decimal" << endl;
    cout << "3. Decimal to Octal" << endl;
    cout << "4. Octal to Decimal" << endl;
    cout << "5. Decimal to Hexadecimal" << endl;
    cout << "6. Hexadecimal to Decimal" << endl;
    cout << "Enter your choice (1-6): ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Enter a decimal number: ";
            cin >> decimal;
            cout << "Binary: " << decimalToBinary(decimal) << endl;
            break;
        case 2:
            cout << "Enter a binary number: ";
            cin >> input;
            cout << "Decimal: " << binaryToDecimal(input) << endl;
            break;
        case 3:
            cout << "Enter a decimal number: ";
            cin >> decimal;
            cout << "Octal: " << decimalToOctal(decimal) << endl;
            break;
        case 4:
            cout << "Enter an octal number: ";
            cin >> input;
            cout << "Decimal: " << octalToDecimal(input) << endl;
            break;
        case 5:
            cout << "Enter a decimal number: ";
            cin >> decimal;
            cout << "Hexadecimal: " << decimalToHexadecimal(decimal) << endl;
            break;
        case 6:
            cout << "Enter a hexadecimal number: ";
            cin >> input;
            cout << "Decimal: " << hexadecimalToDecimal(input) << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
    }

    return 0;
}
