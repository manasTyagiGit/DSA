#include <bits/stdc++.h>
using namespace std;

/***
 * Using Kadane's algorithm, but travering first from back, and then from the
 * front, having a rolling sum, and if rolling sum = 0, then we reset it to 1
 * which does not affect the sum at all.
 * 
 * We do 2 traverses as from front, the product can be negative, but same product
 * traversed from the last will give right answer, and vice versa
 */

int maxProduct(vector<int>& nums) {
    int maxP = INT_MIN;
    int len = nums.size();
    int curP = 1;

    for (int i = 0; i < len; i++)
    {
        curP *= nums[i];
        maxP = max (maxP, curP);
        if (curP == 0)      curP = 1;
    }

    curP = 1;

    for (int i = len - 1; i >= 0; i--)
    {
        curP *= nums[i];
        maxP = max (maxP, curP);

        if (curP == 0)       curP = 1;
    }

    return maxP;


}