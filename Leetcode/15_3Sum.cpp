#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSumClassic(vector<int>& nums) {
    int len = nums.size();
    set <vector<int>> st;       // return set -> vector
    set <int> hset;

    for (int i = 0; i < len; i++)
    {
        hset.clear();           // insert j here for all elements other than nums[i]
        for (int j = i + 1; j < len; j++)
        {
            int third = -(nums[i] + nums[j]);       // third element
            
            if(hset.find(third) != hset.end())      // if some j was actually 'third' for some 'i' and another 'j'
            {
                vector<int> cur = {nums[i], nums[j], third};
                sort (cur.begin(), cur.end());
                st.insert (cur);
            }

            hset.insert (nums[j]);                  // insert nums[j]
        }
    }

    vector<vector<int>> ret(st.begin(), st.end());

    return ret;
}

vector<vector<int>> threeSumBest2Ptr(vector<int>& nums)
{

}


int main ()
{
    vector <int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans= threeSumClassic(nums);

    return EXIT_SUCCESS;
}
