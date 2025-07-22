#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0;
        int curCount = 0;

        int sz = nums.size();

        for (int i = 0; i < sz; i++)
        {
            if (nums[i] == 0)
            {
                if (curCount > maxCount)        maxCount = curCount;
                curCount = 0;
            }

            else
            {
                curCount++;
            }
        }

        if (curCount > maxCount)        maxCount = curCount;

        return maxCount;
    }
};