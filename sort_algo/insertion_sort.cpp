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

void insertion_sort (int arr[], int n) 
{
    for (int i = 0; i < n; i++)
    {
        int j = i;
        
        while (j > 0 && arr[j - 1] > arr[j])
        {
            swap(arr[j], arr[j - 1]);
            j -= 1;
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

    insertion_sort (arr, n);

    cout << "After sorting: ";
    print (arr, n);

    return EXIT_SUCCESS;
}