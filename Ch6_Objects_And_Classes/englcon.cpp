#include <iostream>
using namespace std;

class Distance
{
private:
    int feet;
    float inches;

public:
    // Default constructor
    Distance() : feet(0), inches(0.0) {}

    // Parameterized constructor
    Distance(int ft, float in) : feet(ft), inches(in) {}

    // Input function
    void getDist()
    {
        cout << "Enter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
    }

    // Output function
    void showDist() const
    {
        cout << feet << " ft " << inches << " in" << endl;
    }

    // Function overloading
    void addDist(Distance d1, Distance d2); // version 1 (void)
    Distance addDist(Distance d) const;     // version 2 (returns Distance)
};

// version 1: adds d1 and d2 and stores in current object
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

// version 2: adds calling object + d and returns new Distance
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

int main()
{
    Distance d1, d3;
    Distance d2(11, 6.25);

    cout << "Enter first distance:\n";
    d1.getDist();

    // use version 1
    d3.addDist(d1, d2);

    // use version 2 (returning object)
    d1 = d2.addDist(d3);

    cout << "\nd1 = ";
    d1.showDist();
    cout << "d2 = ";
    d2.showDist();
    cout << "d3 = ";
    d3.showDist();

    return 0;
}