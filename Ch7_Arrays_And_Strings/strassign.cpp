/*
Program: Demonstrating Basic std::string Operations
------------------------------------------------------------
Description:
This program demonstrates several key operations of the C++ `std::string` class:
1. Initialization using constructors and assignment.
2. Copying strings using the overloaded `=` operator.
3. Concatenation using the overloaded `+` and `+=` operators.
4. Swapping string contents using `swap()`.

Author: Phyo T. Oo
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Initialization examples
    string s1("Of Mice");   // Constructor initialization from C-string literal
    string s2 = " and Men"; // Direct assignment initialization
    string s3;              // Empty string

    // Copy assignment: s3 takes value of s1
    s3 = s1;
    cout << "s3 after assignment from s1: " << s3 << endl;

    // Concatenation using '+' operator
    s3 = "In this realm " + s1 + s2;
    cout << "After concatenation: " << s3 << endl;

    // Append using '+=' operator
    s3 += " There is no kingdom of greatness.";
    cout << "After appending: " << s3 << endl;

    // Swapping contents of s1 and s2
    s1.swap(s2);

    cout << "\nAfter swapping s1 and s2:\n";
    cout << "s1 = " << s1 << "\n";
    cout << "s2 = " << s2 << "\n";

    return 0;
}

/*
------------------------------------------------------------
Function Summary:
------------------------------------------------------------
+ `std::string` supports:
  - Assignment (=) — copies one string to another.
  - Concatenation (+) — joins multiple strings.
  - Append (+=) — adds new text at the end of an existing string.
  - swap() — exchanges contents between two strings efficiently.

Example Output:
------------------------------------------------------------
s3 after assignment from s1: Of Mice
After concatenation: In this realm Of Mice and Men
After appending: In this realm Of Mice and Men There is no kingdom of greatness.

After swapping s1 and s2:
s1 =  and Men
s2 = Of Mice
...
------------------------------------------------------------
*/