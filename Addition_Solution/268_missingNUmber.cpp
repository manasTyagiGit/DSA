#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // Hashing solution start   - 0 ms
        /*int sz = nums.size();

        vector<int> freq(sz + 1, 0);

        for (int i = 0; i < sz ; i++)
        {
            freq[nums[i]]++;
        }

        for (int i = 0; i < sz; i++)
        {
            if (freq[i] == 0)       return i;
        }

        return sz;*/
        // Hashing solution end
        

        // Concept of an Arithmetic progression, though non-sorted   - 0 ms
        /*int sz = nums.size();

        long int sum = ((sz + 1) * (sz)) / 2;
        long int sumActual = 0;

        cout << "Sum :: " << sum << endl;

        for (int i = 0; i < sz; i++)
        {
            sumActual += nums[i];
        } 

        return (sum - sumActual);*/

        // Concept of XOR - supposedly uses less memory - 4ms

        int sz = nums.size();

        int x1 = 0;
        int x2 = 0;

        for (int i = 0; i < sz; i++)
        {
            x1 = x1 ^ i;
            x2 = x2 ^ nums[i];
        }

        x1 = x1 ^ sz;

        int missing = x1 ^ x2;

        cout << "Missing is :: " << missing << endl;

        return missing;

    }
};