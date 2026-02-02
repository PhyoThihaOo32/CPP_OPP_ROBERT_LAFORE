#include <iostream>
#include <cstring> // required for strcpy

using namespace std;

class Parts
{
private:
    // Shared constant for name size
    static const int SIZE = 20;
    char pName[SIZE];
    int pNum;
    float pCost;

public:
    // Default constructor
    Parts()
    {
        strcpy(pName, ""); // Initialize string safely
        pNum = 0;
        pCost = 0.0;
    }

    // Parameterized setter
    void setParts(const char p[], int num, float cost)
    {
        strncpy(pName, p, SIZE - 1); // safer copy (avoids overflow)
        pName[SIZE - 1] = '\0';      // ensure null termination
        pNum = num;
        pCost = cost;
    }

    // Display function
    void display() const
    {
        cout << "Name: " << pName << endl
             << "Number: " << pNum << endl
             << "Cost: $" << pCost << endl
             << "----------------------" << endl;
    }
};

int main()
{
    Parts p1, p2, p3;

    p1.setParts("Engine", 101, 250.99);
    p2.setParts("Gearbox", 102, 2000.99);
    // p3 remains default (uninitialized values)

    p1.display();
    p2.display();
    p3.display();

    return 0;
}

/*
Note:
-----
- `static int` → shared variable (same for all objects), can be modified.
  Declaration: static int count;      // define outside class
  Definition:  int ClassName::count = 0;

- `static const int` → shared constant, fixed at compile time, cannot change.
  Declaration & initialization inside class:
  static const int SIZE = 30;         // no need for outside definition

- Use `static int` for counters or shared state.
- Use `static const int` for constants like array sizes or limits.
*/

/*
============================================================
📘 strcpy() vs strncpy() — Safe String Copy Visual Guide
============================================================

Setup:
-------
const int SIZE = 6;
char dest[SIZE];

------------------------------------------------------------
🟢 Case 1: Source fits ("car")
------------------------------------------------------------
✅ strcpy(dest, "car");
Index | 0 | 1 | 2 | 3 | 4 | 5
Value | c | a | r | \0 | ? | ?
- Works fine.
- Automatically adds '\0' at the end.

✅ strncpy(dest, "car", SIZE - 1);
   dest[SIZE - 1] = '\0';
Index | 0 | 1 | 2 | 3 | 4 | 5
Value | c | a | r | \0 | ? | \0
- Safe copy.
- Guarantees '\0' termination even if shorter.

------------------------------------------------------------
🔴 Case 2: Source too long ("engine")
------------------------------------------------------------
⚠️ strcpy(dest, "engine");
Index | 0 | 1 | 2 | 3 | 4 | 5
Value | e | n | g | i | n | e
❌ No '\0', buffer overflow → undefined behavior!

✅ strncpy(dest, "engine", SIZE - 1);
   dest[SIZE - 1] = '\0';
Index | 0 | 1 | 2 | 3 | 4 | 5
Value | e | n | g | i | n | \0
- Truncates safely.
- Always null-terminated, prevents overflow.

------------------------------------------------------------
✅ Summary:
------------------------------------------------------------
| Function                | Adds '\0' | Prevents Overflow | Safe (Short) | Safe (Long) |
|--------------------------|------------|------------------|--------------|-------------|
| strcpy()                 | ✅ (if space) | ❌              | ✅           | ❌          |
| strncpy() + manual '\0'  | ✅ always   | ✅              | ✅           | ✅          |

💡 Best Practice:
-----------------
strncpy(dest, src, SIZE - 1);
dest[SIZE - 1] = '\0';  // Always safe and predictable
============================================================
*/