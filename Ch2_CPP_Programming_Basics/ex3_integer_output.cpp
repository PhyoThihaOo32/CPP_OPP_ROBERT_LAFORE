/*
This program demonstrates:
- Integer constant initialization
- Arithmetic assignment operator (*=)
- Pre-decrement operator (--num)
*/

#include <iostream>
using namespace std;

int main()
{
    int num = 10; // Initialize integer constant

    cout << "Initial value: " << num << endl;

    num *= 2; // Multiply num by 2 and assign result back to num
    cout << "After *= 2: " << num << endl;

    --num; // Decrement num by 1 (pre-decrement)
    cout << "After --num: " << num << endl;

    return 0;
}