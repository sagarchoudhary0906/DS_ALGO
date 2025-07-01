#include<iostream>
#include<stack>
using namespace std;

int main() {
    stack<int> s;
    int n = 456;
    while (n > 0) {
        int lastNum = n % 10;
        s.push(lastNum);
        n = n / 10;
    }

    int ans = 0;
    int multiplier = 1;
    while (!s.empty())
    {
        int top = s.top();
        s.pop();
        ans = ans + (multiplier * top);
        multiplier = multiplier * 10;
    }
    cout << ans;
    return 0;
}