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

void swap (int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort (int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)                 // This is for the position of swap which we are finding the minimum for
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)             // Finding the minimum in the unsorted portion of the array
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
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

    selection_sort (arr, n);

    cout << "After sorting: ";
    print (arr, n);

    return EXIT_SUCCESS;
}