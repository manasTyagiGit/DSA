#include <bits/stdc++.h>
using namespace std;

void print (int arr[], int n)
{
    for (int i = 0; i < n - 1; i++) 
    {
        cout << arr[i] << ", ";
    }

    cout << arr[n - 1] << endl;
}

void merge (int arr[], int low, int mid, int high)
{
    int size = high - low + 1;              // for each recrusive call, have to define this merge size.
    int temp[size] = {0};                   // set all to 0
    int j = 0;                              // temp iterator variable

    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp[j++] = arr[left++];
        }
        else
        {
            temp[j++] = arr[right++];
        }
    }

    while (left <= mid)
    {
        temp[j++] = arr[left++];
    }

    while (right <= high)
    {
        temp[j++] = arr[right++];
    }
    
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void merge_sort (int arr[], int low, int high)
{
    if (low >= high)    return;

    int mid = (high + low) / 2;

    merge_sort (arr, low, mid);
    merge_sort (arr, mid + 1, high);

    merge (arr, low, mid, high);
}


int main (void) {

    int n;

    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Initial array: ";
    print (arr, n);

    merge_sort (arr, 0, n - 1);

    cout << "After sorting: ";
    print (arr, n);

    return EXIT_SUCCESS;
}