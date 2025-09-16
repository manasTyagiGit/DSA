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

void printArray (vector<int> arr)
{
    for (auto i : arr)
    {
        cout << i << " ";
    }

    cout << endl;
}

vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector <int> ans;

        int rows = matrix.size();
        int cols = matrix[0].size();

        int top = 0, left = 0;
        int bottom = rows - 1, right = cols - 1;

        while (top <= bottom && left <= right)
        {
            for (int i = left; i <= right; i++)
            {
                ans.emplace_back (matrix[top][i]);
            }
            top++;

            for (int i = top; i <= bottom; i++)
            {
                ans.emplace_back (matrix[i][right]);
            }
            right--;

            if (top <= bottom)
            {
                for (int i = right; i >= left; i--)
                {
                    ans.emplace_back (matrix[bottom][i]);
                }
                bottom--;
            }

            if (left <= right)
            {
                for (int i = bottom; i >= top; i--)
                {
                    ans.emplace_back (matrix[i][left]);
                }
                left++;
            }
        }

        return ans;
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

    vector <int> ans = spiralOrder (v);

    cout <<"\nSpiral Order printing is :: \n";

    printArray (ans);

}