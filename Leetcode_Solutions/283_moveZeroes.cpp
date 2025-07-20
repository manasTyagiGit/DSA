#include <bits/stdc++.h>
using namespace std;


//Below is my solution of deleting, counting, and appending
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        int zeroCount = 0;
        int i = 0;

        for (auto it = nums.begin(); it != nums.end();){
            if (*it == 0)
            {
                zeroCount++;
                it = nums.erase(it);
            }
            else
            {
                ++it;
            }
        }

        int newFinalIdx = size - zeroCount;

        nums.insert (nums.begin() + newFinalIdx, zeroCount, 0);
    }
};

// This is what everyone teaches as two pointer approach

void moveZeroes(vector<int>& nums) {
        int i = 0;
        int j = 0;

        while (j < nums.size())
        {
            if (nums[j] != 0)
            {
                swap (nums[j], nums[i]);
                i += 1;
            }
            j += 1;
        }
    }