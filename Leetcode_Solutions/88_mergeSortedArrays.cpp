#include <bits/stdc++.h>
using namespace std;

void mergeSimple(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int l1 = nums1.size();
    int l2 = nums2.size();

    for(int i = m; i < m + n; i++)
    {
        nums1[i] = nums2[i - m];
    }

    sort (nums1.begin(), nums1.end());
}

void mergeManual(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
    int left = m - 1;
    int right = n - 1;

    int lastIdx = m + n - 1;

    while (right >= 0)
    {
        if (left >= 0 && nums1[left] > nums2[right])
        {
            nums1[lastIdx--] = nums1[left--];
        }

        else
        {
            nums1[lastIdx--] = nums2[right--];
        }
    }
}