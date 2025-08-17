#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    // The obvious brute is to find out all the sub-arrays,
    // their sum, and then add it up to the key = 'k'

    // But we can use methods from earlier which use a prefix sum
    
    unordered_map <int, int> mp;
    mp[0] = 1;                      // for handling the 0 prefix step
    int sz = nums.size();
    int count = 0, rollingSum = 0;

    for (int i = 0; i < sz; i++)
    {
        rollingSum += nums[i];
        int prefix = rollingSum - k;

        count += mp[prefix];

        mp[rollingSum] += 1;
    }

    return count;
    }
};