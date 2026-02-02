#include <iostream>
#include <cstring>

using namespace std;

int main()
{

    const int SIZE = 1000;
    int i;

    char str1[] = "Do not go gentle into that good night,\n"
                  "Old age should burn and rave at close of day;\n"
                  "Rage, rage against the dying of the light.";

    char str2[] = "I have been one acquainted with the night,\n"
                  "I have walked out in rain—and back in rain.\n"
                  "I have outwalked the furthest city light.\n";

    char copyStr[SIZE];

    for (i = 0; i < strlen(str1); i++)
    {
        copyStr[i] = str1[i];
    }

    copyStr[i] = '\0';

    cout << copyStr;

    cout << endl;

    strcpy(copyStr, str2);

    cout << copyStr << endl;

    return 0;
}