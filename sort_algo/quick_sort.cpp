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

void quick_sort (int arr[], int n)
{
    return;
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

    quick_sort (arr, n);

    cout << "After sorting: ";

    print (arr, n);
}