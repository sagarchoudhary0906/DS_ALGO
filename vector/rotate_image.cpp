#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<vector<int>> arr)
{
    int n = arr[0].size();

    for (int layer = 0; layer < n / 2; layer++)
    {
        int first = layer;
        int last = n - layer - 1;
        for (int i = first; i < last; i++)
        {
            int offset = i - first;
            int temp1 = arr[first][i];
            int temp2 = arr[first][last - offset];
            int temp3 = arr[last - offset][last];
            int temp4 = arr[last][first];

            cout << "Printing temps = " << temp1 << " " << temp2 << " " << temp3 << " " << temp4 << endl;
            arr[first][i] = temp4;
            arr[first][last] = temp1;
            arr[last][last] = temp2;
            arr[last][first] = temp3;
        }
    }
    for (vector<int> row : arr)
    {
        for (int ele : row)
        {
            cout << ele << ", ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << "Enter angle by which you want to roatet the image = ";
    int angle;
    cin >> angle;
    rotate(arr);

    // for (vector<int> row : arr)
    // {
    //     for (int ele : row)
    //     {
    //         cout << ele << ", ";
    //     }
    //     cout << endl;
    // }
    return 0;
}