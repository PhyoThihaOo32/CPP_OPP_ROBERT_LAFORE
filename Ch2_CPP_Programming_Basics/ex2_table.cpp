/*
This program generates a simple right-aligned data table
using the setw() manipulator from <iomanip>.
*/

#include <iostream>
#include <iomanip> // for setw()
using namespace std;

int main()
{
    cout << "----------------------------\n";
    cout << setw(8) << "YEAR" << setw(12) << "POPULATION" << endl;
    cout << "----------------------------\n";

    cout << setw(8) << 1990 << setw(12) << 135 << endl
         << setw(8) << 1991 << setw(12) << 7290 << endl
         << setw(8) << 1992 << setw(12) << 11300 << endl
         << setw(8) << 1993 << setw(12) << 16200 << endl;

    cout << "----------------------------\n";

    return 0;
}