#include <bits/stdc++.h>
using namespace std;


int main (void)
{
    int n;
    cin >> n;
    int arr[n];
    pair<int, int> max = {0, 0};

    map <int, int> mp_freq;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mp_freq[arr[i]]++;

        if (mp_freq[arr[i]] > max.second)
        {
            max.second = mp_freq[arr[i]];
            max.first = arr[i];
        }
    }

    int q;
    cin >> q;

    while (q--)
    {
        int number;
        cin >> number;

        cout << number << " : " << mp_freq[number] << endl;
    }

    cout << "Element with max frequency is :: " << max.first 
    << " : " << max.second << " times" << endl;
    return EXIT_SUCCESS;
}