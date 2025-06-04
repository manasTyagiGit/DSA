#include <bits/stdc++.h>
using namespace std;

#define MAX_TERMS 13

int main (void)
{
    int n;
    cin >> n;

    int arr[n];
    int freq[MAX_TERMS] = {0};

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        freq[arr[i]] += 1;
    }

    int q;
    cin >> q;    

    for (int i = 0; i < q; i++)
    {
        int num;
        cin >> num;

        cout << num << " : " << freq[num] << endl;
    }
    return EXIT_SUCCESS;
}