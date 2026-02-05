/*
Program: Average of Distances
------------------------------------------------------------
Description:
This program defines a class `Distance` that represents a length
in feet and inches. It demonstrates:
- Function overloading
- Object addition using member functions
- Aggregation of multiple Distance objects
- Calculating and displaying average distance

The program prompts the user to enter multiple distances,
sums them up, and computes their average.

Author: Phyo T. Oo
*/

#include <iostream>
using namespace std;

class Distance
{
private:
    int feet;
    float inches;

public:
    // Constructors
    Distance() : feet(0), inches(0.0) {}
    Distance(int ft, float in) : feet(ft), inches(in) {}

    // Input and display functions
    void getDist()
    {
        cout << "Enter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
    }

    void showDist() const
    {
        cout << feet << " ft " << inches << " in" << endl;
    }

    // Overloaded functions for adding distances
    void addDist(Distance d1, Distance d2); // version 1: stores sum of two objects
    void addDist(Distance d1);              // version 2: adds d1 to current object
    Distance addDist(Distance d) const;     // version 3: returns new object (non-mutating)

    // Computes average by dividing total distance by number
    void avgDist(int num);
};

//------------------------------------------------------------
// version 1: adds d1 + d2 → stores result in *this
//------------------------------------------------------------
void Distance::addDist(Distance d1, Distance d2)
{
    inches = d1.inches + d2.inches;
    feet = d1.feet + d2.feet;

    if (inches >= 12.0)
    {
        inches -= 12.0;
        feet++;
    }
}

//------------------------------------------------------------
// version 2: adds another Distance to current object
//------------------------------------------------------------
void Distance::addDist(Distance d1)
{
    inches += d1.inches;
    feet += d1.feet;
    if (inches >= 12)
    {
        inches -= 12;
        feet++;
    }
}

//------------------------------------------------------------
// version 3: returns a new Distance = (this + d)
//------------------------------------------------------------
Distance Distance::addDist(Distance d) const
{
    Distance temp;
    temp.inches = inches + d.inches;
    temp.feet = feet + d.feet;

    if (temp.inches >= 12.0)
    {
        temp.inches -= 12.0;
        temp.feet++;
    }

    return temp;
}

//------------------------------------------------------------
// Divides current Distance by given number to compute average
//------------------------------------------------------------
void Distance::avgDist(int num)
{
    float totalInches = feet * 12.0 + inches; // convert to inches
    float avgInches = totalInches / num;

    feet = static_cast<int>(avgInches / 12);
    inches = fmod(avgInches, 12.0);
}

//------------------------------------------------------------
// Main program
//------------------------------------------------------------
int main()
{
    const int SIZE = 3;
    Distance dist[SIZE];
    Distance total, average;

    cout << "Enter " << SIZE << " distances:\n";
    for (int i = 0; i < SIZE; i++)
    {
        cout << "\nDistance " << i + 1 << ":\n";
        dist[i].getDist();
    }

    cout << "\nEntered distances:\n";
    for (int i = 0; i < SIZE; i++)
    {
        dist[i].showDist();
    }

    // Add all distances together
    for (int i = 0; i < SIZE; i++)
    {
        total.addDist(dist[i]);
    }

    cout << "\nTotal distance: ";
    total.showDist();

    // Compute and display average
    total.avgDist(SIZE);
    cout << "Average distance: ";
    total.showDist();

    return 0;
}