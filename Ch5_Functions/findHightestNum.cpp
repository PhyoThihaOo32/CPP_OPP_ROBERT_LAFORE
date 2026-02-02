/*
Program: Find Highest Number
---------------------------------------------------------
Description:
This program reads a list of integers entered by the user
and determines the highest (largest) non-negative number.
Input continues until the user enters a negative number,
which signals the end of input.

Features:
- Uses a while loop since the number of inputs is unknown.
- Compares each input to find the largest value.
- Returns the highest number entered before termination.

Example:
Input: 87 48 71 -96
Output: 87

Author: Phyo T. Oo
*/

#include <iostream>
#include <climits> // for INT_MIN (represents smallest possible integer value)
using namespace std;

// Function prototype declaration
int findHighestNum();

int main()
{
    // Call the function and store the result
    int highest = findHighestNum();

    // Display the result
    cout << "The highest number is: " << highest << endl;

    return 0;
}

/*
Function: findHighestNum
---------------------------------------------------------
Reads integers from the user until a negative number is entered.
Compares all non-negative numbers and returns the highest one.
If no non-negative number is entered, returns 0.
*/
int findHighestNum()
{
    int highest = INT_MIN; // Initialize to smallest possible integer
    int userNum;

    cout << "Enter numbers (enter a negative number to stop): ";

    // Read the first number
    cin >> userNum;

    // Continue looping until a negative number is entered
    while (userNum >= 0)
    {
        // If the current number is greater than the current highest, update it
        if (userNum > highest)
        {
            highest = userNum;
        }

        // Read the next number
        cin >> userNum;
    }

    // If no positive numbers were entered, default to 0
    if (highest == INT_MIN)
    {
        highest = 0;
    }

    // Return the highest number found
    return highest;
}