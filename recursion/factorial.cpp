#include <iostream>
using namespace std;

int factorial(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    return n * factorial(n - 1);
};

int main()
{
    int n = 4;
    cout << "Factorial is = " << factorial(n);
    return 0;
}