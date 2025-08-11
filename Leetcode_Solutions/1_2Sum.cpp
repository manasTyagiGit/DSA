// Optimized One pass unordered_map for history
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> mp;

        int size = nums.size();

        vector <int> idx;
        for (int i = 0; i < size; i++)
        {
            int diff = target - nums[i];
            auto it = mp.find(diff);

            // not found
            if (it == mp.end())
            {
                mp.insert({nums[i], i});
            }
            // found
            else
            {
                idx.push_back (i);
                idx.push_back (mp[diff]);
                break;
            }

        }

        return idx;
    }
};