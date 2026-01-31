/*
This program calculates the area of a room using nested structures.
It demonstrates:
--------------------------------
• How to define and use nested structures.
• How to access structure members using the dot (.) operator.
• How to convert feet and inches to total feet.
• How to calculate area using the converted measurements.
*/

#include <iostream>
using namespace std;

// Structure representing a distance in feet and inches
struct Distance
{
    int feet;
    float inch;
};

// Structure representing a room, composed of two Distance members
struct Room
{
    Distance length;
    Distance width;
};

int main()
{
    // Initialize a Room object with nested Distance values
    // livingRoom.length = 12 feet, 4.5 inches
    // livingRoom.width  = 20 feet, 10.8 inches
    Room livingRoom = {{12, 4.5}, {20, 10.8}};

    // Convert feet and inches to total feet (1 foot = 12 inches)
    float l = livingRoom.length.feet + (livingRoom.length.inch / 12);
    float w = livingRoom.width.feet + (livingRoom.width.inch / 12);

    // Calculate and display the area in square feet
    // (Optional: if you want m², multiply by 0.092903)
    cout << "The area of the room is " << (l * w) << " sq. ft." << endl;

    return 0;
}

/*
🧠 Notes:
---------
1. Nested structures:
   - A struct can contain another struct as a member.
   - You can access inner members using multiple dots:
       livingRoom.length.feet
       livingRoom.width.inch

2. Conversion:
   - Since there are 12 inches in a foot, dividing inches by 12
     converts inches to feet.

3. Unit Conversion (optional):
   - If you want the result in square meters instead of square feet:
       float areaInMeters = (l * w) * 0.092903;
*/