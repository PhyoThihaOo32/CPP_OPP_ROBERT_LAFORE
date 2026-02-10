/*
Program: Find Maximum Integer in an Array
------------------------------------------------------------
Description:
This program allows the user to input a fixed number of integers
into an array and determines the largest integer among them.
It uses a function `maxInt()` that scans through the array,
finds the largest value, and returns its index.

Demonstrates:
- Passing arrays to functions
- Searching for maximum values
- Using returned indices to access array elements
*/

#include <iostream>
using namespace std;

// Function prototype
int maxInt(int[], int);

int main()
{
    const int SIZE = 10;
    int arr[SIZE];

    // Input numbers from the user
    cout << "Enter " << SIZE << " integers:\n";
    for (int i = 0; i < SIZE; i++)
    {
        cout << "  Number " << i + 1 << ": ";
        cin >> arr[i];
    }

    // Find index of largest element
    int maxIndex = maxInt(arr, SIZE);

    // Display result
    cout << "\nLargest number: " << arr[maxIndex]
         << " (at index " << maxIndex << ")\n";

    return 0;
}

/*
------------------------------------------------------------
Function: maxInt()
Purpose:
  Finds and returns the index of the largest element in an array.

Parameters:
  - arr[]: The integer array to search.
  - size:  Number of elements in the array.

Returns:
  The index of the largest integer found.

Algorithm:
  1. Assume first element is largest.
  2. Traverse array comparing each value.
  3. Update maxIndex when a larger value is found.
------------------------------------------------------------
*/
int maxInt(int arr[], int size)
{
    int maxIndex = 0;     // Assume first element is largest
    int largest = arr[0]; // Store its value

    for (int i = 1; i < size; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
            maxIndex = i;
        }
    }
    return maxIndex;
}