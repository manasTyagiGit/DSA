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


vector<vector<int>> rotateImageBrute (int m, int n, vector<vector<int>>& mat)
{
    vector<vector<int>> newMat(m, vector<int>(m));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            newMat[j][m - i - 1] = mat[i][j];
        }
    }

    return newMat;
}

void rotateImageOptimal (int n, vector<vector<int>>& mat)
{
    //  Transpose first
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(mat[i][j], mat[j][i]);
        }
    }

    //  Reverse each row
    for (int i = 0; i < n; i++)
    {
        reverse (mat[i].begin(), mat[i].end());
    }

}

int main (void)
{
    int x;
    cin >> x;
    int y = x;

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

    cout << "\n After rotating 90 deg\n";

    //  vector<vector<int>> newMat = rotateImageBrute (x, y, v);

    rotateImageOptimal (x, v);

    printMatrix (x, y, v);
}