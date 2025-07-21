/*
* This is for union of two sorted arrays, the union also has to be sorted and 
* should not have duplicates, we can use a set data structure for a Brute Force
* solution. Here we are using two pointers to solve this problem
*
*
*/


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

vector <int> find_union (vector<int>& num1, vector<int>& num2)
{
    int i = 0;
    int j = 0;

    int size1 = num1.size();
    int size2 = num2.size();

    vector <int> ret;

    while (i < size1  && j < size2)
    {
        if (num1[i] <= num2[j])
        {
            if (ret.size() == 0 || ret.back() != num1[i])
                ret.push_back (num1[i]);
            i++;
        }

        else if (num2[j] < num1[i])
        {
            if (ret.size() == 0 || ret.back() != num2[j])
                ret.push_back(num2[j]);
            j++;
        }
    }

    while (i < size1)
    {
        if (ret.size() == 0 || ret.back() != num1[i])
                ret.push_back (num1[i]);
        i++;
    }

    while (j < size2)
    {
        if (ret.size() == 0 || ret.back() != num2[j])
                ret.push_back(num2[j]);
        j++;
    }

    return ret;
}

int main (void)
{
    vector <int> num1 = {1, 2, 2, 3, 4, 4, 5, 7};
    vector <int> num2 = {2, 3, 4, 6, 7, 8};

    cout << "Answer should be :: 1  2   3   4   5   6   7   8" << endl; 

    vector <int> union_res = find_union (num1, num2);

    print (union_res);

    return EXIT_SUCCESS;
}