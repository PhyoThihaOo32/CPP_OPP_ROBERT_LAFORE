/*
Program: Compare Two C-Strings Using strcmp()
--------------------------------------------------------
Description:
This program compares two C-style strings using the strcmp() function.

strcmp() takes two null-terminated character arrays and returns:
- 0  → if both strings are equal.
- >0 → if str1 comes *after* str2 in ASCII order.
- <0 → if str1 comes *before* str2 in ASCII order.

Example:
str1 = "cat", str2 = "bat" → strcmp(str1, str2) > 0
Because 'c' (ASCII 99) comes after 'b' (ASCII 98).

*/

#include <iostream>
#include <cstring> // for strcmp()
using namespace std;

int main()
{
    const int SIZE = 20; // Maximum input size (including null terminator)
    char str1[SIZE], str2[SIZE];

    // Input two strings from user
    cout << "Enter first string (up to 19 characters): ";
    cin.getline(str1, SIZE); // reads a full line (including spaces until newline)

    cout << "Enter second string (up to 19 characters): ";
    cin.getline(str2, SIZE);

    // Compare both strings
    int result = strcmp(str1, str2);

    if (result == 0)
    {
        cout << "Both strings are equal." << endl;
    }
    else if (result > 0)
    {
        cout << "\"" << str1 << "\" comes after \"" << str2 << "\" alphabetically." << endl;
    }
    else
    {
        cout << "\"" << str1 << "\" comes before \"" << str2 << "\" alphabetically." << endl;
    }

    return 0;
}

/*
--------------------------------------------------------
Function Reference:
--------------------------------------------------------
int strcmp(const char *str1, const char *str2);

Compares character by character using ASCII values until:
1. A mismatch occurs, OR
2. The null terminator ('\0') is reached.

Return values:
- 0   → strings are identical.
- < 0 → str1 < str2  (first non-matching char in str1 has smaller ASCII value).
- > 0 → str1 > str2  (first non-matching char in str1 has larger ASCII value).

Example:
-------------------------------------
Input:
str1 = "cat"
str2 = "car"

Output:
"cat" is greater than "car"
Because 't' (116) > 'r' (114)
-------------------------------------
*/