/*
Program: Safe C-String Manipulation Example
--------------------------------------------------------
Description:
This program demonstrates safe manipulation of C-style strings using:
- strlen()   → find string length (excluding '\0')
- strcat()   → append one string to another
- strncat()  → append with a character limit (safer)
- strcpy()   → copy one string to another (no bounds check)
- strncpy()  → copy with a character limit (safer)
It also shows how to handle buffer sizes correctly and ensure proper
null termination.

Author: Phyo T. Oo
*/

#include <iostream>
#include <cstring> // for strlen(), strcat(), strcpy(), strncat(), strncpy()
using namespace std;

int main()
{
    // ------------------------------------------------------------
    // PART 1 — Basic concatenation and copying
    // ------------------------------------------------------------
    const int SIZE = 50;
    char str1[SIZE] = "Pepito mucho";   // Destination string
    char str2[] = " means Little Joe."; // Source string
    char str3[SIZE];                    // Copy destination

    // strlen(): returns number of visible characters (no '\0')
    int length = strlen(str1);
    cout << "Length of str1 (excluding null terminator): " << length << endl;

    // Check available space before concatenation
    if (sizeof(str1) >= (strlen(str1) + strlen(str2) + 1)) // +1 for '\0'
    {
        strcat(str1, str2); // Appends str2 to str1 (adds '\0')
    }
    else
    {
        cout << "Error: Not enough space to concatenate." << endl;
    }

    cout << "After strcat(): " << str1 << endl;

    // strcpy(): copies source to destination (includes '\0'), but unsafe if size not checked
    strcpy(str3, str1);
    cout << "Copied with strcpy(): " << str3 << endl;

    // ------------------------------------------------------------
    // PART 2 — Safe concatenation and copying with limits
    // ------------------------------------------------------------
    const int SIZE_1 = 25;
    const int SIZE_2 = 30;

    char mystr1[SIZE_2] = "Welcome!";
    char mystr2[] = " to West Coast.";
    char mystr3[SIZE_2] = "";

    // strncat(): append limited number of characters safely
    /*
        Function: strncat(dest, src, n)
        Appends up to n characters from src to dest.
        Ensures dest is properly null-terminated.
    */
    int maxAvaChar = sizeof(mystr1) - (strlen(mystr1) + 1); // 1 is to leave space for '\0'
    strncat(mystr1, mystr2, maxAvaChar);
    cout << "After strncat(): " << mystr1 << endl;

    // strncpy(): copy limited number of characters safely
    /*
        Function: strncpy(dest, src, n)
        Copies up to n characters from src.
        If src is shorter, fills rest with '\0'.
        If src is longer, does NOT automatically append '\0'.
    */
    int maxstr3char = sizeof(mystr3) - 1; // Leave space for '\0'
    strncpy(mystr3, mystr1, maxstr3char);
    mystr3[maxstr3char] = '\0'; // Manually ensure null termination

    // Print each character to confirm '\0' termination
    int index = 0;
    cout << "\nCharacter-by-character output of mystr3:" << endl;
    while (mystr3[index] != '\0')
    {
        cout << mystr3[index++] << " ";
    }

    return 0;
}

/*
--------------------------------------------------------
Function Reference
--------------------------------------------------------
| Function          | Description                               | Includes '\0'? | Safe? | Notes |
|-------------------|------------------------------------------ |----------------|-------|-------|
| strlen(str)       | Counts characters before '\0'             | No             | Yes   | Used to check string length |
| strcat(dest, src) | Appends src to dest (adds '\0')           | Yes            | No    | Must ensure dest is large enough |
| strncat(dest, src, n) | Appends up to n chars from src        | Yes            | Yes   | Safer version of strcat |
| strcpy(dest, src) | Copies entire src (adds '\0')             | Yes            | No    | No bounds checking |
| strncpy(dest, src, n) | Copies up to n chars from src         | Sometimes      | Yes   | Must manually add '\0' if src > n |
--------------------------------------------------------

Memory Behavior Note:
---------------------
1. C-strings are character arrays ending with a null terminator ('\0').
2. strlen() excludes '\0' when counting.
3. strcat() and strcpy() depend on '\0' to detect the end of the string.
4. Always leave space for '\0' when declaring or copying strings.
5. strncpy() may not append '\0' if the source string is too long—manually ensure termination.
*/