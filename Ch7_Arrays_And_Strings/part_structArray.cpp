/*
Program: Car Parts Inventory Display
-------------------------------------------------------
Description:
This program demonstrates the use of an array of structures
to represent information about different car parts.

Each `part` structure stores:
- Part name
- Model number
- Part number
- Cost

The program initializes an array of car parts, then displays
their details in a formatted manner.

*/

#include <iostream>
#include <string>
#include <iomanip> // for formatting output
using namespace std;

// Define structure to represent car part information
struct Part
{
    string partName; // Name of the part
    int modelNumber; // Model identifier
    int partNumber;  // Part identifier
    float cost;      // Cost of the part
};

int main()
{
    const int SIZE = 3; // Total number of car parts

    // Initialize array of car parts
    Part carParts[SIZE] = {
        {"T-92F", 1, 111, 120.99},
        {"RE5JK", 2, 222, 500.99},
        {"OBV92", 3, 333, 1000.99}};

    // Display all car parts
    cout << fixed << setprecision(2); // show two decimal points for prices
    cout << "\n=== Car Parts Inventory ===\n";

    for (int i = 0; i < SIZE; i++)
    {
        cout << "\nPart #" << i + 1 << endl;
        cout << "---------------------------------\n";
        cout << "Part Name   : " << carParts[i].partName << endl;
        cout << "Model Number: " << carParts[i].modelNumber << endl;
        cout << "Part Number : " << carParts[i].partNumber << endl;
        cout << "Cost        : $" << setw(8) << carParts[i].cost << endl;
    }

    cout << "\nInventory listing complete.\n";

    return 0;
}