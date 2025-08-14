#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        // I want to do this via two pointer approach first,
        // and if I am unable to do, I will see the solution,
        // and Raj's video. 12:52 am August 15.

        // The below solution works, but looks like a brute
        // force solution, even though, it is an O(N) T.C.
        vector<int> ret;
        int sz = nums.size();
        int pos_idx = 0;
        int neg_idx = 0;

        vector <int> pos;
        vector <int> neg;

        for (int i = 0; i < sz; i++)
        {
            if (nums[i] < 0)        neg.emplace_back (nums[i]);
            else                    pos.emplace_back (nums[i]);
        }

        sz = sz / 2;

        for (int i = 0; i < sz; i++)
        {
            ret.emplace_back (pos[i]);
            ret.emplace_back (neg[i]);
        }

        return ret;
    }
};