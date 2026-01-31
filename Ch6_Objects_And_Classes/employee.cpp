/*
4. Create an Employee class with:
   - empNum (int): employee number
   - empCompen (float): compensation
   - Member functions to enter and display this data.

5. Create a Date class with:
   - day, month, year (int)
   - Functions to input and display date in dd/mm/yyyy format.

6. Extend the Employee class to include:
   - A Date object for hire date
   - An EmpType enum for employee role
   This program inputs and displays data for three employees.
*/

#include <iostream>
using namespace std;

// ------------------- ENUM TYPE -------------------
enum EmpType
{
    laborer = 1,
    secretary,
    manager,
    accountant,
    executive,
    researcher
};

// ------------------- DATE CLASS -------------------
class Date
{
private:
    int day, month, year;

public:
    Date() : day(0), month(0), year(0) {}
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    void getDate()
    {
        cout << "Enter date (dd mm yyyy): ";
        cin >> day >> month >> year;
    }

    void showDate() const
    {
        cout << day << "/" << month << "/" << year;
    }
};

// ------------------- EMPLOYEE CLASS -------------------
class Employee
{
private:
    int empNum;
    float empCompen;
    Date hireDate;
    EmpType empType;

public:
    Employee() : empNum(0), empCompen(0.0f), empType(laborer) {}

    void getEmployeeData()
    {
        cout << "Enter Employee Number: ";
        cin >> empNum;

        cout << "Enter Employee Compensation: $";
        cin >> empCompen;

        hireDate.getDate();

        cout << "Enter Employee Type (1. Laborer, 2. Secretary, 3. Manager, 4. Accountant, 5. Executive, 6. Researcher): ";
        int typeInput;
        cin >> typeInput;

        while (!(typeInput >= 1 && typeInput <= 6))
        {
            cout << "Invalid type. Enter number 1 - 6." << endl;
            cin >> typeInput;
        }
        empType = static_cast<EmpType>(typeInput);
    }

    void display() const
    {
        cout << "\nEmployee Number: " << empNum
             << "\nCompensation: $" << empCompen
             << "\nHire Date: ";
        hireDate.showDate();
        cout << "\nEmployee Type: ";

        switch (empType)
        {
        case laborer:
            cout << "Laborer";
            break;
        case secretary:
            cout << "Secretary";
            break;
        case manager:
            cout << "Manager";
            break;
        case accountant:
            cout << "Accountant";
            break;
        case executive:
            cout << "Executive";
            break;
        case researcher:
            cout << "Researcher";
            break;
        }

        cout << endl;
    }
};

// ------------------- MAIN FUNCTION -------------------
int main()
{
    Employee emp1, emp2, emp3;

    cout << "Enter details for Employee 1:\n";
    emp1.getEmployeeData();

    cout << "\nEnter details for Employee 2:\n";
    emp2.getEmployeeData();

    cout << "\nEnter details for Employee 3:\n";
    emp3.getEmployeeData();

    cout << "\n========== EMPLOYEE DETAILS ==========\n";
    emp1.display();
    emp2.display();
    emp3.display();

    return 0;
}