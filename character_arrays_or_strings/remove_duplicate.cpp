#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s = "geeksforgeeks";
    int freq[200] = {0};

    for (char ch : s)
    {
        freq[ch] = freq[ch] + 1;
    }

    string ss = "";
    for (int i = 0; i < 200; i++)
    {
        if (freq[i] != 0)
        {
            char cc = char(i);
            ss = ss + cc;
        }
    }
    cout << ss << endl;
    return 0;
}