#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> rearrangeArray_uneven(vector<int>& nums) {

        // The below solution works, but looks like a brute
        // force solution, even though, it is an O(N) T.C.
        // But it will work even if there are un-equal number
        // of positive numbers, and negative numbers

     
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

        int neg_sz = neg.size();
        int pos_sz = pos.size();

        if (neg_sz > pos_sz)                        // when no. of negs > no. of pos
        {
            for (int i = 0; i < pos_sz; i++)
            {
                ret.push_back (pos[i]);
                ret.push_back (neg[i]);
            }

            for (int i = pos_sz; i < neg_sz; i++)
            {
                ret.push_back(neg[i]);
            }
        }

        else
        {
            for (int i = 0; i < neg_sz; i++)        // when no. of pos >= no. of negs
            {
                ret.push_back (pos[i]);
                ret.push_back (neg[i]);
            }

            for (int i = neg_sz; i < pos_sz; i++)
            {
                ret.push_back(pos[i]);
            }
        }

        return ret;
    }


    // We are using the assumption contraint that the array is
    // containing exactly same number of negs, and pos

    vector<int> rearrangeArray_even(vector<int>& nums) {
        int sz = nums.size();

        vector<int> ret(sz);
        int pos_idx = 0;
        int neg_idx = 1;

        for (int i = 0; i < sz; i++)
        {
            if (nums[i] > 0)
            {
                ret[pos_idx] = nums[i];
                pos_idx += 2;
            }

            else
            {
                ret[neg_idx] = nums[i];
                neg_idx += 2;
            }
        }

        return ret;
    }

};