/*
Program: Character Classification Demo
---------------------------------------
Description:
This program reads a single character from the user and determines
its type using C++ <cctype> character classification functions.

Each function checks whether the given character belongs to a
specific category (alphabet, digit, punctuation, etc.).

Author: Phyo T. Oo
*/

#include <iostream>
#include <cctype> // Contains standard character testing functions
using namespace std;

void checkChar();
bool testFormatLLLNNN(char[], int);

int main()
{

    return 0;
}

void checkChar()
{
    char ch;

    cout << "Enter a character: ";
    cin >> ch;

    /*
    ─────────────────────────────────────────────
    Character Classification Functions (from <cctype>)
    ─────────────────────────────────────────────
    - isalpha(ch) → Returns true if ch is a letter (A–Z or a–z)
    - isdigit(ch) → Returns true if ch is a digit (0–9)
    - ispunct(ch) → Returns true if ch is punctuation (!, ?, ., etc.)
    - isspace(ch) → Returns true if ch is whitespace (space, tab, newline)
    - isupper(ch) → Returns true if ch is an uppercase letter (A–Z)
    - islower(ch) → Returns true if ch is a lowercase letter (a–z)
    */

    if (isalpha(ch)) // Checks if character is alphabetic (A–Z or a–z)
        cout << "→ Alphabetic letter (A–Z or a–z)." << endl;

    if (isdigit(ch)) // Checks if character is a digit (0–9)
        cout << "→ Digit (0–9)." << endl;

    if (ispunct(ch)) // Checks if character is punctuation
        cout << "→ Punctuation symbol (!, ., ?, etc.)." << endl;

    if (isspace(ch)) // Checks if character is a whitespace
        cout << "→ Whitespace character (space, tab, newline)." << endl;

    if (isupper(ch)) // Checks if character is uppercase
        cout << "→ Uppercase letter (A–Z)." << endl;

    if (islower(ch)) // Checks if character is lowercase
        cout << "→ Lowercase letter (a–z)." << endl;
}

bool testFormatLLLNNN(char str[], int size)
{
    // Example input: "PHO793\0"

    // Check first 3 characters: must be letters (A–Z or a–z)
    for (int i = 0; i < 3; i++)
    {
        if (!isalpha(str[i])) // if any of the first 3 aren't letters
            return false;     // exit immediately and report "Invalid"
    }

    // Check remaining characters: must be digits (0–9)
    for (int i = 3; i < size - 1; i++)
    {
        if (!isdigit(str[i])) // if any of these aren't digits
            return false;     // exit immediately and report "Invalid"
    }
    return true; // if both loops finish without returning false, it's valid
}