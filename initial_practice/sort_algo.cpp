#include <bits/stdc++.h>
using namespace std;

void print (int arr[], int n)
{   
    
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }

    cout << endl;
}

bool comp(pair <int, int> x, pair <int, int> y)
{
    if (x.second < y.second)    return true;
    if (x.second > y.second)    return false;

    if (x.first < y.first)      return true;
    if (x.first > y.first)      return false;

    return false;
}

int main (void)
{
    int arr[5] = {112, 23242, 1213414, 564, 15};

    sort (arr, arr + 5);                // arr + n, where n is not included, it is only upper bound

    // for vectors:

    vector <int> v = {1, 4, -1, 0, 32};

    sort (v.begin(), v.end());

    sort (v.begin(), v.end(), greater<int>());          // reverse sorted, with inbuilt greater<>() comparator
    
    // custom comparator
    vector <pair< int, int>> vp = {{1, 2}, {-1, -2}};
    sort (vp.begin(), vp.end(), comp);

    print (arr, 5);

    cout << *max_element (v.begin(), v.end()) << endl;

    return EXIT_SUCCESS;
}