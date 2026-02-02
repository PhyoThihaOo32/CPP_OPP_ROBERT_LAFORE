/*
Program: Pattern Generator
----------------------------
This program prints two character-based patterns using nested loops.

1️⃣ First pattern: numbers followed by '=' signs.
   Example (input: 5):
   1=
   2==
   3===
   4====
   5=====

2️⃣ Second pattern: '%' symbols followed by numbers.
   Example (input: 5):
   %1
   %%2
   %%%3
   %%%%4
   %%%%%5

Author: Phyo T. Oo
*/

#include <iostream>
using namespace std;

void printSom(); // Function declaration

int main()
{
    int inputVal;

    cout << "Enter a value for the first pattern: ";
    cin >> inputVal;

    // Print number followed by '=' pattern
    for (int i = 1; i <= inputVal; i++)
    {
        cout << i;
        for (int j = 0; j < i; j++)
            cout << "=";
        cout << endl;
    }

    printSom(); // Call second pattern
    return 0;
}

// Prints '%' symbols followed by numbers
void printSom()
{
    int times;
    cout << "\nEnter a value for the second pattern: ";
    cin >> times;

    for (int i = 1; i <= times; i++)
    {
        for (int j = 0; j < i; j++)
            cout << "%";
        cout << i << endl;
    }
}