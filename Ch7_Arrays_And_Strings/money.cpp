/*
7.
One of the weaknesses of C++ for writing business programs is that it does not contain
a built-in type for monetary values such as $173,698,001.32. Such a money type should
be able to store a number with a fixed decimal point and about 17 digits of precision,
enough to handle the national debt in dollars and cents. Fortunately, the built-in C++
type long double has 19 digits of precision, so we can use it as the basis of a money class,
even though it uses a floating decimal. However, we’ll need to add the capability to input
and output money amounts preceded by a dollar sign and divided by commas into groups of three digits;
this makes it much easier to read large numbers. As a first step toward developing such a class,
write a function called mstold() that takes a money string, a string representing a money amount
like "$1,234,567,890,123.99", as an argument and returns the equivalent long double.
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

long double mstold(string);

int main()
{
    long double ld = mstold("$1,234,567,890,123.9912");

    cout << fixed << ld;

    return 0;
}
long double mstold(string str)
{

    string temp;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != '$' && str[i] != ',')
            temp += str[i];
    }

    return stold(temp);
}