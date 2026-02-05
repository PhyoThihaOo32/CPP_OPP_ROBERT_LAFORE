/*
Program: Safe Array Implementation
------------------------------------------------------------
Description:
This program defines a class `SafeArray` that prevents array
index out-of-bounds errors. It checks the validity of the
index before inserting (putElement) or retrieving (getElement)
data from an internal fixed-size integer array.

Demonstrates:
- Encapsulation for safe array access
- Input validation to avoid memory corruption
- Basic array initialization and access
*/

#include <iostream>
using namespace std;

class SafeArray
{
private:
    static const int LIMIT = 10; // Fixed array size
    int arr[LIMIT];              // Internal integer array

public:
    // Constructor initializes all elements to 0
    SafeArray()
    {
        for (int i = 0; i < LIMIT; i++)
            arr[i] = 0;
    }

    // Insert value into array at given index (with boundary check)
    void putElement(int index, int value)
    {
        if (index >= 0 && index < LIMIT)
            arr[index] = value;
        else
            cout << "Error: Invalid index (" << index << ").\n";
    }

    // Retrieve value from given index (with boundary check)
    int getElement(int index) const
    {
        if (index >= 0 && index < LIMIT)
            return arr[index];
        else
        {
            cout << "Error: Invalid index (" << index << ").\n";
            return -1;
        }
    }

    // Display all elements of array
    void printArray() const
    {
        cout << "\nArray contents: ";
        for (int i = 0; i < LIMIT; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main()
{
    SafeArray arr;

    // Insert values safely
    for (int i = 0; i < 10; i++)
        arr.putElement(i, i * 100);

    // Attempt invalid access
    arr.putElement(10, 3000); // Index 10 is out of bounds

    // Display array contents
    arr.printArray();

    // Retrieve a few values
    cout << "arr[3] = " << arr.getElement(3) << endl;
    cout << "arr[9] = " << arr.getElement(9) << endl;

    return 0;
}