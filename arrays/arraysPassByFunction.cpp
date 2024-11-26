#include <iostream>
using namespace std;


/**
 * - If we want to prove the concept that arrays are passed by the refernce then we can take this example which is described below that is .
 * - In print array function arrays is passed by refernce hence if we are changing the value of anay index of this array it's valuw will also get chnged if we print array later in main function.
 * - Why this ? as array is passed by refrence in printArray function this proves that both array in maind and printArray funvction shares the same memory.
 * - Hence the concept of arrays passed by refernce is proved  
 * */


void printArray(int *arr, int size) // Address of array which is a pointer varaible hence the size of array is 8 bytes as pointer is of 8 bytes 
// You can also pass array as (int arr[]) both this and (int *arr) are same and valid index 
{
    cout << "In Print Function and size of arrays is = " << sizeof(arr) << endl; // Output is 8 bytes
    int n = sizeof(arr) / sizeof(int); // Here n = 2 because of pointer size is 8 and size of int is 4 hence 8 / 4 = 2

    for(int i = 0 ; i < size ; i ++) {
        cout << arr[i] << endl;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6}; // Size will be 6 * 4 = 24 bytes

    int size = sizeof(arr) / sizeof(int);

    cout << "In Main = " << sizeof(arr) << endl; //Output is 24 

     for(int i = 0 ; i < size ; i ++) {
        cout << arr[i] << endl;
    }

    cout << endl;

    printArray(arr, size);
    return 0;
}