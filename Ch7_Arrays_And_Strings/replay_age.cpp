#include <iostream>
using namespace std;

int main()
{
    int age[4]; // Declare an array of 4 integers

    // Input loop
    for (int i = 0; i < 4; i++)
    {
        cout << "Enter Age: ";
        cin >> age[i]; // Store user input in array
    }

    // Output loop (range-based for)
    for (int j : age)
    {
        cout << "Age: " << j << endl; // j already holds each value
    }

    return 0;
}