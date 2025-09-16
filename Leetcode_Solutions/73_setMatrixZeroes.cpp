#include <bits/stdc++.h>
using namespace std;



void printMatrix(int m, int n, vector<vector<int>>& mat)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << "\t";
        }

        cout << endl;
    }
}

void setRowsNeg (int n, int i, vector<vector<int>>& mat)
{
    for (int j = 0; j < n; j++)
    {
        if (mat[i][j] != 0)
        {
            mat[i][j] = -1;
        }
    }
}

void setColsNeg (int m, int j, vector<vector<int>>& mat)
{
    for (int i = 0; i < m; i++)
    {
        if (mat[i][j] != 0)
        {
            mat[i][j] = -1;
        }
    }
}

void setMatrixZeroesBrute (int m, int n, vector<vector<int>>& mat)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 0)
            {
                setRowsNeg(n, i, mat);
                setColsNeg(m, j, mat);
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == -1)
            {
                mat[i][j] = 0;
            }
        }
    }
}

void setMatrixZeroesBetter (int m, int n, vector <vector <int>>& mat)
{
    vector <int> row (m, 0);
    vector <int> col (n, 0);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;    
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (row[i] == 1 || col[j] == 1)
            {
                mat[i][j] = 0;
            }
        }
    }
}

void setMatrixZeroesBest (int m, int n, vector<vector<int>>& mat)
{
    int col0 = 1;
    //  int m = mat.size();
    //  int n = mat[0].size();


    //  vector <int> row (m, 0);        -> this can be mat[0...n][0]
    //  vector <int> col (n, 0);        -> this can be mat[0][0...m]

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 0)
            {
                mat[i][0] = 0;

                if (j != 0)
                {
                    mat[0][j] = 0;
                }
                else
                {
                    col0 = 0;
                }
            }
        }
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (mat[0][j] == 0 || mat[i][0] == 0)
            {
                mat[i][j] = 0;
            }
        }
    }

    if (mat[0][0] == 0)
    {
        for (int j = 0; j < n; j++)
        {
            mat[0][j] = 0;
        }
    }

    if (col0 == 0)
    {
        for (int i = 0; i < m; i++)
        {
            mat[i][0] = 0;
        }
    }
}


int main (void)
{
    int x, y;
    cin >> x >> y;

    vector<vector<int>> v(x, vector<int>(y));

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            cin >> v[i][j];
        }
    }

    cout << "Input matrix :: \n";
    printMatrix (x,y, v);

    cout << "\n After setting Zeroes\n";
    //  setMatrixZeroesBrute (x, y, v);

    //  setMatrixZeroesBetter (x, y, v);
    setMatrixZeroesBest (x, y, v);

    printMatrix (x,y, v);
}