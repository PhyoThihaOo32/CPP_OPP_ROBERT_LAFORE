/*
2. Raising a number n to a power p is the same as multiplying n by itself p times.
Write a function called power() that takes a double value for n and an int value for p,
and returns the result as a double value. Use a default argument of 2 for p, so that
if this argument is omitted, the number will be squared.
Write a main() function that gets values from the user to test this function.

7. Start with the power() function of Exercise 2, which works only with type double.
Create a series of overloaded functions with the same name that, in addition to double,
also work with types char, int, long, and float. Write a main() program that exercises
these overloaded functions with all argument types.

*/

#include <iostream>
using namespace std;

double power(double n, int p = 2);
float power(float, int p = 2);
long power(long, int p = 2);

int main()
{
    double userNum;
    int userPower;
    char choice;

    cout << "Enter the number: ";
    cin >> userNum;

    cout << "Do you want to enter a power? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y')
    {
        cout << "Enter the power: ";
        cin >> userPower;
        cout << "Result: " << power(userNum, userPower) << endl;
    }
    else
    {
        // Default power (square)
        cout << "Result (squared): " << power(userNum) << endl;
    }

    return 0;
}

double power(double number, int p)
{
    if (p == 0)
        return 1;

    if (p > 0)
        return number * power(number, p - 1);
    else
        return 1 / power(number, -p);
}

float power(float number, int p)
{
    if (p == 0)
        return 1;

    if (p > 0)
        return number * power(number, p - 1);
    else
        return 1 / power(number, -p);
}

long power(long number, int p)
{
    if (p == 0)
        return 1;

    if (p > 0)
        return number * power(number, p - 1);
    else
        return 1 / power(number, -p);
}
