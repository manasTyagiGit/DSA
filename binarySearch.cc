#include <bits/stdc++.h>
using namespace std;

int binarySearch (int arr[], int low, int high, int key)
{
    if (low > high)             return -1;
     
    int mid = (low + high) / 2;

    if (arr[mid] == key)        return mid;

    else if (arr[mid] > key)    return binarySearch (arr, low, mid - 1, key);
    else                        return binarySearch (arr, mid + 1, high, key);   
}

int main (void)
{
    int n = 0, i = 0;

    cin >> n;
    int arr[n];

    for (i = 0; i < n ; i++)    cin >> arr[i];   

    int key = 0;
    cin >> key;

    int index = binarySearch (arr, 0, n - 1, key);
    
    if (index != -1)            cout << "Found at " << index << endl;
    else                        cout << "Not Found" << endl;

    return EXIT_SUCCESS;
}