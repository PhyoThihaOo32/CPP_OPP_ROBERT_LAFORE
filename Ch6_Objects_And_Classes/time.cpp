/*
3.

Create a class called time that has separate int member data for hours, minutes, and seconds.
One constructor should initialize this data to 0, and another should initialize it to fixed values.
Another member function should display it, in 11:59:59 format.
The final member function should add two objects of type time passed as arguments.

A main() program should create two initialized time objects (should they be const?)
and one that isn’t initialized. Then it should add the two initialized values together,
leaving the result in the third time variable. Finally it should display the value of
this third variable. Make appropriate member functions const.
*/

#include <iostream>

using namespace std;

class Time
{
private:
    int hour,
        minute,
        second;

public:
    Time() : hour(0), minute(0), second(0) {}
    Time(int hr, int min, int sec) : hour(hr), minute(min), second(sec) {}

    void display() const
    {
        cout << hour << ":" << minute << ":" << second << endl;
    }

    Time addTime(const Time &t1, const Time &t2) const
    {
        Time temp;
        temp.second = t1.second + t2.second;
        if (temp.second >= 60)
        {
            temp.second -= 60;
            temp.minute++;
        }
        temp.minute = t1.minute + t2.minute;
        if (temp.minute >= 60)
        {
            temp.minute -= 60;
            temp.hour++;
        }
        temp.hour = t1.hour + t2.hour;

        return temp;
    }
};

int main()
{
    const Time t1(23, 50, 12), t2(21, 25, 2);
    Time t3;

    t3.addTime(t1, t2).display();

    return 0;
}