#include <iostream>
using namespace std;

void printArray(vector<vector<int>> &board, int row, int col)
{
    for (int i = 0; i <= row; i++)
    {
        for (int j = 0; j <= col; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool canPlaceQueen(vector<vector<int>> &board, int i, int j, int re, int ce)
{
    // Checking In Row
    int colIdx = 0;
    while (colIdx <= ce)
    {
        if (board[i][colIdx] == 1)
        {
            return false;
        }
        colIdx++;
    }

    // Checking Col
    int rowIdx = 0;
    while (rowIdx <= re)
    {
        if (board[rowIdx][j] == 1)
        {
            return false;
        }
        rowIdx++;
    }

    int rowStart = i;
    int colStart = j;

    while (rowStart >= 0 && colStart <= ce)
    {
        if (board[rowStart][colStart] == 1)
        {
            return false;
        }
        rowStart--;
        colStart++;
    }

    rowStart = i;
    colStart = j;
    while (rowStart <= re && colStart >= 0)
    {
        if (board[rowStart][colStart] == 1)
        {
            return false;
        }
        rowStart++;
        colStart--;
    }

    rowStart = i;
    colStart = j;
    while (rowStart >= 0 && colStart >= 0)
    {
        if (board[rowStart][colStart] == 1)
        {
            return false;
        }
        rowStart--;
        colStart--;
    }

    rowStart = i;
    colStart = j;

    while (rowStart <= re && colStart <= ce)
    {
        if (board[rowStart][colStart] == 1)
        {
            return false;
        }
        rowStart++;
        colStart++;
    }
    // Returning True
    return true;
}

bool nQueenSolve(vector<vector<int>> &board, int rs, int re, int cs, int ce)
{
    cout << "nQueenSolve called " << rs << " " << re << " " << cs << " " << ce << endl;
    if (rs > re)
    {
        printArray(board, 3, 3);
        
        cout << endl;
        
        return true;
    }
    bool solExist = false;
    for (int col = cs; col <= ce; col++)
    {
        bool canPlace = canPlaceQueen(board, rs, col, re, ce);
        cout << "Can Place at = " << rs << " " << col << " " << re << " " << ce << " canPlace = " << canPlace << endl;
        if (canPlace)
        {
            board[rs][col] = 1;
            solExist = nQueenSolve(board, rs + 1, re, cs, ce);

            if (!solExist)
            {
                board[rs][col] = 0;
            }
            if (solExist)
            {
                return true;
            }
        }
    }
    return solExist;
}



int main()
{
    vector<vector<int>> board = {{0}, {0}, {0}, {0}};
    int n = 4;
    // printArray(board, 3, 3);
    // cout << endl;
    cout << nQueenSolve(board, 0, 3, 0, 3) << endl;
    // printArray(board, 3, 3);
    return 0;
}