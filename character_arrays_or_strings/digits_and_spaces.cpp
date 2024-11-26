#include <iostream>
// #include <cstring>
using namespace std;

int main()
{
    int spaces = 0;
    int alpha = 0;
    int digits = 0;
    char temp = cin.get();

    while (temp != '\n')
    {
        if (temp >= '0' && temp <= '9')
        {
            digits++;
        }
        else if ((temp >= 'a' && temp <= 'z') || (temp >= 'A' && temp <= 'Z'))
        {
            alpha++;
        }
        else if (temp == ' ' || temp == '\t')
        {
            spaces++;
        }
        temp = cin.get();
    }

    cout << "Total Alphabets = " << alpha << endl;
    cout << "Total Digits = " << digits << endl;
    cout << "Total Spaces = " << spaces << endl;
    return 0;
}
