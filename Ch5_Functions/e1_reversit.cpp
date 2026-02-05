/*
Program: reversit() — Reverse a C-string
------------------------------------------------------------
Description:
This program defines a function called `reversit()` that reverses
a C-string (array of characters). It uses a loop to swap the first
and last characters, then the second and next-to-last, and so on.
The function takes a C-string as an argument and modifies it in place.

It demonstrates:
- C-string manipulation with `char[]`
- Pointer indexing and swapping
- Input method that allows embedded blanks

Test phrase:
"Able was I ere I saw Elba"

*/

#include <iostream>
#include <cstring> // for strlen()

using namespace std;

// Function prototype
void reversit(char[]);

int main()
{
    const int SIZE = 100; // Max characters allowed
    char str[SIZE];

    cout << "Enter a phrase: ";
    cin.getline(str, SIZE); // allows embedded blanks

    reversit(str);

    cout << "Reversed string: " << str << endl;

    return 0;
}

/*
------------------------------------------------------------
Function: reversit()
Purpose:
Reverses the characters in a given C-string in place.

Algorithm:
1. Initialize two indices: one at the start (i = 0)
   and one at the end (j = strlen(str) - 1).
2. Swap characters at i and j.
3. Move i forward and j backward until they cross.
------------------------------------------------------------
*/
void reversit(char str[])
{
    int i = 0;
    int j = strlen(str) - 1;
    char temp;

    while (i < j)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}