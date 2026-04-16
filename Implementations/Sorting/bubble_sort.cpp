#include <bits/stdc++.h>
using namespace std;

/**
 * Bubble sort works via picking the largest element and then putting it at the largest available index
 * Hence we start creating bubbles of sorted, and unsorted I guess, I could be wrong here though as to
 * what 'BUBBLE' means. We do subsequent swaps until the element is at its place
 */

void print_array (int arr[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        cout << arr[i] << ", ";
    }

    cout << arr[len - 1];

    cout << endl;
}


void bubble_sort (int arr[], int len)
{
    for (int i = len - 1; i > 0; i--)
    {
        bool swap_done = false;                 // To check in one sweep if array is already sorted
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap_done = true;
                swap (arr[j], arr[j + 1]);
            }
        }

        if (!swap_done)     break;              // Best case = O(N)
    }

    print_array (arr, len);
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
    bubble_sort(arr, len);

    return EXIT_SUCCESS;
}