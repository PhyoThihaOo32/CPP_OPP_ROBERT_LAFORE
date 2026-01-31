/*
4. Write a function that takes two Distance values as arguments and returns the larger one.
Include a main() program that accepts two Distance values from the user, compares them,
and displays the larger.
*/

#include <iostream>
using namespace std;

struct Distance
{
    int feet;
    float inch;
};

Distance largerDistance(const Distance &, const Distance &);

int main()
{
    Distance d1, d2, larger;

    cout << "Enter Distance for d1 (feet inches): ";
    cin >> d1.feet >> d1.inch;

    cout << "Enter Distance for d2 (feet inches): ";
    cin >> d2.feet >> d2.inch;

    larger = largerDistance(d1, d2);

    cout << "Larger distance is: "
         << larger.feet << " feet "
         << larger.inch << " inches" << endl;

    return 0;
}

Distance largerDistance(const Distance &d1, const Distance &d2)
{
    float d1_inches = d1.feet * 12 + d1.inch;
    float d2_inches = d2.feet * 12 + d2.inch;

    if (d1_inches > d2_inches)
        return d1;
    else
        return d2;
}