#include<iostream>
using namespace std;

// Time complexity is O(n)
/**
 * This Algo states that if there is some negative value addition in positve value addition then it will shoot down the overall value
 * but if there is a psoitive value addition in some other positive value them it will shoot up the overall value
 * Hence when the ucrrent sum is less than 0 that time we are considering 0 as current sum beacuse including that negative will only shoot down the overall value
 */
int kadeneAlgo(int arr[], int size) {
    int maxSum = 0;
    int currSum = 0;
    for(int i = 0; i < size ; i ++) {
        currSum  = currSum + arr[i];
        if(currSum < 0) {
            currSum = 0;
        }
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}

int main() {
    int arr[9] = {-2, 3, 4, -1, 5, -12, 6, 1, 3};
    int size = 9;
    cout << "Max Subarray Sum = " << kadeneAlgo(arr, size);
    return 0;
}