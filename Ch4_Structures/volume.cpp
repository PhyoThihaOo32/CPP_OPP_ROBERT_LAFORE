/*
3. This program models the volume of a room using nested structures.
   Each dimension (length, width, height) is represented by a Distance structure.
   The program calculates and displays the volume in cubic feet.
*/

#include <iostream>
using namespace std;

struct Distance
{
    int feet;
    float inch;
};

struct Volume
{
    Distance length, width, height;
};

int main()
{
    // Initialize a volume object with feet and inches
    Volume room = {{2, 3.5}, {5, 4.4}, {10, 2.5}};

    // Convert each dimension to feet (1 foot = 12 inches)
    float l = room.length.feet + room.length.inch / 12;
    float w = room.width.feet + room.width.inch / 12;
    float h = room.height.feet + room.height.inch / 12;

    // Calculate total volume
    float volume = l * w * h;

    cout << "The volume of the room is " << volume << " cubic feet." << endl;

    return 0;
}