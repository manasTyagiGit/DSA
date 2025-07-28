#include <bits/stdc++.h>
using namespace std;

int findLongestSubArray_O2 (int arr[], int n, int target)
{
    int longest = 0;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];

            if (sum == target)
            {
                longest = max (longest, j - i + 1);
            }
        }
    }

    return longest;
}

int findLongestSubArray_map (int arr[], int n, int target)
{
    unordered_map <int, int> prefixSum;
    int maxLen = 0;

    int curSum = 0;

    for (int i = 0; i < n; i++)
    {
        curSum += arr[i];

        if (curSum == target)                                           // check if currently the sum equals target
        {
            maxLen = max (maxLen, i + 1);
        }

        int rem = curSum - target;

        if (prefixSum.find(rem) != prefixSum.end())                     // check if entry for remainder is there
        {
            int curLen = i - prefixSum[rem];
            maxLen = max (maxLen, curLen);
        }

        if (prefixSum.find(curSum) == prefixSum.end())                  // only add if does not exist
            prefixSum[curSum] = i;
    }
    
    return maxLen;
}

int findLongestSubArray_pos (int arr[], int n, int target)
{
    int maxLen = 0;
    int right = 0, left = 0;
    int curSum = arr[0];

    while (right < n)
    {
        while (curSum > target && left <= right)
        {
            curSum -= arr[left];
            left++;
        }

        if (curSum == target)
        {
            maxLen = max (maxLen, right - left + 1);
        }

        right++;

        if (right < n)
        {
            curSum += arr[right];
        }        
    }

    return maxLen;
}

int main (void)
{
    int n = 10;
    int arr[n] = {1, 2, 3, 1, 0, 1, 1, 1, 4, 6};
    int arr_neg[n+2] = {1, 2, 3, 1, 1, -1, 1, 0, 1, 1, 4, 6};
    int target = 0;

    cin >> target;

    //int len_longest = findLongestSubArray_O2 (arr, n, target);
    int len_longest = findLongestSubArray_map (arr_neg, n, target);

    int len_longest_pos = findLongestSubArray_pos (arr, n, target);

    cout << "Length of longest in positive map:: " << len_longest_pos << endl;
    cout << "Length of longest in pos+neg map:: " << len_longest << endl;

    return EXIT_SUCCESS;
}
