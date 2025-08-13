#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;

        int cur_sum = 0;
        int sz = nums.size();

        for (int i = 0; i < sz; i++)
        {
            cur_sum = cur_sum + nums[i];
            cur_sum = max(nums[i], cur_sum);
            maxSum  = max(maxSum, cur_sum);
        }
        return maxSum;  
    }    
};