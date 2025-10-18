#include <bits/stdc++.h>
using namespace std;

int reversePairsBrute(vector<int>& nums) {
    int len = nums.size() - 1;

    int count = 0;

    for (int i = len; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if ((long long)nums[j] > (2 *(long long) nums[i]))
            {
                count++;
            }
        }
    }
    return count;
}

