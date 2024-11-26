#include <iostream>
using namespace std;

int main()
{
    // Creating an array
    int a[100]; // Allocate memory 400 bytes as one intger is 4 bytes. This array will have garbage data as array is not initalised.

    int arr1[100] = {0}; // All elements will be zero

    int arr2[100] = {1, 2, 3}; // First three elements will be 1, 2, 3 and rest will be 0

    int arr3[] = {1, 2, 3}; // This will be an array of size 3 [1, 2, 3];

    string fruites[4] = {"apple", "mango", "guava", "banana"};

    int marks[10]; // Indexes are like 0 , 1 , 2, 3, 4, ____________________________, 9
    int n;
    cout << "Enter the number of students = ";
    cin >> n;

    //Taking input in array
    for (int i = 0 ; i < n ; i ++) {
        cout << "Enter marks of student number " << (i + 1) << " = ";
        cin >> marks[i];
    }

    //Output of array
    for (int i = 0 ; i < n ; i ++) {
        cout << marks[i] <<", ";
    }


    
    
    return 0;
}