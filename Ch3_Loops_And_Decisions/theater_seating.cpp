#include <iostream>
using namespace std;

int main()
{
    int numRows;
    int numColumns;
    int currentRow;
    char currentRowLetter;
    int currentColumn;
    int currentColumnInteger;

    cin >> numRows;
    cin >> numColumns;

    currentRowLetter = 'A';

    for (currentRow = 1; currentRow <= numRows; currentRow++)
    {

        for (currentColumn = 1; currentColumn <= numColumns; currentColumn++)
        {
            cout << currentRowLetter << currentColumn << " ";
        }
        currentRowLetter++;
        cout << endl;
    }

    return 0;
}