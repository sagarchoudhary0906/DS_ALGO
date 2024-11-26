#include<iostream>
using namespace std;

/**
 * - Linear search is a searching algorithm
 * - time complexity is O(n).
 * - Brute force technique 
 * - It search linearly
 */

bool linearSearch(int *arr, int key, int size) {
    bool present = false;
    for(int i = 0 ; i < size ; i ++) {
        int curElement = arr[i];
        if (curElement == key) {
            present = true;
            break;
        }
    }
    return present;
}
int main() {

    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "Enter the key you want to search = "<< endl;
    int key;
    cin >> key;

    int size = sizeof(arr) / sizeof(int);

    if (linearSearch(arr, key, size)) {
        cout << "You number " << key <<" is present in the provided array";
    } else {
        cout << "You number " << key <<" is not present in the provided array";
    }

    return 0;
}