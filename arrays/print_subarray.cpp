#include<iostream>
#include <cmath>
#include <algorithm>
using namespace std;


void printSubarray(int *arr, int size) {
    for (int i = 0 ; i < size; i ++) {
        for (int j = i ; j< size; j++) {
            cout << "[ ";
            for (int k = i ; k <= j; k++) {
                cout << arr[k];
                if (k != j) {
                    cout << ", ";
                }
            }
            cout << " ]" << endl;;
        }
        cout << endl;
    }
} 

int numberOfSubArrays(int size) {
    return (size * (size + 1)) / 2;
}

int largestSubarraySumBruteForce(int *arr, int size) {
    int maxSum = -1;
    for (int i = 0 ; i < size ; i ++) {
        for (int j = i ; j < size ; j ++) {
            int sum = 0;
            for (int k = i ; k <= j ; k++) {
                sum = sum + arr[k];
            }
            maxSum = max(maxSum, sum);
        }
    }
    return maxSum;
}

//Time complexity of prefix sum array is O(n^2) beavuse we have reduced the inner k loop iteration with prefix sum computation
int largestSubArraySumPrefixSumMethod(int arr[], int size) {
    int maxVal = -1 * 10000;
    int prefixSumArr[100] = {0};

    for (int i = 0 ; i < size; i++) {
        int curElement = arr[i];
        int lastIdx = i - 1;
        if (i != 0) {
             prefixSumArr[i] = curElement + prefixSumArr[i - 1];
        } else {
            prefixSumArr[i] = curElement;
        }
    } 

    for(int i = 0; i < size ; i ++) {
        for(int j = i ; j < size ; j ++) {
            int sum = i > 0 ? prefixSumArr[j] - prefixSumArr[i - 1] : prefixSumArr[j];
            maxVal = max(sum, maxVal);
        }
    }

    return maxVal;
}

int main() {
    int arr[9] = {-2 , 3, 4, -1, 5, -12, 6, 1, 3};
    int size = 9;

    printSubarray(arr, size); 
    cout << "Number of subarrays = " << numberOfSubArrays(size) << endl;
    cout << "Largest subarray sum BRUTE FORCE = "<< largestSubarraySumBruteForce(arr, size) << endl; // Time complexity is O(n ^ 3)
    cout << "Largest subarray sum using prefix sum array = " << largestSubArraySumPrefixSumMethod(arr, size) << endl; 
    return 0;
}