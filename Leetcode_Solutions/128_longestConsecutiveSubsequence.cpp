#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive_Brute(vector<int>& nums) {
        // Easy brute is to sort the array, and then run a one pass
        // to check the longest running sequence (it will be a subarray),
        // T.C. = O(n logn), S.C. = O(1)

        int sz = nums.size();
        int max_len = 0;
        int cur_len = 1;

        if (sz == 1 || sz == 0)        return sz;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < sz - 1; i++)
        {
            long long int diff = nums[i + 1] - nums[i];    
            if (diff == 1)
            {
                cur_len++;
            }
            else if (diff > 1)
            {
                cur_len = 1;
            }
            if (cur_len > max_len)
            {
                max_len = cur_len;
            }
        }

        return max_len;

    }

    int longestConsecutive_Set(vector<int>& nums) {
        int sz = nums.size();

        if (sz <= 1)                return sz;

        unordered_set <int> st;
        int max_len = 1;

        for (auto x : nums)
        {
            st.insert (x);
        }

        for (auto y : st)
        {
            if (st.find(y - 1) == st.end())
            {
                int cur_len = 1;
                int x = y;

                while (st.find(x + 1) != st.end())
                {
                    x++;
                    cur_len++;
                }
                
                max_len = max(max_len, cur_len);

            }
        }

        return max_len;

    }
};