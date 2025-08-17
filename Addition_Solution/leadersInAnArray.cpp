#include <bits/stdc++.h>
using namespace std;

void print (vector<int> arr)
{
    for (auto it: arr)
    {
        cout << it << "\t";
    }

    cout << endl;
}

vector <int> retLeaderArray (vector<int>& nums)
{
    int sz = nums.size();
    vector <int> ret;

    int cur_leader = nums[sz - 1];
    ret.emplace_back (cur_leader);

    for (int i = sz - 2; i >= 0; i--)
    {
        if (nums[i] > cur_leader)
        {
            cur_leader = nums[i];
            ret.emplace_back(nums[i]);
        }
    }

    return ret;
}

int main (void)
{
    int n;
    cin >> n;

    vector <int> nums;

    for (int i = 0; i < n; i++)
    {
        int key;
        cin >> key;
        nums.emplace_back (key);
    }


    vector<int> ret = retLeaderArray (nums);

    print (ret);
    return EXIT_SUCCESS;
}