#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void swap (int* a, int* b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();

        int cur = 0;

        for (int i = 1; i < size; i++)
        {
            if (nums[i] != nums[cur])
            {
                cur += 1;
                swap (&nums[i], &nums[cur]);
            }
        }
        return cur + 1;
    }
};