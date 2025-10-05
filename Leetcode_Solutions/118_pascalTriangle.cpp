#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate3ms(int numRows) {                  // same intuition but, slightly more runtime due to new vector creation
        vector<vector<int>> ans = {{1}, {1,1}};

        if (numRows == 1)       return {{1}};
        if (numRows == 2)       return ans;

        for (int i = 2; i < numRows; i++)
        {
            vector<int> curRow;
            vector<int> prevRow = ans[i - 1];

            curRow.emplace_back(1);
            for (int j = 1; j < i; j++)
            {                
                curRow.emplace_back(prevRow[j] + prevRow[j - 1]);                
            }
            curRow.emplace_back(1);         

            ans.push_back(curRow);
        }        

        return ans;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for (int i = 0; i < numRows; i++)
        {
            ans.push_back(vector<int> (i + 1, 1));                  // pushes a vector of size = i+1, all elements = 1
        }      

        for (int i = 2; i < numRows; i++)                           // only change 3rd row onwards, and middle elements
        {            
            for (int j = 1; j < i; j++)
            {                
                ans[i][j] = ans[i - 1][j] + ans[i - 1][j - 1];               
            }   

        }        

        return ans;
    }
};