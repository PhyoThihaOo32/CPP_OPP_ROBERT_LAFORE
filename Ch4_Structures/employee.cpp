/*
7. This program extends the employee structure by adding:
   - An enum Etype (from Exercise 6) to represent employee role
   - A Date struct (from Exercise 5) to record employment start date

   The user enters details for three employees:
   - Employee number
   - Compensation
   - Role (first letter only)
   - Start date (mm dd yyyy)

   The program stores this information and then displays it.
*/

#include <iostream>
using namespace std;

// Enum to represent employee type
enum Etype
{
    laborer,
    secretary,
    manager,
    accountant,
    executive,
    researcher
};

// Structure to store a date
struct Date
{
    int month;
    int day;
    int year;
};

// Structure to store employee data
struct Employee
{
    int empNum;
    float compensation;
    Etype empRole;
    Date employmentDate;
};

// Function prototypes
void setRole(Etype &);
void showEmpRole(Etype);
void showDate(const Date &);

int main()
{
    Employee emp1, emp2, emp3;

    // ---------- EMPLOYEE 1 ----------
    cout << "Enter employee 1 number and compensation: ";
    cin >> emp1.empNum >> emp1.compensation;

    cout << "Enter employee 1 role (first letter only): ";
    setRole(emp1.empRole);

    cout << "Enter employee 1 start date (mm dd yyyy): ";
    cin >> emp1.employmentDate.month >> emp1.employmentDate.day >> emp1.employmentDate.year;

    // ---------- EMPLOYEE 2 ----------
    cout << "\nEnter employee 2 number and compensation: ";
    cin >> emp2.empNum >> emp2.compensation;

    cout << "Enter employee 2 role (first letter only): ";
    setRole(emp2.empRole);

    cout << "Enter employee 2 start date (mm dd yyyy): ";
    cin >> emp2.employmentDate.month >> emp2.employmentDate.day >> emp2.employmentDate.year;

    // ---------- EMPLOYEE 3 ----------
    cout << "\nEnter employee 3 number and compensation: ";
    cin >> emp3.empNum >> emp3.compensation;

    cout << "Enter employee 3 role (first letter only): ";
    setRole(emp3.empRole);

    cout << "Enter employee 3 start date (mm dd yyyy): ";
    cin >> emp3.employmentDate.month >> emp3.employmentDate.day >> emp3.employmentDate.year;

    // ---------- DISPLAY RESULTS ----------
    cout << "\n\nEmployee Information:\n";

    cout << "\nEmployee 1: #" << emp1.empNum << ", Compensation: $" << emp1.compensation << endl;
    showEmpRole(emp1.empRole);
    showDate(emp1.employmentDate);

    cout << "\nEmployee 2: #" << emp2.empNum << ", Compensation: $" << emp2.compensation << endl;
    showEmpRole(emp2.empRole);
    showDate(emp2.employmentDate);

    cout << "\nEmployee 3: #" << emp3.empNum << ", Compensation: $" << emp3.compensation << endl;
    showEmpRole(emp3.empRole);
    showDate(emp3.employmentDate);

    return 0;
}

// ---------- Function Definitions ----------

// Convert user input into employee type
void setRole(Etype &etype)
{
    char type;
    cin >> type;

    switch (tolower(type))
    {
    case 'l':
        etype = laborer;
        break;
    case 's':
        etype = secretary;
        break;
    case 'm':
        etype = manager;
        break;
    case 'a':
        etype = accountant;
        break;
    case 'e':
        etype = executive;
        break;
    case 'r':
        etype = researcher;
        break;
    default:
        cout << "Invalid input. Defaulting to laborer.\n";
        etype = laborer;
    }
}

// Print employee type as text
void showEmpRole(Etype etype)
{
    cout << "Employee type: ";
    switch (etype)
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
    cout << endl;
}

// Display date in mm/dd/yyyy format
void showDate(const Date &date)
{
    cout << "Start Date: " << date.month << "/" << date.day << "/" << date.year << endl;
}