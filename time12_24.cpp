/*
Conversion between objects of different classes
-----------------------------------------------
- Conversion can be done using:
  1. A one-argument constructor (conversion constructor)
  2. A conversion operator (operator Type())
- The choice depends on whether the conversion logic should live
  inside the *source class* or the *destination class*.
*/

#include <iostream>
#include <string>
using namespace std;

enum PmAm
{
    am = 0,
    pm = 1
};

class Time12
{
private:
    PmAm isPm;
    int hour;
    int minute;

public:
    // Default constructor
    Time12() : isPm(am), hour(12), minute(0) {}

    // Constructor with validation
    Time12(PmAm pmAm, int hr, int min) : isPm(pmAm)
    {
        // ✅ Input validation ensures 1 ≤ hour ≤ 12, 0 ≤ min ≤ 59
        hour = (hr >= 1 && hr <= 12) ? hr : 12;
        minute = (min >= 0 && min <= 59) ? min : 0;
    }

    void display() const
    {
        cout << hour << ":";
        if (minute < 10)
            cout << "0";
        cout << minute << " " << (isPm ? "PM" : "AM") << endl;
    }
};

class Time24
{
private:
    int hour;
    int minute;
    int second;

public:
    // Default constructor
    Time24() : hour(0), minute(0), second(0) {}

    // Constructor with validation
    Time24(int hr, int min, int sec)
    {
        hour = (hr >= 0 && hr < 24) ? hr : 0;
        minute = (min >= 0 && min < 60) ? min : 0;
        second = (sec >= 0 && sec < 60) ? sec : 0;
    }

    void display() const
    {
        if (hour < 10)
            cout << "0";
        cout << hour << ":";
        if (minute < 10)
            cout << "0";
        cout << minute << ":";
        if (second < 10)
            cout << "0";
        cout << second << endl;
    }

    // Conversion operator: Time24 → Time12
    operator Time12() const;
};

// Conversion logic
Time24::operator Time12() const
{
    int hr24 = hour;
    int min = minute;

    // Round minutes if seconds ≥ 30
    if (second >= 30)
        min++;

    // Handle overflow from rounding
    if (min >= 60)
    {
        min = 0;
        hr24++;
        if (hr24 == 24)
            hr24 = 0;
    }

    // Determine AM/PM correctly
    PmAm ampm = (hr24 >= 12) ? pm : am;

    // Convert hour from 24-hour to 12-hour format
    int hr12 = hr24 % 12;
    if (hr12 == 0)
        hr12 = 12;

    // Return Time12 object
    return Time12(ampm, hr12, min);
}

int main()
{
    Time12 t12(am, 11, 24);
    Time24 t24(23, 12, 58); // 23:12:58 → should become 11:13 PM

    cout << "Original 12-hour time: ";
    t12.display();

    cout << "Converted from 24-hour: ";
    Time12 t1 = t24; // Implicit conversion
    t1.display();

    return 0;
}