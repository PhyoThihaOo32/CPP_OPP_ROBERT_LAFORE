/*
3. Write a function called zeroSmaller() that is passed two int arguments by reference and
then sets the smaller of the two numbers to 0. Write a main() program to exercise this function.
*/

#include <iostream>
using namespace std;

void zeroSmaller(int &, int &);

int main()
{
    int num1, num2;

    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    zeroSmaller(num1, num2);

    cout << "After zeroSmaller():\n";
    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;

    return 0;
}

void zeroSmaller(int &num1, int &num2)
{
    if (num1 < num2)
        num1 = 0;
    else
        num2 = 0;
}