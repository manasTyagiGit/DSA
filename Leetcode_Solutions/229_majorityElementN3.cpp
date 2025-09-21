#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {        // Hashing solution in comments, uses extra ~ O(N) space, but O(N) runtime
        /*unordered_map <int, int> freq;
        int sz = nums.size();

        vector<int> ans;

        for (int i = 0; i < sz; i++)
        {
            freq[nums[i]]++;           
        }

        for (auto it: freq)
        {
            if (it.second > floor (sz/3))
            {
                ans.push_back(it.first);
            }
        }

        return ans;*/


        // The below solution takes into account the fact that at max,
        // there can be 2 elements with frequencies > floor (n/3) in an array,
        // i.e, total frequency > 2n/3, so just use 2 pointers in Bayer counting


        vector <int> ans;
        int sz = nums.size();

        int count1 = 0, count2 = 0;
        int candt1 = INT_MIN, candt2 = INT_MIN;

        for (int i = 0; i < sz; i++)
        {
            if (nums[i] == candt1)
            {
                count1++;
            }

            else if(nums[i] == candt2)
            {
                count2++;
            }

            else if (count1 == 0)
            {
                candt1 = nums[i];
                count1++;
            }

            else if (count2 == 0)
            {
                candt2 = nums[i];
                count2++;
            }

            else
            {
                count1--;
                count2--;
            }
        }

        count1 = 0, count2 = 0; 

        for (int i = 0; i < sz; i++)
        {
            if (nums[i] == candt1)          count1++;
            else if (nums[i] == candt2)     count2++;
        }

        if (count1 > floor (sz / 3))         ans.emplace_back (candt1);
        if (count2 > floor (sz / 3))         ans.emplace_back (candt2);

        return ans;

    }