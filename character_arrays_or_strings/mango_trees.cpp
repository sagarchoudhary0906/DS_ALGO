#include <iostream>
using namespace std;

/**
 * Rahul's Father has left a farm orgaised as an NxN grid. Each square in the grid either has or does not have a mango tree.
 * He has to divide the farm with his three sisters as follows:
 * He will draw one horizontal line and one vertical line to divider the field into four rectangles.alignasHis friends will chose three of the four rectangles.
 * His friends will choose three of the four samples fieldsand he gets the last one.
 * INPUT = [
 *  '.', '#', '#', '.', '.', '.',
 *  '#', '.', '.', '#', '#', '.',
 *  '.', '#', '.', '.', '.', '.',
 *  '.', '#', '#', '.', '.', '#',
 *  '#', '.', '.', '#', '#', '.',
 *  '.', '#', '.', '.', '.', '.',
 * ]
 *
 * OUTPUT = 3
 * Here 3 will be the maximum minimum he can get
 *
 * Here the idea is to maximise it's minimum.
 */

int mangoTressBruteForce(char arr[][6], int rows, int col)
{
    int ans = INT_MIN;
    // Traversing each Row
    for (int i = 0; i < rows; i++)
    {
        // Traversing Each Column
        // Making Cut
        for (int j = 0; j < col; j++)
        {
            // Cut coordinates.
            int x = i, y = j;
            // Own Quad
            int rr = 0, cc = 0;
            int quadMinSum = INT_MAX;
            int sum = 0;
            cout << "X and Y  = " << x << " " << y << endl;
            for (int xx = rr; xx <= x; xx++)
            {
                for (int yy = cc; yy <= y; yy++)
                {
                    cout << char(arr[xx][yy]) << " , ";
                    if (arr[xx][yy] == '#')
                    {
                        sum = sum + 1;
                    }
                }
                cout << endl;
            }
            quadMinSum = min(quadMinSum, sum);
            cout << "Sum is = " << sum << " And Minum sum so far is = " << quadMinSum << " \n and answer so far is = " << ans << endl;

            cout << "--------------" << endl;

            cout << "Now Taking Sum For Second Quad" << endl;
            // First Quad
            sum = 0;
            rr = x + 1;
            cc = 0;
            cout << "X and Y  = " << rr << " " << cc << endl;

            for (int xx = rr; xx < rows; xx++)
            {
                for (int yy = cc; yy <= y; yy++)
                {
                    cout << char(arr[xx][yy]) << ", ";
                    if (arr[xx][yy] == '#')
                    {
                        sum = sum + 1;
                    }
                }
                cout << endl;
            }

            quadMinSum = min(quadMinSum, sum);
            cout << "Sum is = " << sum << " And Minum sum so far is = " << quadMinSum << " \n and answer so far is = " << ans << endl;

            cout << "--------------" << endl;

            cout << "Now Taking Sum For Thrid Quad" << endl;

            sum = 0;
            rr = 0;
            cc = y + 1;
            cout << "X and Y  = " << rr << " " << cc << endl;
            for (int xx = rr; xx <= x; xx++)
            {
                for (int yy = cc; yy < col; yy++)
                {
                    cout << char(arr[xx][yy]) << ", ";
                    if (arr[xx][yy] == '#')
                    {
                        sum = sum + 1;
                    }
                }
                cout << endl;
            }

            quadMinSum = min(quadMinSum, sum);
            cout << "--------------" << endl;

            cout << "Now Taking Sum For Fourth Quad" << endl;
            sum = 0;
            rr = x + 1;
            cc = y + 1;
            cout << "X and Y  = " << rr << " " << cc << endl;

            for (int xx = rr; xx < rows; xx++)
            {
                for (int yy = cc; yy < col; yy++)
                {
                    cout << char(arr[xx][yy]) << ", ";
                    if (arr[xx][yy] == '#')
                    {
                        sum = sum + 1;
                    }
                }
                cout << endl;
            }
            quadMinSum = min(quadMinSum, sum);
            ans = max(ans, quadMinSum);
            cout << endl;
        }
    }
    cout << endl;
    return ans;
}

int mangoTreeOptimised(char arr[][6], int rows, int col)
{
    int ans = INT_MIN;
    int prefixSumMatx[6][6] = {{0}}; // Correctly declare and initialize

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            int aboveCellX = i - 1;
            int aboveCellY = j;

            int leftCellX = i;
            int leftCellY = j - 1;

            int leftCellSum = 0;
            int aboveCellSum = 0;
            int diagnoalCellSum = 0;

            if (aboveCellX < 0)
            {
                aboveCellSum = 0;
            }
            else
            {
                aboveCellSum = prefixSumMatx[aboveCellX][aboveCellY];
            }

            if (leftCellY < 0)
            {
                leftCellSum = 0;
            }
            else
            {
                leftCellSum = prefixSumMatx[leftCellX][leftCellY];
            }

            if (leftCellY < 0 || aboveCellX < 0)
            {
                diagnoalCellSum = 0;
            }
            else
            {
                diagnoalCellSum = prefixSumMatx[aboveCellX][leftCellY];
            }

            prefixSumMatx[i][j] = aboveCellSum + leftCellSum - diagnoalCellSum;
            if (arr[i][j] == '#')
            {
                prefixSumMatx[i][j] += 1;
            }
            cout << prefixSumMatx[i][j] << ", ";
        }
        cout << endl;
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            int minSum = INT_MAX;
            cout << "Current prefix sum aray value is = " << prefixSumMatx[i][j] << " and cuts are " << i << ", " << j << endl;
            int firstQuadSum = prefixSumMatx[i][j];
            int secondQuadSum = prefixSumMatx[i][col - 1] - firstQuadSum;
            int thridQuadSum = prefixSumMatx[rows - 1][j] - firstQuadSum;
            int fourthQuadSum = prefixSumMatx[rows - 1][col - 1] - (firstQuadSum) - secondQuadSum - thridQuadSum;
            cout << "All Quad Sum = " << firstQuadSum << " " << secondQuadSum << " " << thridQuadSum << " " << fourthQuadSum << endl;
            minSum = min(minSum, firstQuadSum);
            cout << "min Sum " <<minSum << endl;
            minSum = min(minSum, secondQuadSum);
            cout << "min Sum " <<minSum << endl;
            minSum = min(minSum, thridQuadSum);
            cout << "min Sum " <<minSum << endl;
            minSum = min(minSum, fourthQuadSum);
            cout << "min Sum " <<minSum << endl;
            ans = max(ans, minSum);
            cout << "min Sum and answer = " << ans << endl;
        }
    }
    return ans;
}

int main()
{
    char arr[][6] = {
        {'.', '#', '#', '.', '.', '.'},
        {'#', '.', '.', '#', '#', '.'},
        {'.', '#', '.', '.', '.', '.'},
        {'.', '#', '#', '.', '.', '#'},
        {'#', '.', '.', '#', '#', '.'},
        {'.', '#', '.', '.', '.', '.'}};

    // cout << mangoTressBruteForce(arr, 6, 6) << endl; // The time complexity of brute force will be O(n^4)
    cout << endl;
    cout << mangoTreeOptimised(arr, 6, 6) << endl; // Time complexity of this solution is O(n ^ 2)
    return 0;
}