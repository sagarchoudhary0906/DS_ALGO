#include<iostream>
using namespace std;

void reverseArray(int *arr, int size) {
    int si = 0;
    int ei = size - 1;

    while (si < ei) {
        int siNum = arr[si];
        int eiNum = arr[ei];
        swap(arr[si], arr[ei]);
        si++ ;
        ei--;
    }
}

void printArray(int *arr, int size) {
    for(int i = 0 ; i < size; i ++) {
        cout << arr[i] << ", ";
    }
    cout << endl;
}

int main() {
    int arr[5] = {1, 2, 3, 4 , 5};

    printArray(arr, 5);
    reverseArray(arr, 5);
    printArray(arr, 5);
    return 0;
}