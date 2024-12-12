#include<iostream>
using namespace std;

int firstOccurenceIdx(vector<int> v, int si, int ei, int key) {
    if (si > ei) {
        cout << "Key is Not present";
        return -1;
    }

    if (v[si] == key) {
         cout << "Key is  present at = ";
        return si;
    }
    return firstOccurenceIdx(v, si + 1, ei, key);
}

int main() {
   
    vector<int> v = {1, 4, 2, 5, 23, 34, 23};
    int si = 0;
    int ei = v.size() - 1;
    int key = 23;
    cout << firstOccurenceIdx(v, si, ei, key);
    return 0;
}