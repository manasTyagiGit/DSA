#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors_extraSpace(vector<int>& nums) {
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
};