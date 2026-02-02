/*
Program: Reverse a String using at() and Pointers
------------------------------------------------------------
Description:
This program reverses a string by dynamically allocating memory
and using both:
  1. The `at()` member function (safe index access)
  2. Pointer arithmetic (`*(ptr + i)`)

It demonstrates:
- Dynamic memory allocation using `new`
- Accessing string data using `at()`
- Returning a pointer from a function

Author: Phyo T. Oo
*/

#include <iostream>
#include <string>
using namespace std;

// Function prototype
char *reverseString(string);

int main()
{

    string str1;
    cout << "Type anything: ";
    getline(cin, str1);

    // Call the function to reverse the string
    char *ptr = reverseString(str1);

    cout << "Original string: " << str1 << endl;
    cout << "Reversed string (via pointer): ";

    // Print reversed string using pointer arithmetic
    for (int i = 0; i < str1.size(); i++)
    {
        cout << *(ptr + i);
    }
    cout << endl;

    // Always free dynamically allocated memory
    delete[] ptr;

    return 0;
}

// Function to reverse a string and return a pointer to new char array
char *reverseString(string str)
{
    // Allocate dynamic memory (+1 for null terminator)
    char *ptr = new char[str.size() + 1];
    int j = 0;

    // Copy characters from end to beginning
    for (int i = str.length() - 1; i >= 0; i--)
    {
        *(ptr + (j++)) = str.at(i); // Safe character access
    }

    *(ptr + j) = '\0'; // Null-terminate the reversed string

    return ptr;
}

/*
------------------------------------------------------------
Function Summary:
------------------------------------------------------------
reverseString(string str)
  - Allocates new memory dynamically to hold the reversed version.
  - Copies characters from the end of the input string to the beginning.
  - Returns a pointer to the newly created reversed C-string.

------------------------------------------------------------
Key Notes:
------------------------------------------------------------
1. `.at(i)` performs bounds checking (throws exception if out of range).
2. `*(ptr + i)` is equivalent to `ptr[i]` — both access the same memory.
3. Always `delete[]` dynamically allocated memory to avoid memory leaks.
4. Adding `+1` in allocation ensures space for the null terminator.

------------------------------------------------------------
Example Output:
Original string: Hello World!
Reversed string (via pointer): !dlroW olleH
------------------------------------------------------------
*/