/*
Program: String Utility Functions (Copy, Slice, Count)
------------------------------------------------------------
Description:
This program demonstrates fundamental C-string operations using character arrays and loops.
It includes:
  1. stringCopy()  - Copies one string into another.
  2. stringSlice() - Cuts a string at the first whitespace.
  3. countChar()   - Counts the number of times a specific character appears in a string.

Each function manually handles string manipulation without using <cstring> functions like strcpy() or strlen(),
illustrating how C-strings work internally.

*/

#include <iostream>
#include <cctype> // for isalpha(), isspace()
using namespace std;

// Function prototypes
void stringCopy(char dest[], char src[]);
void stringSlice(char str[]);
int countChar(char str[], char c);
int countChar(char *, char);

int main()
{
    char str[] = "Hello World";
    char userIn;
    int count;

    // Prompt user for a character to count
    cout << "Enter character you want to count in the string: ";
    cin >> userIn;

    // Call function to count occurrences
    count = countChar(str, userIn);

    // Display result
    cout << "There are " << count << " '" << userIn << "' in \"" << str << "\"." << endl;

    return 0;
}

/*
------------------------------------------------------------
Function: stringCopy()
------------------------------------------------------------
Purpose:
- Copies all characters from src[] into dest[] until '\0' is found.

Parameters:
- dest[] : Destination array (must be large enough to hold src)
- src[]  : Source string to copy

Logic:
1. Use a loop to copy character-by-character.
2. Stop when '\0' (end of string) is reached.
3. Append '\0' to destination manually.
*/
void stringCopy(char dest[], char src[])
{
    int index = 0;
    while (src[index] != '\0')
    {
        dest[index] = src[index];
        index++;
    }
    dest[index] = '\0';
}

/*
------------------------------------------------------------
Function: stringSlice()
------------------------------------------------------------
Purpose:
- Removes everything from the first whitespace onward.

Example:
Input:  "Hello World"
Output: "Hello"

Logic:
1. Traverse until a space or '\0' is found.
2. When space is found, replace it with '\0' to mark end of string.
*/
void stringSlice(char str[])
{
    int index = 0;
    while (!isspace(str[index]) && str[index] != '\0')
    {
        index++;
    }
    str[index] = '\0';
}

/*
------------------------------------------------------------
Function: countChar()
------------------------------------------------------------
Purpose:
- Counts how many times a specific character appears in a C-string.

Parameters:
- str[] : Input string
- c     : Character to count

Logic:
1. Loop through every character until '\0' (end of string).
2. Increment count whenever str[index] == c.
3. Return total count.
*/
int countChar(char str[], char c)
{
    int index = 0;
    int count = 0;

    while (str[index] != '\0')
    {
        if (str[index] == c)
        {
            count++;
        }
        index++;
    }
    return count;
}

int countChar(char *str, char c)
{
    int count = 0;
    while (*str != '\0')
    {
        if (*str == c)
            count++;
        str++;
    }

    return count;
}