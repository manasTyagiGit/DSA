
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeBetter(vector<vector<int>>& intervals) {           // O(N logn + N2)
    vector <vector <int>> ans;

    int len = intervals.size();

    sort (intervals.begin(), intervals.end());

    for (int i = 0; i < len; i++)
    {
        int curBegin = intervals[i][0];
        int curEnd = intervals[i][1];

        if (!ans.empty() && ans.back()[1] >= curEnd)            // in case we already cover it
        {
            continue;
        }

        for (int j = i + 1; j < len; j++){                      // for compare with current iter to next
            if (intervals[j][0] <= curEnd)
            {
                if(curEnd < intervals[j][1])
                    curEnd = intervals[j][1];
            }
            else        break;
        }   

        ans.push_back({curBegin, curEnd});
    }

    return ans;
}

vector<vector<int>> mergeBest(vector<vector<int>>& intervals) {         // O(nlogn + n), sort + linear traverse

    vector<vector<int>> ans;
    int len = intervals.size();

    sort (intervals.begin(), intervals.end());                  // important stuff

    ans.push_back (intervals[0]);

    for (int i = 1; i < len; i++)
    {
        if (intervals[i][0] <= ans.back()[1])                   // case of overlapping intervals
        {
            ans.back()[1] = max (ans.back()[1], intervals[i][1]);
        }

        else                                                    // case where they do nto overlap
        {
            ans.push_back ({intervals[i][0], intervals[i][1]});
        }
    }

    return ans;
    
}
