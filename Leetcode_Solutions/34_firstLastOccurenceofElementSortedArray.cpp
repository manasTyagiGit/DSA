#include <bits/stdc++.h>
using namespace std;

vector<int>::iterator lower_bound(vector<int>:: iterator begin, vector<int>:: iterator end, int target)
{
    while (begin < end)
    {
        vector<int>:: iterator mid = (begin) + (end - begin) / 2;

        if (*mid >= target)         // hit a value > or = the target, a bound found, search in left to find smaller lower bound
        {
            end = mid;
        }

        else
        {
            begin = mid + 1;
        }

    }

    return begin;
}

vector<int>:: iterator upper_bound (vector<int>:: iterator begin, vector <int>:: iterator end, int target)
{
    while (begin < end)
    {
        vector<int>:: iterator mid = (begin) + (end - begin) / 2;

        if (*mid > target)         // hit a value > or = the target, a bound found, search in left to find smaller upper bound
        {
            end = mid;
        }

        else
        {
            begin = mid + 1;
        }

    }

    return begin;
}

vector<int> searchRange(vector<int>& nums, int target) {
    auto lowerbound = lower_bound (nums.begin(), nums.end(), target);

    if (lowerbound == nums.end() || *lowerbound != target)        return {-1, -1};

    auto upperbound = upper_bound (nums.begin(), nums.end(), target);

    vector <int> idx;

    idx.push_back(lowerbound - nums.begin());
    idx.push_back(upperbound - 1 - nums.begin());

    return idx;    
}

int main (void)
{
    int n;

    cout <<"Enter the size of array: n, then the elements of array, then the target :: \n";
    
    cin >> n;
    vector<int> nums(n, 0);

    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        
        nums[i] = v;
    }

    int target;

    cin >> target;

    vector<int> idx = searchRange (nums, target);

    for (auto it: idx)
    {
        cout << it << ",";

    }
    
    cout << endl;

    return EXIT_SUCCESS;
}