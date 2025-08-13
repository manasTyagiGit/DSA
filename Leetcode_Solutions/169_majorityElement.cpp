#include <bits/stdc++.h>
using namespace std;

class Solution {
public: 
    int majorityElementHashing(vector<int>& nums) {                 //T.C. = O(nlogn), S.C. = O(n)
        // This is a brute solution of Linear time, but
        // uses extra space for frequency array (hashing)

        map <int, int> freq;        
        int sz = nums.size();

        int majorityEle = nums[0];

        for (int i = 0; i < sz; i++)
        {
            freq[nums[i]]++;

            if (freq[nums[i]] > floor (sz / 2))
            {
                majorityEle = nums[i];
            }
        }        

        return majorityEle;

    }

    int majorityElement (vector<int>& nums)                         //T.C. = O(n), S.C. = O(1)
    {
        int majority = nums[0];
        int count = 0;

        int sz = nums.size();

        for (int i = 0; i < sz; i++)
        {      
            if (count == 0)
            {
                majority = nums[i];
                count++;
            }

            else if (majority == nums[i])
            {
                count++;
            }

            else
            {
                count--;
            }
        }

        /**
            In this question 169_majorityElement, there is an assumption that
            majority element always exists, but in case this assumption is not
            there, we should use another loop to count occurences of the 
            majority which is essentially a candidate only
        */
        return majority;
    }

};