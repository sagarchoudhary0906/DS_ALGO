#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter Pascal Traingle rows count = ";
    cin >> n;
    cout << endl;

    int mat[6][6] = {{0}};
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (count > i)
            {
                continue;
            }

            if (j == 0)
            {
                mat[i][j] = 1;
            }
            else if (i == 0)
            {
                continue;
            }
            else
            {
                if (i - 1 < 0 || j - 1 < 0)
                {
                    mat[i][j] = 0;
                }
                else
                {
                    mat[i][j] = mat[i - 1][j - 1] + mat[i - 1][j];
                }
            }
            cout << mat[i][j] << ", ";
            count++;
        }
        cout << endl;
    }
    return 0;
}