/*
This program count the larger element from the array.
*/

#include <iostream>

using namespace std;

int countLarger(int[], int, int);
void setArrayElements(int[], int);

int main()
{

    const int SIZE = 5;
    int count;
    int array[SIZE];

    setArrayElements(array, SIZE);

    count = countLarger(array, SIZE, 20);

    cout << count << endl;

    return 0;
}

int countLarger(int arr[], int size, int x)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > x)
            count++;
    }

    return count;
}

void setArrayElements(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Enter " << i + 1 << " element: ";
        cin >> arr[i];
    }
}