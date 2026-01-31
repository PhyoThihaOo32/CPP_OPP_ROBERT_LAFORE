/*
Program: Password Sanitizer
-------------------------------------------------------
Description:
This program removes all occurrences of the substring "asdf"
from a user-entered string (e.g., a password or code word).
It demonstrates the use of:
 - `string::find()` to locate a substring within a string.
 - `string::replace()` to remove or modify parts of a string.
 - `string::npos` to detect when no more matches are found.

The while loop continues until there are no more occurrences
of "asdf" left in the string.

Author: Phyo Thiha
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string codeWord; // Variable to store the user's input
    int idx;         // Variable to store the position (index) of "asdf" in the string

    // Prompt user to enter a code word or password
    cout << "Enter a code word: ";
    cin >> codeWord;

    idx = 0; // Initialize index to 0

    /*
       Loop Explanation:
       - find("asdf") returns the index of the first occurrence of "asdf".
       - If not found, it returns string::npos.
       - The loop continues as long as "asdf" exists in the string.
    */
    while (codeWord.find("asdf") != string::npos)
    {
        // Find the position of the substring "asdf"
        idx = codeWord.find("asdf");

        // Replace (remove) 4 characters starting at index 'idx'
        // Replacing with "" (empty string) effectively deletes it
        codeWord.replace(idx, 4, "");
    }

    // Display the cleaned-up version of the code word
    cout << "New password: " << codeWord << endl;

    return 0;
}