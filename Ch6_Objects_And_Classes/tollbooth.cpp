/*
2.

Imagine a tollbooth at a bridge. Cars passing by the booth are expected to pay a 50-cent toll.
Mostly they do, but sometimes a car goes by without paying.
The tollbooth keeps track of the number of cars that have gone by,
and of the total amount of money collected.

Model this tollbooth with a class called tollBooth. The two data items are a type unsigned int
to hold the total number of cars, and a type double to hold the total amount of money collected.
A constructor initializes both of these to 0. A member function called payingCar()
increments the car total and adds 0.50 to the cash total. Another function, called nopayCar(),
increments the car total but adds nothing to the cash total.
Finally, a member function called display() displays the two totals.
Make appropriate member functions const.

Include a program to test this class. This program should allow the user to push one key
to count a paying car, and another to count a nonpaying car. Pushing the Esc key should cause
the program to print out the total cars and total cash and then exit.

*/

#include <iostream>

using namespace std;

class TollBooth
{
private:
    unsigned int numberOfCars, noPayCars;
    double moneyCollected;

public:
    TollBooth() : numberOfCars(0), noPayCars(0), moneyCollected(0.0)
    {
    }

    void payingCars()
    {
        numberOfCars++;
        moneyCollected += 0.5;
    }

    void noPayingCars()
    {
        numberOfCars++;
        noPayCars++;
    }

    void display() const
    {
        cout << "Number of Cars: " << numberOfCars << endl
             << "Total Money Collected: " << moneyCollected << " $" << endl
             << "No Paying Cars: " << noPayCars << endl
             << "Toll Fees = 0.5 cents " << endl;
    }
};

int main()
{

    TollBooth midtownTunnel;

    int input;

    do
    {
        do
        {
            cout << "Press 1: Paying Car.\nPress 2: No Paying Car.\nPress 0: Exit Program." << endl;
            cin >> input;
        } while (!(input == 1 || input == 2 || input == 0));

        switch (input)
        {
        case 1:
            midtownTunnel.payingCars();
            break;
        case 2:
            midtownTunnel.noPayingCars();
            break;
        case 0:
            cout << "Exiting Program" << endl;
            midtownTunnel.display();
            break;
        }
    } while (input != 0);

    return 0;
}