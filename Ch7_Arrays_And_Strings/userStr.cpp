/*
------------------------------------------------------------
Program: Simple String Class Example
------------------------------------------------------------
Description:
This program demonstrates a custom `String` class that stores
a fixed-size C-style string internally. It shows:
- Use of constructors for initialization
- Safe string copying with `strncpy`
- Safe string concatenation with `strncat`
- Access rules for private class members
- Object assignment behavior in C++
*/

#include <iostream>
#include <cstring>
using namespace std;

class String
{
private:
    static const int SIZE = 80; // Maximum string length
    char string[SIZE];          // Character array to hold the string

public:
    // Default constructor initializes empty string
    String() { string[0] = '\0'; }

    // Parameterized constructor (safe copy using strncpy)
    String(char str[])
    {
        strncpy(string, str, SIZE - 1);
        string[SIZE - 1] = '\0';
    }

    // Display the string
    void display() const
    {
        cout << string << endl;
    }

    // Concatenate another String object to the current one
    void concat(String str)
    {
        // Note: A class method can access private data of another
        // object of the same class (hence `str.string` is allowed).
        if (strlen(string) + strlen(str.string) < SIZE)
        {
            strncat(string, str.string, SIZE - strlen(string) - 1);
            string[SIZE - 1] = '\0'; // Ensure null termination
        }
        else
        {
            cout << "String too long." << endl;
        }
    }
};

int main()
{
    char temp1[] = "Take me back to Oregon.";
    char temp2[] = "Wishing stars..";
    char temp3[] = "Ohh - Dear West Coast.";

    String str1(temp1);
    String str2(temp2);
    String str3;

    str1.display();
    str2.display();

    /*
    --------------------------------------------------------
    Line: str3 = str2;
    --------------------------------------------------------
    This invokes the **default assignment operator** provided
    by the compiler. It performs a **memberwise copy**:
    - Copies each data member from str2 to str3.
    - Works fine because the class only contains simple types.
    If the class managed dynamic memory (using pointers),
    a custom assignment operator (deep copy) would be needed.
    --------------------------------------------------------
    */
    str3 = str2;
    str3.display();

    // Concatenate temp3 string to str1
    str1.concat(temp3);
    str1.display();

    return 0;
}