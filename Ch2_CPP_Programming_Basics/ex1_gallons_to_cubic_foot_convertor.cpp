/*
This program converts gallons to cubic feet.
There are 7.481 gallons in one cubic foot.
Formula:
    cubicFeet = gallons / 7.481
*/

#include <iostream>
using namespace std;

int main()
{
    float gallons, cubicFeet;

    cout << "Enter gallons: ";
    cin >> gallons;

    // Conversion formula
    cubicFeet = gallons / 7.481;

    cout << "Equivalent in cubic feet: " << cubicFeet << endl;

    return 0;
}