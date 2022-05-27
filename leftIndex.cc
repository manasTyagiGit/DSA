#include <bits/stdc++.h>
using namespace std;

int lowerIndex (int arr[], int low, int high, int key)
{
    if (low > high)         return low;
    int mid = low + (high - low) / 2;

    if (arr[mid] < key)     return lowerIndex (arr, mid + 1, high, key);
    else                    return lowerIndex (arr, low, mid - 1, key);    
}

int main (void)
{
    int n = 0, i = 0;

    cin >> n;
    int arr[n];

    for (i = 0; i < n ; i++)        cin >> arr[i];   

    int key = 0;
    cin >> key;

    int lowerI = lowerIndex (arr, 0, n - 1, key);
   
    cout << lowerI << endl;

    return EXIT_SUCCESS;
}