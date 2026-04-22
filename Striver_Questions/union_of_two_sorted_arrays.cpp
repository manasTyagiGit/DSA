#include <bits/stdc++.h>
using namespace std;

void print (vector <int> nums)
{
    for (auto it : nums)
    {
        cout << it << "\t";

    }

    cout << endl;
}

vector<int> find_union(vector<int> nums1, vector<int> nums2)
{
    int i = 0, j = 0;
    int size1 = nums1.size(), size2 = nums2.size();
    vector<int> ret;

    while (i < size1 && j < size2)
    {
        if (nums1[i] <= nums2[j])
        {
            if (ret.size() == 0 || ret.back() != nums1[i])
            {
                ret.push_back(nums1[i]);
            }
            i++;
        }

        else
        {
            if (ret.size() == 0 || ret.back() != nums2[j])
            {
                ret.push_back(nums2[j]);
            }
            j++;
        }
    }

    while (i < size1)
    {
        if (ret.size() == 0 || ret.back() != nums1[i])
        {
            ret.push_back(nums1[i]);
            
        }
        i++;
    }

    while (j < size2)
    {
        if (ret.size() == 0 || ret.back() != nums2[j])
        {
            ret.push_back(nums2[j]);
        }
        j++;
    }

    return ret;
}

int main ()
{
    vector <int> num1 = {1, 2, 2, 3, 4, 4, 5, 7};
    vector <int> num2 = {2, 3, 4, 6, 7, 8};

    cout << "Answer should be :: 1  2   3   4   5   6   7   8" << endl; 

    vector <int> union_res = find_union (num1, num2);

    print (union_res);
    return EXIT_SUCCESS;
}