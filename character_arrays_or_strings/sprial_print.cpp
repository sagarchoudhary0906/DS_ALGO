#include <iostream>
using namespace std;

void printSprialArray(int arr[][5], int rows, int columns)
{
    int rightThreshold = rows - 1;
    int bottomThreshold = columns - 1;
    int leftThreshold = 0;
    int upperThreshold = 0;

    int n = rows * columns;
    int counter = 0;

    int i = 0;
    int j = 0;
    while (counter <= n)
    {
        // Printing Right
        while (j <= rightThreshold && counter <= n)
        {
            cout << arr[i][j] << " ";
            j++;
            counter++;
        }
        if (counter >= n)
        {
            break;
        }
        j--;
        i++;
        upperThreshold++;
        // Printing Bottom
        while (i <= bottomThreshold && counter <= n)
        {
            cout << arr[i][j] << " ";
            counter++;
            i++;
        }
        if (counter >= n)
        {
            break;
        }
        i--;
        rightThreshold--;
        j--;
        // Printing Left
        while (j >= leftThreshold && counter <= n)
        {
            cout << arr[i][j] << " ";
            j--;
            counter++;
        }
        if (counter >= n)
        {
            break;
        }
        j++;
        bottomThreshold--;
        i--;
        //Printing Up
        while(i >= upperThreshold) {
            cout << arr[i][j] << " ";
            counter++;
            i--;
        }
        if (counter >= n)
        {
            break;
        }
        i++;
        leftThreshold++;
        j++;
    }
}

int main()
{
    int arr[][5] = {{1, 2, 3, 4, 17},
                    {5, 6, 7, 8, 18},
                    {9, 10, 11, 12, 19},
                    {13, 14, 15, 16, 20},
                    {21, 22, 23, 24, 25}};
    int rows = 5;
    int columns = 5;
    printSprialArray(arr, rows, columns);
    return 0;
}