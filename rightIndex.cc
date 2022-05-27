#include <bits/stdc++.h>
using namespace std;

int highrIndex (int arr[], int low, int high, int key)
{
    if (low > high)         return high;
    int mid = low + (high - low) / 2;

    if (arr[mid] > key)     return highrIndex (arr, low, mid - 1, key);
    else                    return highrIndex (arr, mid + 1, high, key);    
}

int main (void)
{
    int n = 0, i = 0;

    cin >> n;
    int arr[n];

    for (i = 0; i < n ; i++)        cin >> arr[i];   

    int key = 0;
    cin >> key;

    int highrI = highrIndex (arr, 0, n - 1, key);
   
    cout << highrI << endl;

    return EXIT_SUCCESS;
}