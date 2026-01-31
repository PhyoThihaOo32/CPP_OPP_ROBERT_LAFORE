/*
5. Create a structure of type date that contains three members:
the month, the day of the month, and the year, all of type int.
(Or use day-month-year order if you prefer.) Have the user enter a date in the format 12/31/2001,
store it in a variable of type struct date, then retrieve the values from the variable and
print them out in the same format.
*/

#include <iostream>

using namespace std;

struct Date
{
    int month;
    int day;
    int year;
};

void printDate(Date);

int main()
{
    Date date;

    cout << "Enter month: ";
    cin >> date.month;
    cout << "Enter day: ";
    cin >> date.day;
    cout << "Enter year: ";
    cin >> date.year;

    printDate(date);

    return 0;
}

void printDate(Date date)
{
    cout << date.month << "/" << date.day << "/"
         << date.year << endl;
}