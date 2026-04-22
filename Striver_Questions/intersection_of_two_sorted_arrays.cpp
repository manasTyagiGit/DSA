#include <bits/stdc++.h>
using namespace std;

void print (vector <int> arr)
{
    for (auto it : arr)
    {
        cout << it << "\t";

    }

    cout << endl;
}

vector<int> find_inter (vector<int> nums1, vector<int> nums2)
{
    vector<int> ret;
    
    // For unsorted arrays, although an unordered_set can also be used for implementation
    //sort (nums1.begin(), nums1.end());        
    //sort (nums2.begin(), nums2.end());

    int i = 0, j = 0;
    int size1 = nums1.size(), size2 = nums2.size();

    while (i < size1 && j < size2)
    {
        if (i > 0 && nums1[i - 1] == nums1[i])
        {
            i++;
            continue;
        }

        if (j > 0 && nums2[j - 1] > nums2[j])
        {
            j++;
            continue;
        }

        if (nums1[i] < nums2[j])            i++;
        else if (nums2[j] < nums1[i])       j++;
        else{
            ret.push_back (nums1[i]);
            i++;
            j++;
        }
    }

    return ret;
}

int main (void)
{
    vector <int> num1 = {1, 2, 2, 3, 4, 4, 5, 7};
    vector <int> num2 = {2, 3, 4, 6, 7, 8};

    cout << "Answer should be :: 2, 3, 4, 7" << endl; 

    vector <int> inter_res = find_inter (num1, num2);

    print (inter_res);

    return EXIT_SUCCESS;
}