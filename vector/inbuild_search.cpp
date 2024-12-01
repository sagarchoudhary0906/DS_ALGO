#include <iostream>
using namespace std;

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int key = 7;

    vector<int>::iterator i = find(arr.begin(), arr.end(), key);
    if (i != arr.end())
    {
        cout << "Element is present at index = " << i - arr.begin();
    }
    else
    {
        cout << "Element is not present";
    }
    return 0;
}