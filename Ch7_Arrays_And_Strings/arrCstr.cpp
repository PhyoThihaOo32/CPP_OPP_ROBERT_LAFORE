/*
Program: Multi-Dimensional Employee and Office Data Tracker
------------------------------------------------------------
Description:
This program demonstrates how to use multi-dimensional character arrays (C-style strings)
to store hierarchical data:
- 2D array: days of the week
- 3D array: employee names grouped by office

Key Concepts:
- 2D and 3D arrays for string storage
- Nested loops for input and output
- Organized structured data representation

Author: Phyo T. Oo
*/

#include <iostream>
using namespace std;

int main()
{
    const int DAYS = 7;
    const int MAX_CHAR = 10;
    const int NUM_EMPLOYEE = 2;
    const int EMP_NAMES = 50;
    const int NUM_OFFICE = 2;

    char daysOfWeeks[DAYS][MAX_CHAR];
    char employeeNames[NUM_EMPLOYEE][EMP_NAMES] = {"Pepito Mucho", "Max Halloway"};
    char specificEmpName[NUM_OFFICE][NUM_EMPLOYEE][EMP_NAMES];

    // --- Input Section: Days of the Week ---
    cout << "=== Enter Days of the Week ===" << endl;
    for (int i = 0; i < DAYS; i++)
    {
        cout << "Day " << i + 1 << ": ";
        cin >> daysOfWeeks[i];
    }

    // --- Display Days ---
    cout << "\n--- Days of the Week ---" << endl;
    for (int i = 0; i < DAYS; i++)
    {
        cout << daysOfWeeks[i] << " ";
    }
    cout << "\n";

    // --- Display Predefined Employee Names ---
    cout << "\n--- Company Employee List ---" << endl;
    for (int i = 0; i < NUM_EMPLOYEE; i++)
    {
        cout << "Employee " << i + 1 << ": " << employeeNames[i] << endl;
    }

    // --- Input Section: Employees per Office ---
    cout << "\n=== Enter Employees Assigned per Office ===" << endl;
    for (int i = 0; i < NUM_OFFICE; i++)
    {
        cout << "\nOffice No. " << i + 1 << ":" << endl;
        for (int j = 0; j < NUM_EMPLOYEE; j++)
        {
            cout << "  Employee " << j + 1 << " Name: ";
            cin >> specificEmpName[i][j];
        }
    }

    // --- Output Section: Employees per Office ---
    cout << "\n=== Employees Organized by Office ===" << endl;
    for (int i = 0; i < NUM_OFFICE; i++)
    {
        cout << "Office " << i + 1 << ":" << endl;
        for (int j = 0; j < NUM_EMPLOYEE; j++)
        {
            cout << "  " << specificEmpName[i][j] << endl;
        }
    }

    return 0;
}