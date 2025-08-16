#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //next_permutation (nums.begin(), nums.end());

        /*
            Idea is to find the breakpoint from the right of
            the array, i.e., the end of the array, and then 
            swap those, and finally sort between the breakpoint,
            and final.
        */

        int sz = nums.size();
        int breakpoint = -1;

        for (int i = sz - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                breakpoint = i;
                break;
            }
        }

        if (breakpoint == -1)
        {
            reverse (nums.begin(), nums.end());
            return;
        }
        
        for (int i = sz - 1; i > breakpoint; i--)
        {
            if (nums[breakpoint] < nums[i])
            {
                swap (nums[i], nums[breakpoint]);
                break;
            }
        }

        reverse (nums.begin() + breakpoint + 1, nums.end()) ;      

    }
};