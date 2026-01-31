/*
1. Refer to the circarea program in Chapter 2, “C++ Programming Basics.”
Write a function called circarea() that finds the area of a circle in a similar way.
It should take an argument of type float and return an argument of the same type.
Write a main() function that gets a radius value from the user, calls circarea(), and displays the result.
*/

#include <iostream>

using namespace std;

float circleArea(float);

const float PI = 3.141592;

int main()
{
    float radius;

    cout << "Enter radius: ";
    cin >> radius;

    cout << "Area: " << circleArea(radius) << endl;

    return 0;
}

float circleArea(float radius)
{
    return PI * radius * radius;
}