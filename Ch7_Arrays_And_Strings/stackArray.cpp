/*
Program: Simple Integer Stack
------------------------------
Description:
Implements a fixed-size stack (LIFO - Last In, First Out) using an array.
- Allows pushing integers until the stack is full.
- Pops and prints values in reverse order of insertion.

*/

#include <iostream>
using namespace std;

class Stack
{
private:
    static const int MAX = 10; // Maximum stack size
    int arr[MAX];              // Stack storage
    int nextIndex;             // Index of the top element

public:
    Stack() : nextIndex(-1) {} // Initialize as empty

    // Push an element onto the stack
    void push(int value)
    {
        if (nextIndex >= MAX - 1)
        {
            cout << "Stack full — can’t add more elements!" << endl;
            return;
        }
        arr[++nextIndex] = value;
    }

    // Pop the top element
    int pop()
    {
        if (nextIndex < 0)
        {
            cout << "Stack empty — nothing to pop!" << endl;
            return -1;
        }
        return arr[nextIndex--];
    }
};

int main()
{
    Stack s1;
    int userInput;

    // Push 10 elements
    for (int i = 0; i < 10; i++)
    {
        cout << "Enter value at index " << i << " :";
        cin >> userInput;
        s1.push(userInput);
    }

    // Try pushing one more to show the full message
    cout << "\nTrying to add another value..." << endl;
    s1.push(999);

    // Pop and display values
    cout << "\nPopping values: ";
    for (int i = 0; i < 10; i++)
    {
        cout << s1.pop() << " ";
    }

    // Try popping once more to show empty message
    cout << "\nTrying to pop from empty stack..." << endl;
    s1.pop();

    return 0;
}