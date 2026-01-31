/*
5. Write a function called hms_to_secs() that takes three int values—for hours, minutes,
and seconds—as arguments, and returns the equivalent time in seconds (type long).
Create a program that exercises this function by repeatedly obtaining a time value in hours, minutes,
and seconds from the user (format 12:59:59), calling the function,
and displaying the value of seconds it returns.
*/

#include <iostream>

using namespace std;

unsigned long hms_to_secs(int, int, int);

int main()
{
    int hour, minute, second;

    cout << "Enter hour minute second (hh/mm/sec): ";
    cin >> hour >> minute >> second;

    cout << "Total second: " << hms_to_secs(hour, minute, second) << endl;

    return 0;
}

unsigned long hms_to_secs(int hour, int min, int sec)
{
    return hour * 3600 + min * 60 + sec;
}