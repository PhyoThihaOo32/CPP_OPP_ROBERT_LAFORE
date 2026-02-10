#include <iostream>
#include <string>

using namespace std;

int main()
{

    string userInput;
    int alphaCount = 0, digitCount = 0;

    cout << "Enter: ";
    getline(cin, userInput);

    for (int i = 0; i < userInput.length(); i++)
    {
        if (isalpha(userInput.at(i)))
        {
            alphaCount++;
        }
        if (isdigit(userInput.at(i)))
        {
            digitCount++;
        }
    }

    cout << "Alphabet: " << alphaCount << endl
         << "Digit: " << digitCount << endl;

    return 0;
}