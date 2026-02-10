#include <iostream>

using namespace std;

class Distance
{
private:
    static const float MTF; // 1 m = 3.28084
    int feet;
    float inches;

public:
    Distance() : feet(0), inches(0.0) {};
    Distance(int f, float i) : feet(f), inches(i) {};
    // conversion constructor : float(meter) to distance(feet/inch)
    explicit Distance(float meter)
    {
        float tfeet = meter * MTF;
        feet = static_cast<int>(tfeet); // Note: casting does not change the original value — it just creates a temporary converted copy.
        inches = (tfeet - feet) * 12;
    }

    void display() const
    {
        cout << "Feet: " << feet << endl
             << "Inches: " << inches << endl;
    }

    void getDistance()
    {
        cout << "Enter Feet: ";
        cin >> feet;
        cout << "Enter Inches: ";
        cin >> inches;
    }

    Distance operator+(const Distance &) const;
    bool operator>(const Distance &) const;
    void operator+=(const Distance &);
    operator float() const; // a conversion operator that convert this object into float value
                            // The float after operator is itself the return type.
};

const float Distance::MTF = 3.28084F;

Distance Distance::operator+(const Distance &d) const
{
    int tfeet = feet + d.feet;
    float tinches = inches + d.inches;

    if (tinches >= 12.0)
    {
        tinches -= 12.0;
        tfeet++;
    }
    return Distance(tfeet, tinches);
}

bool Distance::operator>(const Distance &d) const
{
    float tdist = inches + (feet / 12.0);
    float odist = d.inches + (d.feet / 12.0);

    return (tdist > odist) ? true : false;
}

void Distance::operator+=(const Distance &d)
{
    feet += d.feet;
    inches += d.inches;
    if (inches >= 12)
    {
        inches -= 12.0;
        feet++;
    }
}

Distance::operator float() const
{
    float fracFeet = inches / 12;
    fracFeet += static_cast<float>(feet);
    return fracFeet / MTF;
}
// testing explicit keyword
void fancyDistance(Distance);
int main()
{

    Distance d1(2, 2), d2(3, 3), d3, d4;

    d3 = d1 + d2;
    d4 = d1 + d2 + d3;

    d3.display();
    d4.display();

    if (d2 > d1)
    {
        cout << "d2 greater than d1." << endl;
    }
    else
        cout << "d1 greater than d2." << endl;

    Distance d5(2.0);

    d5.display();

    float meterD5 = d5;

    cout << meterD5 << endl;

    cout << "Testing explicit: " << endl;
    // fancyDistance(meterD5);

    return 0;
}

void fancyDistance(Distance d)
{
    cout << "Distance in feet and inches" << endl;
    d.display();
}

/*
Learning Notes:

✅ static const int works because integral types were always allowed
⚠️ static const float needs constexpr (or an external definition) because floating-point
constants weren’t allowed until C++11

*/