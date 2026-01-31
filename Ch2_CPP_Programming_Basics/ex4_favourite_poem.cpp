/*
This program prints a short poem using a string variable.
Demonstrates:
- Use of escape sequence \n for line breaks
- Outputting string objects with cout
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Store poem in a string variable with embedded newlines
    string poem = "Candy is dandy,\nBut liquor is quicker.\n";

    // Display the poem
    cout << poem;

    return 0;
}