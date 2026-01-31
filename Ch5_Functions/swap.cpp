/*
8. Write a function called swap() that interchanges two int values passed to it by the calling program.
(Note that this function swaps the values of the variables in the calling program, not those in the function.)
You’ll need to decide how to pass the arguments. Create a main() program to exercise the function.

9. Repeat Exercise 8, but instead of two int variables,
have the swap() function interchange two struct Time values.
*/

#include <iostream>
using namespace std;

struct Time
{
    int hour;
    int minute;
    int second;
};

void swap(int &, int &);
void swap(Time &, Time &);
void displayTime(const Time &);

int main()
{
    int num1, num2;
    Time time1, time2;

    // Exercise 8: swap integers
    cout << "Enter two integers: ";
    cin >> num1 >> num2;

    cout << "\nBefore swapping integers:\n";
    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;

    swap(num1, num2);

    cout << "\nAfter swapping integers:\n";
    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;

    // Exercise 9: swap Time structures
    cout << "\nEnter Time 1 (hh mm ss): ";
    cin >> time1.hour >> time1.minute >> time1.second;

    cout << "Enter Time 2 (hh mm ss): ";
    cin >> time2.hour >> time2.minute >> time2.second;

    cout << "\nBefore swapping times:\n";
    displayTime(time1);
    displayTime(time2);

    swap(time1, time2);

    cout << "\nAfter swapping times:\n";
    displayTime(time1);
    displayTime(time2);

    return 0;
}

// Swap two integers
void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

// Swap two Time structures
void swap(Time &t1, Time &t2)
{
    Time temp = t1;
    t1 = t2;
    t2 = temp;
}

// Display Time
void displayTime(const Time &t)
{
    cout << t.hour << ":" << t.minute << ":" << t.second << endl;
}