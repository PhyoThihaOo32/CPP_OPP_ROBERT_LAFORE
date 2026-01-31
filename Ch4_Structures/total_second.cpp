/*
9. This program demonstrates how to use a structure to represent time.

   The structure `Time` stores hours, minutes, and seconds.
   The user enters a time (in either 12:59:59 format or via separate prompts),
   and the program calculates the total number of seconds represented by that time.
*/

#include <iostream>
using namespace std;

// Structure to represent time
struct Time
{
    int hour;
    int minute;
    int second;
};

int main()
{
    Time myTime;

    // Prompt the user to enter time components
    cout << "Enter time (hour minute second): ";
    cin >> myTime.hour >> myTime.minute >> myTime.second;

    // Convert time to total seconds
    unsigned long totalSeconds = myTime.hour * 3600 + myTime.minute * 60 + myTime.second;

    // Display the result
    cout << "Total seconds: " << totalSeconds << endl;

    return 0;
}