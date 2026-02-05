/*
2.
Create a class called employee that contains a name (an object of class string) and
an employee number (type long). Include a member function called getdata() to get data
from the user for insertion into the object, and another function called putdata() to display the data.
Assume the name has no embedded blanks.
Write a main() program to exercise this class. It should create an array of type employee,
and then invite the user to input data for up to 100 employees. Finally,
it should print out the data for all the employees.
*/

#include <iostream>
#include <string>

using namespace std;

class Employee
{
private:
    string empName;
    long empId;

public:
    Employee() : empName(""), empId(0) {}
    Employee(string name, long id) : empName(name), empId(id) {};
    void getData()
    {

        int count = 1;
        cout << "Enter Employee " << count << " Name: ";
        getline(cin, empName);
        cout << "Enter Employee " << count << " ID: ";
        cin >> empId;
        cin.ignore();
        count++;
    }
    void displayData() const
    {
        int count = 1;
        cout << "Employee " << count << " Name: " << empName << endl;
        cout << "Employee " << count << " Id: " << empId << endl;
    }
};

int main()
{

    const int SIZE = 5;
    Employee emp[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        emp[i].getData();
    }

    for (int i = 0; i < SIZE; i++)
    {
        emp[i].displayData();
    }

    return 0;
}