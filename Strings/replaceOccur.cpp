/*
Program: Replace Substring in Text
-------------------------------------------------------
Description:
This program demonstrates how to iterate through a string
and replace every occurrence of a specific substring.

In this case, it replaces all occurrences of "U.S.A."
with "United States." using a while loop.

The loop continues as long as "U.S.A." is found in the text.
The string functions `find()` and `replace()` are used
to search for and modify substrings, respectively.

Author: Phyo Thiha
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Original text containing multiple occurrences of "U.S.A."
    string userText = "I have been to the U.S.A. and the U.S.A. is beautiful. U.S.A.!";

    // Variable to hold the position (index) of each occurrence
    int usaIndex;

    // The replacement phrase
    string replace = "United States.";

    // Display the original text
    cout << "Original text:\n"
         << userText << endl;

    /*
       While loop explanation:
       -----------------------
       - `find("U.S.A.")` searches for the substring "U.S.A." in `userText`.
       - If found, it returns the index (position) where it begins.
       - If not found, it returns `string::npos` ("no position" = not found).
       - The loop continues until there are no more "U.S.A." substrings.
    */
    while (userText.find("U.S.A.") != string::npos)
    {
        // Find the index of the substring "U.S.A."
        usaIndex = userText.find("U.S.A.");

        // Replace the substring with "United States."
        // Parameters:
        //   - start position: usaIndex
        //   - number of characters to replace: 6 ("U.S.A." has 6 characters)
        //   - new string: replace
        userText.replace(usaIndex, 6, replace);
    }

    // Display the modified text
    cout << "\nModified text:\n"
         << userText << endl;

    return 0;
}