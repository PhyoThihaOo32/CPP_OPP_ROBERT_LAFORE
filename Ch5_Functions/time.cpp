/*
5. Write a function called hms_to_secs() that takes three int values—for hours, minutes,
and seconds—as arguments, and returns the equivalent time in seconds (type long).
Create a program that exercises this function by repeatedly obtaining a time value in hours, minutes,
and seconds from the user (format 12:59:59), calling the function,
and displaying the value of seconds it returns.
*/

#include <iostream>
using namespace std;

struct Time
{
    int hour;
    int minute;
    int second;
};

unsigned long hms_to_secs(int, int, int);
Time sec_to_time(long);

int main()
{
    int hour, minute, second;
    long total_second;
    char choice;
    char c1, c2;
    Time convertedTime;

    do
    {
        cout << "Enter time (hh:mm:ss): ";
        cin >> hour >> c1 >> minute >> c2 >> second;

        cout << "Total seconds: "
             << hms_to_secs(hour, minute, second) << endl;

        cout << "Do you want to enter another time? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Enter total seconds: ";
    cin >> total_second;

    convertedTime = sec_to_time(total_second);

    cout << "Converted time: "
         << convertedTime.hour << ":"
         << convertedTime.minute << ":"
         << convertedTime.second << endl;

    return 0;
}

unsigned long hms_to_secs(int hour, int min, int sec)
{
    return hour * 3600 + min * 60 + sec;
}

Time sec_to_time(long totalSeconds)
{
    Time t;
    t.hour = totalSeconds / 3600;
    t.minute = (totalSeconds % 3600) / 60;
    t.second = totalSeconds % 60;
    return t;
}