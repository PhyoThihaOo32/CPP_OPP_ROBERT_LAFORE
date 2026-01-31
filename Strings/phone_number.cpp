/*
Program: Phone Number Letter Converter
-------------------------------------------------------
Description:
This program converts a user-entered phone number containing
letters (like "1-800-FLOWERS") into its numeric equivalent
following a standard telephone keypad mapping.

Rules:
- The input may include letters (A-Z, a-z) and dashes (-).
- Numbers (0–9) and dashes are kept unchanged.
- Invalid characters are replaced with '?'.
- The program uses ASCII comparisons to detect and convert
  letters to their corresponding digits.

Author: Phyo Oo
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string userInput; // User-entered phone number
    char currChar;    // Current character being processed

    // Prompt the user for input
    cout << "Enter phone number (letters/- OK, no spaces): ";
    cin >> userInput;

    cout << "\nConverted phone number: ";

    /*
       Loop through every character in the string:
       - If it’s a number or dash, print it as-is.
       - If it’s a letter, convert it to its numeric equivalent.
       - If it’s invalid, replace it with '?'.
    */
    for (int i = 0; i < userInput.length(); i++)
    {
        currChar = userInput.at(i);

        if ((currChar >= '0' && currChar <= '9') || (currChar == '-'))
        {
            cout << currChar; // Keep digits and dashes as-is
        }
        else if ((currChar >= 'a' && currChar <= 'c') || (currChar >= 'A' && currChar <= 'C'))
        {
            cout << "2";
        }
        else if ((currChar >= 'd' && currChar <= 'f') || (currChar >= 'D' && currChar <= 'F'))
        {
            cout << "3";
        }
        else if ((currChar >= 'g' && currChar <= 'i') || (currChar >= 'G' && currChar <= 'I'))
        {
            cout << "4";
        }
        else if ((currChar >= 'j' && currChar <= 'l') || (currChar >= 'J' && currChar <= 'L'))
        {
            cout << "5";
        }
        else if ((currChar >= 'm' && currChar <= 'o') || (currChar >= 'M' && currChar <= 'O'))
        {
            cout << "6";
        }
        else if ((currChar >= 'p' && currChar <= 's') || (currChar >= 'P' && currChar <= 'S'))
        {
            cout << "7";
        }
        else if ((currChar >= 't' && currChar <= 'v') || (currChar >= 'T' && currChar <= 'V'))
        {
            cout << "8";
        }
        else if ((currChar >= 'w' && currChar <= 'z') || (currChar >= 'W' && currChar <= 'Z'))
        {
            cout << "9";
        }
        else
        {
            cout << "?"; // Unknown or invalid character
        }
    }

    cout << endl;

    return 0;
}