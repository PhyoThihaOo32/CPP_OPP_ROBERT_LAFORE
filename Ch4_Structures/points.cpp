/*
2. A point on a 2D plane can be represented by an x and y coordinate.
   This program uses a structure to represent points, allows the user
   to enter two points, then computes and displays their sum.
*/

#include <iostream>
using namespace std;

struct Point
{
    float x, y;
};

int main()
{
    Point p1, p2, p3;

    cout << "Enter coordinates for p1 (x y): ";
    cin >> p1.x >> p1.y;

    cout << "Enter coordinates for p2 (x y): ";
    cin >> p2.x >> p2.y;

    p3.x = p1.x + p2.x;
    p3.y = p1.y + p2.y;

    cout << "Coordinates of p1 + p2 are: (" << p3.x << ", " << p3.y << ")" << endl;

    return 0;
}