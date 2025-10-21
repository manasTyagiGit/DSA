#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int>& nums) {
    int min = INT_MAX;

    int high = nums.size() - 1;
    int low = 0;

    if (nums[low] < nums[high])       return nums[low];        // rotated by k.len(nums[]) or 0

    while (low < high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] >= nums[0])
            low = mid + 1;
        else
            high = mid;
    }

    return nums[low];
    
}