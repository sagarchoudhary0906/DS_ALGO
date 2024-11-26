#include <iostream>
using namespace std;

/**
 * - Binary Search is a searching alogirthm
 * - Time complexixty is O(log n)
 * - Because Binary Search is only applied on a sorted space set
 */


bool binarySearchIsPresent(int *arr, int key, int size) {
    bool present = false;
    int si = 0;
    int ei = size - 1;

    while (si < ei) {
        int midPoint = (si + ei) / 2;

        int num = arr[midPoint];
        if (num == key) {
            present = true;
            break;
        }
        if (num < key) {
            si = si + 1;
        } else {
            ei = ei - 1;
        }
    }

    return present;
} 

int getIndexOfKey(int *arr, int key, int size) {
    int index = -1;
    int si = 0;
    int ei = size - 1;

    while (si < ei) {
        int midPoint = (si + ei) / 2;

        int num = arr[midPoint];
        if (num == key) {
            index = midPoint;
            break;
        }
        if (num < key) {
            si = si + 1;
        } else {
            ei = ei - 1;
        }
    }
    return index;
}


int main()
{

    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8 , 9, 10};
    int key;
    cout << "Enter Key you want to search = ";
    cin >> key;
    int size = sizeof(arr)/ sizeof(int);

    bool present = binarySearchIsPresent(arr, key, size);

    if(present) {
        cout<< "You key is present" << endl;
    } else {
        cout << "Key is not present"<< endl;
    }

    int index = getIndexOfKey(arr, key, size);
    if (index != -1) {
         cout<< "You key is present at index " << index<< endl;
    } else {
         cout<< "You key is not present"<< endl;
    }

    return 0;
}