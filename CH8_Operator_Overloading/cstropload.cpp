#include <iostream>
#include <cstring>
using namespace std;

class String
{
private:
    static const int SIZE = 100;
    char str[SIZE];

public:
    // Default constructor
    String() { str[0] = '\0'; }

    // Constructor with C-string
    String(const char s[])
    {
        strncpy(str, s, SIZE - 1);
        str[SIZE - 1] = '\0';
    }

    // Display the string
    void display() const { cout << str << endl; }

    // Get a character
    char getEl(int index) const { return str[index]; }

    // Return max capacity
    int getSize() const { return SIZE; }

    // Concatenation operator
    String operator+(const String &) const;
    // Equality operator
    bool operator==(const String &) const;
    // Greater-than operator (lexicographic compare)
    bool operator>(const String &) const;
    char &operator[](int);
};

String String::operator+(const String &s) const
{
    String temp;
    if (strlen(str) + strlen(s.str) < SIZE)
    {
        strcpy(temp.str, str);
        strcat(temp.str, s.str);
    }
    else
    {
        cout << "Not enough size to concat." << endl;
        return String(); // return empty object
    }
    return temp;
}

// Equality operator
bool String::operator==(const String &s) const
{
    return (strcmp(str, s.str) == 0);
}

// Greater-than operator (lexicographic compare)
bool String::operator>(const String &s) const
{
    return (strcmp(str, s.str) > 0);
}

char &String::operator[](int index)
{
    if (index >= 0 && index < SIZE)
    {
        return str[index];
    }
}

int main()
{
    String s1("Hello");
    String s2(" World");
    String s3 = s1 + s2;

    cout << "Concatenation: ";
    s3.display();

    if (s1 == s2)
        cout << "s1 and s2 are equal." << endl;
    else if (s1 > s2)
        cout << "s1 is lexicographically greater than s2." << endl;
    else
        cout << "s1 is lexicographically smaller than s2." << endl;

    return 0;
}