/*
Program: Multi-Dimensional Sales Data Tracker
-------------------------------------------------------
Description:
This program uses a 3D array to store sales figures for multiple districts,
months, and days. It demonstrates how to handle multi-dimensional arrays,
nested loops, function modularization, and formatted output.

Details:
- There are 4 districts, 4 months, and 3 days of data.
- Sales data can be entered manually by the user.
- The program displays all the data in a structured format
  and computes the total and average sales per district.
- This model can easily be extended for monthly or company-wide summaries.

Author: Phyo Thiha
*/

#include <iostream>
#include <iomanip> // for setprecision and formatting output
using namespace std;

// Define array dimensions
const int DISTRICT = 4; // Number of districts
const int MONTH = 4;    // Number of months
const int DAYS = 3;     // Number of days per month

// Function prototypes
void getSales(double[][MONTH][DAYS]);
void display(const double[][MONTH][DAYS]);
void showTtlAvg(const double[][MONTH][DAYS]);

int main()
{
    // Declare 3D array for sales data
    double sales[DISTRICT][MONTH][DAYS] = {};

    // Step 1: Get user input for sales
    getSales(sales);

    // Step 2: Display sales data
    cout << fixed << setprecision(2); // show numbers with two decimal places
    cout << "\n=== Sales Report ===" << endl;
    display(sales);

    // Step 3: Show total and average per district
    showTtlAvg(sales);

    return 0;
}

/*
-----------------------------------------------------------
Function: getSales()
Purpose:  Accepts user input for each district, month, and day.
-----------------------------------------------------------
*/
void getSales(double sales[][MONTH][DAYS])
{
    cout << "=== Enter Sales Data ===" << endl;
    for (int d = 0; d < DISTRICT; d++)
    {
        cout << "\n--- District " << d + 1 << " ---" << endl;
        for (int m = 0; m < MONTH; m++)
        {
            for (int day = 0; day < DAYS; day++)
            {
                cout << "Enter sales for District " << d + 1
                     << ", Month " << m + 1
                     << ", Day " << day + 1 << ": ";
                cin >> sales[d][m][day];
            }
        }
    }
}

/*
-----------------------------------------------------------
Function: display()
Purpose:  Prints all stored sales in a structured format.
-----------------------------------------------------------
*/
void display(const double sales[][MONTH][DAYS])
{
    cout << "\n--- Detailed Sales Data ---" << endl;
    for (int d = 0; d < DISTRICT; d++)
    {
        cout << "\nDistrict " << d + 1 << ":" << endl;
        for (int m = 0; m < MONTH; m++)
        {
            cout << "  Month " << m + 1 << ":" << endl;
            for (int day = 0; day < DAYS; day++)
            {
                cout << "    Day " << day + 1 << " = $"
                     << setw(6) << sales[d][m][day] << endl;
            }
        }
    }
}

/*
-----------------------------------------------------------
Function: showTtlAvg()
Purpose:  Calculates and displays total and average sales
          per district.
-----------------------------------------------------------
*/
void showTtlAvg(const double sales[][MONTH][DAYS])
{
    cout << "\n=== Summary by District ===" << endl;
    for (int d = 0; d < DISTRICT; d++)
    {
        double total = 0.0;
        int count = 0;

        for (int m = 0; m < MONTH; m++)
        {
            for (int day = 0; day < DAYS; day++)
            {
                total += sales[d][m][day];
                count++;
            }
        }

        cout << "District " << setw(2) << d + 1
             << " | Total Sales: $" << setw(8) << total
             << " | Average: $" << setw(8) << total / count << endl;
    }
}