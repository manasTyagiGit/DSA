#include <bits/stdc++.h>
using namespace std;

/**
 * Merge sort uses the fact that an array of one element is sorted. It divides the array
 * into subarrays recursively, until each subarray has m = 1 elements, then we can
 * percolate upwards merging by comparing two subarrays at a time, and since height
 * of a binary tree (recursive call stack) is Log N, the sorting takes place in 
 * O(N log N) time.
 */

void print_array (int *arr, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        cout << arr[i] << ", ";
    }

    cout << arr[len - 1];

    cout << endl;
}

void percolate_up (int *arr, int low, int mid, int high)
{
    int left = low;
    int right = mid + 1;
    int size = high - low + 1;

    int curr[size] = {0};
    int i = 0;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            curr[i++] = arr[left++];
        }
        else
        {
            curr[i++] = arr[right++];
        }
    }

    while (left <= mid)
    {
        curr[i++] = arr[left++];
    }

    while (right <= high)
    {
        curr[i++] = arr[right++];
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = curr[i - low];
    }

}

void merge_sort (int *arr, int low, int high)
{
    if (low >= high)        return;             // Array of size m = 1

    int mid = low + (high - low) / 2;

    merge_sort (arr, low, mid);
    merge_sort (arr, mid + 1, high);

    percolate_up(arr, low, mid, high);    
}


int main ()
{
    int len = 0;
    cout << "Enter size of your array :: ";
    cin >> len;

    int arr[len];
    cout << "Enter your array :: " << endl;

    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
    }

    cout << "Array is :: ";
    print_array (arr, len);

    cout << "Sorted array is :: ";
    merge_sort(arr, 0, len - 1);
    print_array(arr, len);

    return EXIT_SUCCESS;
}