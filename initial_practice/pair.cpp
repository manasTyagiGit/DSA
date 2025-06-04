#include <bits/stdc++.h>
using namespace std;

int main (void)
{
    pair <int, float> pair_obj1;
    pair_obj1 = {1, 1.01};

    cout << pair_obj1.first << "  <-- first part of pair\n" 
    << pair_obj1.second << "  <--- second part\n";

    pair <int, pair <int, string>> nested_pair;

    nested_pair = {1, {31, "Bit length of a positive primitive Int"}};

    cout << "Sr. No.: " << nested_pair.first << "\nEntry: " << nested_pair.second.first 
    << "\nDescription: " << nested_pair.second.second << endl;

    pair <int, int> arr[] = {{1, 2}, {2, 4}, {3, 6}};

    for (int i = 0; i < size(arr); i++)
    {
        cout << i << ":: " << arr[i].first << ", " << arr[i].second << endl;
    }

    return EXIT_SUCCESS;
}