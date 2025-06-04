#include <bits/stdc++.h>
using namespace std;

// simple binary search return either the index of key in arr[] if found, else -1

int simple_binary_search (int arr[], int high, int low, int key)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)                return mid;

        else if (arr[mid] < key)            low = mid + 1;

        else                                high = mid - 1;
    }

    return -1;
}

// This type of Binary Search method returns either the index where 'key' exists, else returns
// the index of the next immediate greater element

int lower_bound_binary_search (int arr[], int high, int low, int key)
{
    int mid = 0;
    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (arr[mid] == key)                return mid;

        else if (arr[mid] < key)            low = mid + 1;

        else                                high = mid - 1;
    }

    return low;   
}

// This type of binary search either returns the index where key resides in arr[],
// or return the index for the element which is immediately smaller than the key
int upper_bound_binary_search (int arr[], int high, int low, int key)
{
    int mid = 0;
    int ret = 0;

    while (low < high)
    {
        mid = low + (high - low) / 2;

        if (arr[mid] == key)                return mid;
        
        else if (arr[mid] > key)            high = mid - 1;

        else
        {
            ret = mid;
            low = mid + 1;
        }     
    }

    return ret;
}


int main (void)
{
    int arr[10] = {10, 20, 30, 35, 50, 60, 70, 80, 90, 100};

    int key = 35;
    int idx = lower_bound_binary_search (arr, 10, 0, key);            // searching index of '40' in the arr[]
    int idx2 = upper_bound_binary_search (arr, 10, 0, key);
    cout << "Index of " << key << " in arr[] is :: " << idx << endl;
    cout << "Index of " << key << " in arr[] is :: " << idx2 << endl;


    // Builtin methods::

    vector <int> v = {10, 20, 30, 35, 50, 60, 70, 80, 90, 100};

    int id1 = lower_bound (v.begin(), v.end(), key) - v.begin();    // returns index for value immediately greater than key, or index for key
    int id2 = upper_bound (v.begin(), v.end(), key) - v.begin();    // return index for value immediately greater than key.

    cout << id1 << "\t" << id2 << endl;

    return EXIT_SUCCESS;
}