/*
Program: Theater Seat Label Generator
---------------------------------------
Description:
Generates seat labels for a theater where each seat is identified
by a letter (row) and a number (column).

Example:
If numRows = 2 and numColumns = 3, output:
A1 A2 A3
B1 B2 B3

Author: Phyo T. Oo
*/

#include <iostream>
using namespace std;

int main()
{
    int numRows, numColumns;
    char currentRowLetter = 'A'; // Start from row 'A'

    cin >> numRows >> numColumns; // Input: number of rows and columns

    // Loop through rows
    for (int currentRow = 1; currentRow <= numRows; currentRow++)
    {
        // Loop through columns
        for (int currentColumn = 1; currentColumn <= numColumns; currentColumn++)
        {
            cout << currentRowLetter << currentColumn << " ";
        }
        cout << endl;       // Move to next row
        currentRowLetter++; // Next letter (B, C, D, ...)
    }

    return 0;
}