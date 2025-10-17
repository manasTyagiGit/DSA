#include <bits/stdc++.h>
using namespace std;

int lengthSubArray (vector <int> arr)
{
    int len = 0;
    int sz = arr.size();
    int curSum = 0;
    int curLen = 0;

    map <int, int> mp;
    mp[0] = -1;                 // can also use a base entry like this

    for (int i = 0; i < sz; i++)
    {
        curSum += arr[i];
        // if (curSum == 0)
        // {
        //     len = max (i + 1, curLen);
        // }

        if (mp.find(curSum) != mp.end())            // curSum found
        {
            curLen = i - mp[curSum];
            len = max (len, curLen);
        }

        else
        {
            mp[curSum] = i;
        }

    }

    return max(len, curLen);
}

int main (void)
{
    cout << "Enter size of array : n, then the array with space after each element" << endl;
    int n;

    cin >> n;

    vector <int> arr (n, 0);

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        arr[i] = a;
    }

    cout << lengthSubArray (arr) << endl;
    return EXIT_SUCCESS;
}