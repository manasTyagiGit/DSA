#include <bits/stdc++.h>
using namespace std;

/**
 * Selection sort picks the element which is the smallest in the unsorted array,
 * and puts it at the lowest position in the unsorted array
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

void selection_sort (int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        int min_idx = arr[i];
        for (int j = i; j < len; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        swap (arr[i], arr[min_idx]);
    }

    print_array(arr, len);
}


int main()
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
    selection_sort (arr, len);

    return EXIT_SUCCESS;
}