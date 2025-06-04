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

void bubble_sort (int arr[], int n)
{
    for (int i = n - 1; i >= 1; i--)                // The outside loop runs from last to first
    {
        bool swap_flag = false;
        for (int j = 0; j < i; j++)                 // The inside loop runs from 0th to i-1 index to compare, as i onwards is sorted
        {
            if (arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                swap_flag = true;                
            }
        }
        if (!swap_flag)
        {
            cout << "it is sorted already" << endl;
            break;
        }
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

    bubble_sort (arr, n);

    cout << "After sorting: ";
    print (arr, n);

    return EXIT_SUCCESS;
}