#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // This is my Thought, it is not in-place obviously, and uses O(n) extra space,
    // but that can be altered to act on the same array if we do a nums.clear() first
    void sortColorsBrute(vector<int>& nums) {
        int noOfColors = 3;
        vector <int> freq (noOfColors, 0);
        int sz = nums.size();
        vector <int> ret;

        if (sz == 1)        return;

        for (int i = 0; i < sz; i++)
        {
            freq[nums[i]]++;
        }        
        
        /**
            ret.insert(ret.begin(), freq[0], 0);
            ret.insert(ret.begin() + freq[0], freq[1], 1);
            ret.insert(ret.begin() + freq[0] + freq[1], freq[2], 2);
        */        

        int idx = 0;
        for (int i = 0; i < noOfColors; i++)
        {
            ret.insert (ret.begin() + idx, freq[i], i);
            idx += freq[i];
        }        

        nums = ret;
        
    }

    void sortColors (vector <int>& nums)
    {
        int sz = nums.size();
        int low = 0, mid = 0, high = sz - 1;

        while (mid <= high)                 // as unsorted is only between [mid, high] indices
        {
            if (nums[mid] == 0)
            {
                swap (nums[low], nums[mid]);
                low++;
                mid++;
            }

            else if (nums[mid] == 1)
            {
                mid++;
            }

            else 
            {
                swap(nums[high], nums[mid]);
                high--;
            }
        }
    }
};