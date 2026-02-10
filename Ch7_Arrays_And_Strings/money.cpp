/*
7.
C++ lacks a built-in type for monetary values (e.g., $173,698,001.32).
To handle money safely, we can use long double (19 digits precision)
and implement formatting for input/output of dollar amounts.

11.
Implement ldtoms() to convert a long double into a formatted money string.
It should insert commas and prepend a dollar sign.

12.
Create a bMoney (Money) class that:
- Stores monetary values as long doubles.
- Converts money strings to long doubles using mstold().
- Converts long doubles to money strings using ldtoms().
- Supports addition of two money values using madd() or similar.
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

class Money
{
private:
    long double money; // stores the actual amount in numeric form

public:
    Money() : money() {} // default constructor initializes to 0

    // Basic setters/getters
    void setMoney(long double m) { money = m; }
    long double getMoney() const { return money; }

    // Converters
    long double mstold(string); // Converts money string to long double
    string ldtoms(long double); // Converts long double to formatted string

    // Add two Money objects or add a numeric amount
    Money addMoney(const Money &, const Money &);
    void addMoney(long double);
};

/*
Function: mstold
----------------
Removes '$' and ',' symbols from a money string
and converts it to a long double.
Example: "$1,234.56" → 1234.56
*/
long double Money::mstold(string str)
{
    string temp;

    // Copy only digits and decimal point
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != '$' && str[i] != ',')
            temp += str[i];
    }

    // Convert cleaned string to long double
    return stold(temp);
}

/*
Function: ldtoms
----------------
Converts a long double into a formatted money string.
Example: 1234567.89 → "$1,234,567.89"
*/
string Money::ldtoms(long double ld)
{
    ostringstream os;

    // Ensure number isn't too large
    if (ld <= 9999999999999990.00)
        os << fixed << showpoint << setprecision(2) << ld;
    else
        return "value too large to handle.";

    // Add dollar sign to the beginning
    string str = os.str().insert(0, "$");

    // Insert commas for readability (simple pattern)
    for (int i = 1; i < str.length(); i++)
    {
        if (i % 4 == 0 && i < (str.length() - 3))
        {
            str.insert(i, ",");
        }
    }

    return str;
}

/*
Function: addMoney
------------------
Adds the monetary values of two Money objects
and returns a new Money object containing the sum.
*/
Money Money::addMoney(const Money &m1, const Money &m2)
{
    Money temp;
    temp.money = m1.money + m2.money;
    return temp;
}

/*
Overloaded addMoney
-------------------
Adds a raw long double amount to the current Money object.
*/
void Money::addMoney(long double m)
{
    money += m;
}

int main()
{
    Money money;
    long double amount;
    // 1. Prompt user for two money strings
    cout << "Enter your amount: ";
    cin >> amount;

    money.setMoney(amount);
    // 2. Convert using ldtoms()
    money.ldtoms(money.getMoney());
    // 3. Add them using addMoney()
    cout << "Enter the amount you want to add: ";
    cin >> amount;
    money.addMoney(amount);
    // 4. Display result using ldtoms()
    cout << "Final amount " << money.ldtoms(money.getMoney()) << endl;

    return 0;
}