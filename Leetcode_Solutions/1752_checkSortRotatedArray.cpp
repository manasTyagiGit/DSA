#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int violations = 0;
        int s = size (nums);
        for (int i = 1; i < s; i++)
        {
            if (nums[i - 1] > nums[i])      violations++;
        }

        if (nums[0] < nums[s - 1])          violations++;

        return (violations > 1) ? (false) : (true);
    }
};