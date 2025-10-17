#include <bits/stdc++.h>
using namespace std;

/***
 * In a map, unordered_map, we do not need to explicitly add
 * an entry to search it, if it does not exist, it will be
 * having a default key (the one which we are referring via),
 * and the other field as default, here int = 0
 */

int noOfXORSubArrays (vector<int> arr, int target)
{
    int count = 0;
    int len = arr.size();

    unordered_map <int, int> freq;
    freq[0] = 1;
    int rolling_xor = 0;

    for (int i = 0; i < len; i++)
    {
        rolling_xor ^= arr[i];

        int curCheck = target ^ rolling_xor;

        count += freq[curCheck];

        freq[curCheck]++;

    }

    return count;
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

    int target;

    cout << "Enter target XOR value :: " ;

    cin >> target;

    cout << endl;
    cout << noOfXORSubArrays (arr, target) << endl;
    return EXIT_SUCCESS;
}