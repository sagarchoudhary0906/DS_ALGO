/**
 * Given a vector of pairs representing coordinates x and y of different cabs on a X-Y plane.
 * Sort them according to their distance from the origin in the non-decreasing order i.e. the cab with shortest distance from the origin will be at first.
 * Sample Input
 * { (2,3), (1,2), (3,4), (2,4), (1,4) }
 *
 * Sample Output
 * { (1, 2), (2, 3), (1, 4), (2, 4), (3, 4) }
 */

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2)
{
    float distance1 = sqrt((p1.first * p1.first) + (p1.second * p1.second));
    float distance2 = sqrt((p2.first * p2.first) + (p2.second * p2.second));
    return distance1 < distance2;
}

int main()
{
    vector<pair<int, int>> v = {{2, 3}, {1, 2}, {3, 4}, {2, 4}, {1, 4}};
    sort(v.begin(), v.end(), compare);

    for (pair<int, int> p : v)
    {
        cout << "(" << p.first << "," << p.second << ")" << endl;
    }
    return 0;
}