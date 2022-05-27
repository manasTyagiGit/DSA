#include <bits/stdc++.h>
using namespace std;

void printArr (int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)     cout << arr[i] << ", ";

    cout << arr[n - 1] << endl;
}

void merge (int arr[], int low, int mid, int high)
{
    int i = 0, j = 0, k = 0;
    int lSize = mid - low + 1, rSize = high - mid;

    int left[lSize], right[rSize];

    for (i = 0; i < lSize; i++)     left[i] = arr[i + low];    
    for (i = 0; i < rSize; i++)     right[i] = arr[i + mid + 1];

    i = low;

    while ((j < lSize) && (k < rSize))
    {
        if (left[j] <= right[k])    arr[i++] = left[j++];
        else                        arr[i++] = right[k++];
    }    

    while (j < lSize)               arr[i++] = left[j++]; 
    while (k < rSize)               arr[i++] = right[k++];
}

void mergeSort (int arr[], int low, int high)
{
    int mid = 0;

    if (low < high)
    {
        mid = (high + low) / 2;
        mergeSort (arr, low, mid);
        mergeSort (arr, mid + 1, high);
        merge (arr, low, mid, high);
    }
}

int main (void)
{
    int n = 0, key = 0;;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)     cin >> arr[i];    

    printArr (arr, n);
    mergeSort (arr, 0, n - 1);
    printArr (arr, n);

    return EXIT_SUCCESS;
}