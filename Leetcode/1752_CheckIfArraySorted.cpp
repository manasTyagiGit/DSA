#include <bits/stdc++.h>
using namespace std;

bool check(vector<int>& nums) {
    // In a sorted array there can only be one variation,
    // i.e. between last and first element, same is true,
    // for a sorted but rotated array.

    int len = nums.size();

    int variations = 0;

    for (int i = 1; i < len; i++)
    {
        if (nums[i-1] > nums[i])      variations++;
    }

    if (nums[len - 1] > nums[0])      variations++;

    if (variations > 1)
    {
        return false;
    }

    return true;
}

int main ()
{
    int n;

    cin >> n;
    vector <int> nums;

    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;

        nums.push_back(k);

    }

    if (check(nums))
    {
        cout << "Array is rotated and sorted";
    }

    else{
        cout << "Array is not sorted";
    }

    return EXIT_SUCCESS;
}