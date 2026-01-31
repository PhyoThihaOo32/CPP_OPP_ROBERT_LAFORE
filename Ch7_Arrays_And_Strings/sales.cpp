/*
This program invites the user to enter a series of six values representing widget sales for each day of the week
(excluding Sunday) and then calculates the average of these values.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    const int SIZE = 6;
    double sales[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        cout << "Enter sales figures for day " << i + 1 << ": ";
        cin >> sales[i];
    }

    double total = 0;
    for (double sale : sales)
        total += sale;

    double avg = total / SIZE;

    cout << fixed << setprecision(2);
    cout << "\nTotal sales: " << total << endl;
    cout << "Average sales: " << avg << endl;

    return 0;
}