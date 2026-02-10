/*
Normally, when a member function is declared as const, it cannot modify any member variables of the object.
But sometimes, you need to modify certain internal fields (like logs, counters, or cached values)
even inside a const function — without breaking the logical const-ness of the object.
*/

#include <iostream>
#include <string>

using namespace std;

class Scrollbar
{
private:
    int size;
    mutable string color;
    /*
    •	color is mutable → can be changed even inside const functions.
    */

public:
    Scrollbar() : size(0), color("") {}
    Scrollbar(int s, string clr) : size(s), color(clr) {}

    void setSize(int s) { size = s; }
    void setColor(string clr) const { color = clr; }
    /*
    •	setColor() is a const member function → promises not to modify non-mutable members.
    */

    int getSize() const { return size; }
    string getColor() const { return color; }

    void display() const
    {
        cout << "Size: " << size << endl
             << "Color: " << color << endl;
    }
};

int main()
{

    Scrollbar const sb(100, "White");
    sb.display();

    sb.setColor("Grey");
    sb.display();

    /*
    •	sb is const → it can only call const-qualified functions.
    •	setColor() is const, so it’s allowed.
    •	Inside that function, color is mutable, so it can legally change.

    So yes — the const object sb is changing color!
    But this is considered “logical constness” —
    we assume that changing color doesn’t affect the logical identity of the scrollbar
    (even though it technically mutates one member).
    */

    Scrollbar sb2(200, "Black");
    sb2.display();
    sb2.setSize(300);
    sb2.setColor("Red");
    sb2.display();

    /*
    •	sb2 is not const, so it can call any member function — const or not.
    •	Declaring a function const only means “this function won’t change object state,” not “only const objects can use it.”

    So both const and non-const objects can call a const function.
    The compiler just ensures the function itself won’t mutate non-mutable members.
    */

    return 0;
}