#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1 = "test";
    string s2 = "ttew";
    int maxLen = max(s1.length(), s2.length());
    int freq1[200] = {0};
    int freq2[200] = {0};
    for (char c1 : s1)
    {
        freq1[c1] = freq1[c1] + 1;
    }
    for (char c2 : s2)
    {
        freq2[c2] = freq2[c2] + 1;
    }

    bool isPerm = true;

    for (char ch : s1)
    {
        if (freq1[ch] != freq2[ch])
        {
            isPerm = false;
            break;
        }
    }
    cout << endl;
    cout << "Are Permutation = " << isPerm << endl;
    return 0;
}