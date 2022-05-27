#include <bits/stdc++.h>
using namespace std;

int lowerIndex (int arr[], int low, int high, int key)
{
    if (low > high)             return high;                                        // index of the first arr[x] < key
     
    int mid = (low + high) / 2;

    if (arr[mid] < key)         return lowerIndex (arr, mid + 1, high, key);
    else                        return lowerIndex (arr, low, mid - 1, key);         // = key shifts to lower side
}

int highrIndex (int arr[], int low, int high, int key)
{
    if (low > high)             return low;                                         // index of the first arr[x] > key
     
    int mid = (low + high) / 2;

    if (arr[mid] > key)         return highrIndex (arr, low, mid - 1, key);
    else                        return highrIndex (arr, mid + 1, high, key);        // = shifts to the higher side   
}

int main (void)
{
    int n = 0, i = 0;

    cin >> n;
    int arr[n];

    for (i = 0; i < n ; i++)        cin >> arr[i];   

    int key = 0;
    cin >> key;

    int lowerI = lowerIndex (arr, 0, n - 1, key);
    int highrI = highrIndex (arr, 0, n - 1, key);
    cout << "L_index :: " << lowerI << "\tH_index :: " << highrI << endl;

    cout << "Number of Occurences of " << key << " = " << highrI - lowerI - 1 << endl;

    return EXIT_SUCCESS;
}