#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // The obvious burte force is to go through
        // every sub-array in O(N^2) time, but here
        // we can use Kadane's algorithm

        /*
            In the Kadane's algo, we traverse the array
            from 0 to n, and make a choice of whether to
            add the current element to the rolling sum,
            or set it to zero, and start the sum again from
            the current element. Former when we know rolling
            sum is still greater than the current element + rolling sum, 
            and the later when the current element is bigger than
            adding it to the rolling sum.
        */  

        // Let us also try to print the indices for this sub-array

        int left = 0, right = 0, temp = 0;  

        int sz = nums.size();
        int cur_sum = 0;                // only need int
        int max_sum = INT_MIN;

        for (int i = 0; i < sz; i++)
        {
            if (nums[i] > cur_sum + nums[i])            // new sub-array start
            {
                cur_sum = nums[i];                
                temp = i;
            }
            else                                        // continue in old sub-array
            {
                cur_sum += nums[i];
            }

            if (cur_sum > max_sum)                      // to change to latest indices based on addition
            {
                max_sum = cur_sum;
                left = temp;
                right = i;
            }
        }

        cout << "indices window :: " << left << " to " << right << endl;

        return max_sum;
    }
};