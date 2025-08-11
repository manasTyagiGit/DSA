#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int violations = 0;
        int s = size (nums);
        for (int i = 1; i < s; i++)
        {
            if (nums[i - 1] > nums[i])      violations++;
        }

        if (nums[0] < nums[s - 1])          violations++;

        cout << "No of violations :: " << violations << endl;

        return (violations > 1) ? (false) : (true);
    }
};

int main (void)
{
    int n = 0;

    cin >> n;
    vector<int> nums;
    int val;

    for (int i = 0; i < n; i ++){
        cin >> val;

        nums.emplace_back (val);
    }

    Solution sol;

    cout << (bool) sol.check(nums) << endl;

    return EXIT_SUCCESS;
}