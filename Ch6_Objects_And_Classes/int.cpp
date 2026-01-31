/*
1.Create a class that imitates part of the functionality of the basic data type int.
Call the class Int (note different capitalization). The only data in this class is an int variable.
Include member functions to initialize an Int to 0, to initialize it to an int value,
to display it (it looks just like an int), and to add two Int values.
*/

#include <iostream>

using namespace std;

class Int
{
private:
    int number;

public:
    Int() : number(0) {}
    Int(int n) : number(n) {}

    void setInt(int n) { number = n; };
    int getInt() const { return number; }

    // Return a new Int object (doesn't modify the original)
    Int addInt(const Int &other) const
    {
        return Int(number + other.number);
    }
    double squareInt(int power)
    /*
    •	For large power, recursion may cause a stack overflow.
    •	You could optimize it using iteration or exponentiation by squaring,
        but for small powers, this is fine.
    */
    {
        if (power == 0)
            return 1;
        if (power > 0)
        {
            return number * squareInt(power - 1);
        }
        else if (power < 0)
        {
            return (1.0 / number) * squareInt(power + 1);
        }
        else
            return 1;
    }
};

int main()
{
    Int myNum(2);
    Int otherNum;

    otherNum = myNum.addInt(Int(4));
    cout << otherNum.getInt() << endl;

    return 0;
}
