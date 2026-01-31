/*
This program demonstrates how to use an enumeration (enum) with switch statements
to input and display an employee type. The user enters the first letter of the type,
which is then mapped to the corresponding enum value and printed in full.
*/

#include <iostream>
using namespace std;

// Define enumeration for employee types
enum etype
{
    laborer,
    secretary,
    manager,
    accountant,
    executive,
    researcher
};

int main()
{
    etype emp1;
    char type;

    cout << "Enter employee type (first letter only)\n";
    cout << "laborer, secretary, manager, accountant, executive, researcher: ";
    cin >> type;

    // Convert input character to enum value
    switch (type)
    {
    case 'l':
    case 'L':
        emp1 = laborer;
        break;
    case 's':
    case 'S':
        emp1 = secretary;
        break;
    case 'm':
    case 'M':
        emp1 = manager;
        break;
    case 'a':
    case 'A':
        emp1 = accountant;
        break;
    case 'e':
    case 'E':
        emp1 = executive;
        break;
    case 'r':
    case 'R':
        emp1 = researcher;
        break;
    default:
        cout << "Invalid input. Exiting program." << endl;
        return 1;
    }

    // Output the full employee type
    cout << "Employee type is ";

    switch (emp1)
    {
    case laborer:
        cout << "laborer";
        break;
    case secretary:
        cout << "secretary";
        break;
    case manager:
        cout << "manager";
        break;
    case accountant:
        cout << "accountant";
        break;
    case executive:
        cout << "executive";
        break;
    case researcher:
        cout << "researcher";
        break;
    }

    cout << "." << endl;

    return 0;
}