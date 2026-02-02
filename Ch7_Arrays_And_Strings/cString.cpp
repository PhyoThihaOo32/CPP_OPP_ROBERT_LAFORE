/*
Program: Interactive String Input Demo
---------------------------------------
Description:
This program demonstrates different ways to handle character array (C-string) input in C++.
It shows:
- Reading single-word and multi-word input.
- Handling input buffers using cin.ignore().
- Reading input until a specific delimiter ('X').

Key Topics:
- cin with setw()
- cin.get() for multi-word input
- cin.ignore() to clear input buffer
- Character array manipulation

Author: Phyo T. Oo
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    const int SIZE = 50; // Maximum input size

    char name[SIZE];
    char quote[] = "The only limit to our realization of tomorrow is our doubts of today.";
    char wish[SIZE];
    char song[SIZE];

    // --- Input name (single word) ---
    cout << "Enter your name: ";
    cin >> setw(SIZE) >> name;

    cout << "\nHello, " << name << "!" << endl;
    cout << "Here's an inspiring quote for you:" << endl;
    cout << quote << "\n"
         << endl;

    // --- Clear leftover newline from buffer ---
    cin.ignore();

    // --- Input a wish (multi-word using cin.get) ---
    cout << "Make a wish: ";
    cin.get(wish, SIZE);
    cout << "\nBeautiful wish: " << wish << "\n"
         << endl;

    // --- Input a song (multi-line until 'X') ---
    cout << "Sing a song (type 'X' to stop): ";
    cin.get(song, SIZE, 'X');
    cout << "\nYour song:\n"
         << song << "\n"
         << endl;

    cout << "--- End of Session ---" << endl;
    return 0;
}