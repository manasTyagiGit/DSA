#include <bits/stdc++.h>
using namespace std;

bool search(vector<int>& nums, int target) {
    int high = nums.size() - 1;
    int low = 0;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target)        return true;

        if ((nums[low] == nums[mid]) && (nums[mid] == nums[high]))
        {
            low++;
            high--;
        }

        else if (nums[low] <= nums[mid])         // branch 1
        {   
            if (target >= nums[low] && target < nums[mid])
                high = mid - 1;
            else
                low = mid + 1;                
        }

        else                                // branch 2
        {
            if (target > nums[mid] && target <= nums[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }

    return false;
}