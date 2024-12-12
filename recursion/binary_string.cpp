#include <iostream>
using namespace std;
/**
 * Print num of binary strings can be made of length n with no consecutive 1s
 */

int binaryStrings(int n, string str)
{
    if (str.length() >= 2)
    {
        char c1 = str[str.length() - 1];
        char c2 = str[str.length() - 2];

        if (c1 == '1' && c2 == '1')
        {
            return 0;
        }
    }


    if (n == 0)
    {
        return 1;
    }

    return binaryStrings(n - 1, str + "1") + binaryStrings(n - 1, str + "0");
}

int main()
{
    int n = 4;
    cout << binaryStrings(n, "");
    return 0;
}