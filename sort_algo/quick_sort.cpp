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

int partition (int arr[], int low, int high)
{
    int pivot = low;

    int i = low, j = high;

    while (i < j)
    {
        while (i < high && arr[i] <= arr[pivot])     i++;
        while (j > low && arr[j] > arr[pivot])       j--;

        if (i < j)
        {
            swap (&arr[i], &arr[j]);
        }
    }

    swap (&arr[j], &arr[pivot]);

    return j;
}

void quick_sort (int arr[], int low, int high)
{
    if (low < high)
    {
        int p_idx = partition (arr, low, high);

        quick_sort (arr, low, p_idx - 1);
        quick_sort (arr, p_idx + 1, high);
    }
}

int main (void)
{
    int n;

    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Before sorting: ";

    print (arr, n);

    quick_sort (arr, 0, n - 1);

    cout << "After sorting: ";

    print (arr, n);
}