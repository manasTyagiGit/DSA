#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

    /*

    The Below is brute force, and it gives TLE on 38th out of 39th test case


    void rotate(vector<int>& nums, int k) {
        int size = nums.size();

        k = k % size;

        if (k == 0)     return;

        for (int i = 0; i < k; i++)
        {
            int extracted = nums[size - 1];
            nums.insert (nums.begin() + 0, extracted);
            nums.erase  (nums.begin() + size);
        }
    }
    */

    void rotate(vector<int>& nums, int k) 
    {
        int size = nums.size();

        k = k % size;

        if (k == 0)     return;

        vector <int> extracted;

        extracted.insert (extracted.begin() + 0, nums.begin() + size - k, nums.end());
        nums.erase (nums.begin() + size - k, nums.end());

        nums.insert (nums.begin() + 0, extracted.begin(), extracted.end());
    }
};