#include <bits/stdc++.h>
using namespace std;

/**
 * Insertion sort works by picking an element in current unsorted array, and putting it at 
 * its right place, by subsequent swaps, eventually expanding the area of sorted array from
 * i = 1 till length of array
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

void insertion_sort (int arr[], int len)
{
    for (int i = 0; i < len; i++){
        int j = i;

        while (j > 0 && arr[j - 1] > arr[j])
        {
            swap (arr[j - 1], arr[j]);
            j--;
        }
    }

    print_array(arr, len);
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
    insertion_sort (arr, len);

    return EXIT_SUCCESS;
}