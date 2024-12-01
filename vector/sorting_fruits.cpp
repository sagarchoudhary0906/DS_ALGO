/**
 * Given a vector of pairs of a string and an integer representing names and prices of different fruits.
 * A string is also passed as a parameter with name equals either "price",
 * meaning you have to sort the fruits on the basis of their price or "name",
 * which means you have to sort the fruit on the basis of their name.
 */

#include <iostream>
#include <vector>
using namespace std;

bool comparePrice(pair<string, int> p1, pair<string, int> p2) {
    return p1.second < p2.second;
}

int main()
{
    vector<pair<string, int>> v = {{"Mango", 100}, {"Grapes", 40}, {"Apple", 60}, {"Guava", 70}, {"Banana", 30}};
    string S = "name";

    if (S == "price")
    {
        sort(v.begin(), v.end(), comparePrice);
    }
    else
    {
        sort(v.begin(), v.end());
    }

    for (pair<string, int> p : v)
    {
        cout << "(" << p.first << "," << p.second << ")" << endl;
    }
    return 0;
}