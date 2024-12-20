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

void nQueenSolve(vector<vector<int>> &board, int rs, int re, int cs, int ce)
{
    if (rs > re)
    {
        printArray(board, 3, 3);
        
        cout << endl;
        return;
    }
    bool solExist = false;
    for (int col = cs; col <= ce; col++)
    {
        bool canPlace = canPlaceQueen(board, rs, col, re, ce);
        if (canPlace)
        {
            board[rs][col] = 1;
            nQueenSolve(board, rs + 1, re, cs, ce);
            board[rs][col] = 0;
        }
    }
}



int main()
{
    vector<vector<int>> board = {{0}, {0}, {0}, {0}};
    int n = 4;
    // printArray(board, 3, 3);
    // cout << endl;
    nQueenSolve(board, 0, 3, 0, 3);
    // printArray(board, 3, 3);
    return 0;
}