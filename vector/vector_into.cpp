#include<iostream>
#include<vector>
using namespace std;

/**
 * Pushing an element at the back of vector is O(1) but in some case it is O(n) in case of doubling the size of vector
 * - On average term it is O(1)
 */

int main() {
    vector<int> arr; // 0 Size
    arr = {1, 2, 3, 4, 15, 6};
    arr.push_back(18);
    cout << arr.size() << endl; // size of vector = 6
    cout << arr.capacity() << endl; // Capacity of vector = 12

    vector<int> arr1(10, 7); //this satest that vector arr1 has 10 elements where each cell value is 7

    // 2-D Vector
    vector<vector<int>> mat; // Here each row can have different number of elements
    mat = {
        {1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 2}
    };
    return 0;
}