/*
1. A phone number, such as (212) 767-8900, can be thought of as having three parts:
   the area code (212), the exchange (767), and the number (8900).

   This program uses a structure to store these three parts separately.
   It initializes one phone number, allows the user to input another,
   and then displays both numbers.
*/

#include <iostream>
#include <iomanip>
using namespace std;

// Structure representing a phone number
struct Phone
{
    int area_code;
    int exchange;
    int number;
};

int main()
{
    Phone phone1 = {212, 767, 8900}; // initialized value
    Phone phone2;                    // user input

    cout << "Enter your area code, exchange, and number: ";
    cin >> phone2.area_code >> phone2.exchange >> phone2.number;

    cout << "\nMy number is (" << phone1.area_code << ") "
         << phone1.exchange << "-" << phone1.number << endl;

    cout << "Your number is (" << phone2.area_code << ") "
         << phone2.exchange << "-" << phone2.number << endl;

    return 0;
}