#include <bits/stdc++.h>
using namespace std;

void printArr (int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)     cout << arr[i] << ", ";

    cout << arr[n - 1] << endl;
}

void swap (int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partitionFunction (int arr[], int low, int high)
{
    int i = low, pivotIndex = high, firstLarger = low;

    for (i = low; i < high; i++)
    {
        if (arr[i] < arr[pivotIndex])
        {
            swap (&arr[i], &arr[firstLarger]);
            firstLarger++;
        }        
    }

    swap (&arr[pivotIndex], &arr[firstLarger]);

    return firstLarger;    
}

int lobudoPartition (int arr[], int low, int high)
{
    srand (time(NULL));
    int random = low + rand() % (high - low);

    swap (&arr[random], &arr[high]);
    
    return partitionFunction (arr, low, high);
}

void quickSort (int arr[], int low, int high)
{
    int pivotIndex = 0;
    if ((high - low) > 0)
    {
        pivotIndex = lobudoPartition (arr, low, high);
        quickSort (arr, low, pivotIndex - 1);
        quickSort (arr, pivotIndex + 1, high);
    }
}

int main (void)
{
    int n = 0, key = 0;;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)     cin >> arr[i];    

    printArr (arr, n);
    quickSort (arr, 0, n - 1);
    printArr (arr, n);

    return EXIT_SUCCESS;
}