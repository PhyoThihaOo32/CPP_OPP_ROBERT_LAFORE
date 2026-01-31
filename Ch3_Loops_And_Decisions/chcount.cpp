/*
This program counts the number of words and characters
in a phrase typed by the user.

Key concepts demonstrated:
---------------------------
1. getline(cin, phrase)  → Reads a full line including spaces.
2. stringstream ss(phrase) → Treats the string like a stream (like cin),
   allowing word-by-word extraction using the >> operator.
3. ss >> word → Extracts one word at a time until no words remain.
4. phrase.length() → Counts the total number of characters (including spaces).
5. This version is portable and does not use <conio.h> or getche().
*/

#include <iostream>
#include <string>
#include <sstream> // Required for stringstream

using namespace std;

int main()
{
    string phrase;     // The full user-entered phrase
    string word;       // Temporary holder for each extracted word
    int wordCount = 0; // Counts number of words

    // Prompt user for input
    cout << "Enter a phrase: ";
    getline(cin, phrase); // Reads a whole line (unlike cin >> which stops at spaces)

    // Create a stringstream object initialized with the user input
    stringstream ss(phrase);

    // Read one word at a time until no more words remain
    while (ss >> word)
    {
        wordCount++;
    }

    // Count total number of characters (including spaces)
    int charCount = phrase.length();

    // Display the result
    cout << "\nResults:\n";
    cout << "----------------------------------\n";
    cout << "Total Characters (including spaces): " << charCount << endl;
    cout << "Total Words: " << wordCount << endl;
    cout << "----------------------------------\n";

    return 0;
}

/*
💡 Note about getche() and <conio.h>:
------------------------------------
• `getche()` is a non-standard function from <conio.h> (short for Console I/O).
• It reads a single character from the keyboard and *echoes* it to the screen immediately.
  Example:
      char ch = getche();  // waits for user to press a key and displays it

• <conio.h> and `getche()` were used in old Turbo C/C++ or MS-DOS compilers.
• They are **not part of the C++ standard library**, so they don’t work on macOS or Linux.
• Modern C++ programs use:
      cin >> ch;        // reads one character (without echo control)
      cin.get(ch);      // reads including spaces or newlines
• Always prefer standard input methods for portability.
*/