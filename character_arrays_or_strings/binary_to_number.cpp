#include<iostream>
#include<string>
using namespace std;

int binaryToDecimal(string s)
{
    int ans = 0 ; 
    int length = s.length();
    int maxPow = length - 1;
    int multiplier = 1;
    while (maxPow > 0) {
        multiplier = 2 * multiplier;
        maxPow--;
    }

    for (char ch : s) {
        if (ch == '1') {
            ans = ans + (multiplier);
        }
        multiplier = multiplier / 2;
    }

    return ans;
}

int main() {
    string s = "1111";
    cout << binaryToDecimal(s);
    return 0;
}