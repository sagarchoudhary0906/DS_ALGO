#include<iostream>
using namespace std;

int lastOccurenceIdx(vector<int> v, int si, int ei, int key) {
    if (ei < si) {
        cout << "Key is Not present";
        return -1;
    }

    if (v[ei] == key) {
         cout << "Key is  present at = ";
        return ei;
    }
    return lastOccurenceIdx(v, si, ei - 1, key);
}

int main() {
   
    vector<int> v = {1, 4, 2, 5, 23, 34, 23};
    int si = 0;
    int ei = v.size() - 1;
    int key = 23;
    cout << lastOccurenceIdx(v, si, ei, key);
    return 0;
}