#include <bits/stdc++.h>
using namespace std;

void printvec (vector<int> v)
{
    cout << "[";
    for (auto it: v)
    {
        cout << it << " ";
    }

    cout << "], ";
}

void print (vector<vector<int>> v)
{
    for (auto vec : v){
        printvec (vec);        
    }
    cout << endl;
}

vector<vector<int>> threeSumBrute(vector<int>& nums) {
    set <vector<int>> hashset;

    int sz = nums.size();

    for (int i = 0; i < sz - 2; i++)
    {
        for (int j = i + 1; j < sz - 1; j++)
        {
            for (int k = j + 1; k < sz; k++)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    vector <int> v = {nums[i], nums[j], nums[k]};
                    sort(v.begin(), v.end());
                    hashset.insert(v);
                }
            }
        }
    }    
    vector<vector<int>> vec (hashset.begin(), hashset.end());

    return vec;
}

vector<vector<int>> threeSumBetter(vector<int>& nums) {                 // TLE on 313/315 test case
    set <vector<int>> hashset;
    int sz = nums.size();

    set <int> rolling_set;

    for (int i = 0; i < sz; i++)
    {
        rolling_set.clear();
        for (int j = i + 1; j < sz; j++)
        {
            int k = - (nums[i] + nums[j]);

            if (rolling_set.find(k) != rolling_set.end())      // found
            {
                vector <int> v = {nums[i], nums[j], k};
                sort(v.begin(), v.end());

                hashset.insert(v);
            }

            rolling_set.insert(nums[j]);
        }
    }
        
    vector<vector<int>> vec (hashset.begin(), hashset.end());

    return vec;
}

vector<vector<int>> threeSumBest(vector<int>& nums) {
        int sz = nums.size();
        sort (nums.begin(), nums.end());

        vector <vector <int>> ans;

        for (int i = 0; i < sz; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])        continue;

            int j = i + 1;                              // next
            int k = sz - 1;                             // final

            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum > 0)
                {
                    // shrink array by right to fit smaller element into nums[k]
                    k--;
                }
                else if (sum < 0)
                {
                    // shrink array by left to fit larger element into nums[j]
                    j++;
                }
                else
                {
                    vector <int> v = {nums[i], nums[j], nums[k]};
                    ans.push_back (v);

                    j++;            // move to next
                    k--;            // move to previous

                    while (j < k && nums[j] == nums[j - 1])     j++;
                    while (j < k && nums[k] == nums[k + 1])     k--; 
                }

            }
        }
        return ans;
    }

int main (void)
{
    int n;

    cin >> n;

    vector <int> nums (n, 0);

    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;

        nums[i] = k;
    }

    vector<vector<int>> ans = threeSumBest (nums);

    print (ans);

    return EXIT_SUCCESS;
}