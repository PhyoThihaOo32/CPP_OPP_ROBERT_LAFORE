/*
Program: Distance Array Tracker
--------------------------------
Description:
This program demonstrates how to use an array of class objects in C++.
- A class `Distance` stores feet and inches.
- The user can input up to 5 distance values.
- Each distance is then displayed back to the user.

Key Concepts:
- Class definition with constructors and member functions.
- Array of objects.
- Controlled loop with user choice and size limit.
*/

#include <iostream>
using namespace std;

class Distance
{
private:
    int feet;
    float inches;

public:
    // Default constructor
    Distance() : feet(0), inches(0) {}

    // Parameterized constructor
    Distance(int ft, float in) : feet(ft), inches(in) {}

    // Input distance
    void getDistance()
    {
        cout << "Enter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
    }

    // Display distance
    void showDistance() const
    {
        cout << "Feet: " << feet << " ft, "
             << "Inches: " << inches << " inches" << endl;
    }
};

int main()
{
    const int SIZE = 5;  // Maximum number of entries
    Distance dist[SIZE]; // Array of Distance objects
    int index = 0;       // Tracks number of distances entered
    int option;          // User control for continuing input

    // Input loop
    do
    {
        if (index < SIZE)
        {
            cout << "\nEnter Distance in feet and inches:\n";
            dist[index++].getDistance();
            if (index >= SIZE)
            {
                {
                    cout << "\nCannot add more — storage full!\n";
                    break;
                }
            }

            cout << "Press 0 to stop or any other key to continue: ";
            cin >> option;
        }
    } while (option != 0);

    // Output all distances
    cout << "\n--- Entered Distances ---\n";
    for (int i = 0; i < index; i++)
    {
        cout << "Distance " << i + 1 << ": ";
        dist[i].showDistance();
    }

    return 0;
}