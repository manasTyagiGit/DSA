#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Brute Solution Below, runs in O(n + n), S.C = O(2n)
    int singleNumber_brute(vector<int>& nums) {
        int sz = nums.size();

        unordered_map <int, int> freq;        

        for (int i = 0; i < sz; i++)
        {
            freq[nums[i]]++;
        }

        for (int i = 0; i < sz; i++)
        {
            if (freq[nums[i]] == 1)   return nums[i];               // return the number, as it is not sorted
        }

        return nums[0];             // won't happen, so can also return -1
    }

    // Becasuse x ^ x = 0, hence the remaining with XOR all in chain will be the remaining number
    int singleNumber(vector<int>& nums) {
        int sz = nums.size();

        int xor_res = 0;

        for (int i = 0; i < sz; i++)
        {
            xor_res = xor_res ^ nums[i];
        }

        return xor_res;
        
    }
};