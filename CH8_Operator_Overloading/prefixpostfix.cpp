#include <iostream>
using namespace std;

class Counter
{
private:
    unsigned count; // internal count

public:
    // Constructors
    Counter() : count(0) {}
    Counter(int c) : count(c) {}

    // Accessor / Mutator
    void setCount(int c) { count = c; }
    unsigned getCount() const { return count; }

    // ----- Increment Operators -----
    // Prefix (++x): Increment first, then return updated value
    Counter operator++()
    {
        return Counter(++count); // increment then return new value
    }

    // Postfix (x++): Return old value, then increment
    Counter operator++(int)
    {
        return Counter(count++); // return copy before increment
    }

    // ----- Decrement Operators -----
    // Prefix (--x): Decrement first, then return updated value
    Counter operator--()
    {
        return Counter(--count); // decrement then return
    }

    // Postfix (x--): Return old value, then decrement
    Counter operator--(int)
    {
        return Counter(count--); // return copy before decrement
    }
};

int main()
{
    Counter c1, c2, c3;

    cout << "Initial values:\n";
    cout << "c1: " << c1.getCount() << ", c2: " << c2.getCount()
         << ", c3: " << c3.getCount() << endl;

    c1++;      // postfix: c1 = 1
    c2 = c1++; // postfix: c2 = 1, c1 = 2
    c3 = ++c2; // prefix:  c2 = 2, c3 = 2

    cout << "\nAfter increments:\n";
    cout << "c1: " << c1.getCount() << ", c2: " << c2.getCount()
         << ", c3: " << c3.getCount() << endl;

    --c2; // prefix: c2 = 1
    c3--; // postfix: c3 = 1

    cout << "\nAfter decrements:\n";
    cout << "c2: " << c2.getCount() << ", c3: " << c3.getCount() << endl;

    return 0;
}