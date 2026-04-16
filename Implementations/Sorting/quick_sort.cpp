#include <bits/stdc++.h>
using namespace std;

/**
 * Quick sort works by picking up an element (random pivot), and then puts it at its right place
 * in the array, and then arranges the numbers on its left and right. Left side numbers are always
 * smaller, and right side numbers are always larger, equal can be kept on either, left by default.
 * 
 * Then the same can be recursively done for left and right sides as pivot is already at its right place,
 * i.e, Divide and Conquer.
 * 
 * Only be wary to pick an element that is random and not the right most or left most, as this algorithm 
 * can run upto O(N^2) in that worst case if the array is sorted.
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

int partition (int* arr, int low, int high)
{
    int pivot = low;        // try not to do this, pick random
    int i = low, j = high;

    while (i < j)
    {
        while (i < high && arr[i] < arr[pivot])
        {
            i++;
        }

        while (j > low && arr[j] > arr[pivot]){
            j--;
        }
        if (i < j)
            swap (arr[i], arr[j]);
    }

    swap(arr[j], arr[pivot]);
    
    return pivot;
}

void quick_sort (int* arr, int low, int high)
{
    if (low < high)             // it will be recursive on subarrays (left, and right)
    {
        int pivot = partition (arr, low, high);
        quick_sort (arr, low, pivot - 1);
        quick_sort (arr, pivot + 1, high);
    }
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
    quick_sort(arr, 0, len - 1);
    print_array(arr, len);

    return EXIT_SUCCESS;
}