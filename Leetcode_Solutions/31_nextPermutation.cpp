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

            We need to match the longest prefix possible, hence
            taking the breakpoint from the right, and not left

            Once we swap, just sort the portion after the breakpoint
            as that is the smallest string lexicographically.

            If no breakpoint, it is the largest string in the lexicon,
            hence return a sorted (or cleverly, the reverse) of the string
        */

        int sz = nums.size();
        int breakpoint = -1;

        for (int i = sz - 2; i >= 0; i--)               // first breakpoint from the right
        {
            if (nums[i] < nums[i + 1])
            {
                breakpoint = i;
                break;
            }
        }

        if (breakpoint == -1)                           // in case the largest string in lexicon
        {
            reverse (nums.begin(), nums.end());
            return;
        }
        
        for (int i = sz - 1; i > breakpoint; i--)       // find the first larger element than the breakpoint from right, and swap
        {
            if (nums[breakpoint] < nums[i])
            {
                swap (nums[i], nums[breakpoint]);
                break;
            }
        }

        reverse (nums.begin() + breakpoint + 1, nums.end()) ;       // clever sort way, can also use sort())

    }
};