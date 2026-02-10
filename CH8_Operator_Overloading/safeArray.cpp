#include <iostream>
using namespace std;

class Array
{
private:
    static const int SIZE = 10;
    int array[SIZE];

public:
    // ❌ You marked this const, but operator[] returns a non-const reference (can modify elements)
    // ✅ Remove const from this declaration if you want to allow modification (e.g., arr[i] = 5;)
    int &operator[](int index);

    // ✅ Add a constructor to initialize the array (optional)
    Array()
    {
        for (int i = 0; i < SIZE; i++)
            array[i] = 0;
    }

    // ✅ For viewing the array content (optional)
    void display() const
    {
        for (int i = 0; i < SIZE; i++)
            cout << array[i] << " ";
        cout << endl;
    }
};

// Overloaded [] operator definition
int &Array::operator[](int index)
{
    // ✅ Check for bounds
    if (index >= 0 && index < SIZE)
    {
        return array[index]; // ✅ Return reference allows modification
    }
    else
    {
        cout << "Error: Index out of range." << endl;
        static int dummy = -1; // ⚠️ Dummy variable to safely return reference if invalid
        return dummy;
    }
}

int main()
{
    Array arr;

    arr[0] = 100;  // ✅ Works: modifies first element
    arr[5] = 500;  // ✅ Works
    arr[11] = 999; // ❌ Triggers error message

    arr.display(); // ✅ Displays array

    cout << "arr[0]: " << arr[0] << endl;

    return 0;
}

/*
🔍 NOTES & FIXES:
-----------------
1️⃣ operator[] should not be const
    ❌ You wrote: int &operator[](int) const;
    ✅ Fix: int &operator[](int);

    ➤ Reason: Returning a non-const reference allows modification (arr[i] = value;).
      If you really want a const version (for read-only), you can overload a second version:
      const int &operator[](int index) const;

2️⃣ Missing return path for invalid index
    ❌ Your version only returned if the index was valid.
    ✅ Added dummy static variable to return safely when out of range.

3️⃣ Added constructor to initialize elements to 0 — makes testing cleaner.

4️⃣ Added `display()` to visualize stored values.

5️⃣ If you want **read-only access**, overload another version:
    const int &operator[](int index) const { ... }  // for const objects
*/