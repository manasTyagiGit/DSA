#include <bits/stdc++.h>
using namespace std;

int main(void) 
{
    vector <int> v = {1, 2, 3, 4, 5, 6, 7};

    for (vector <int> :: iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *(it) << endl;
    }

    //OR

    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *(it) << endl;
    }

    for (auto it : v)
    {
        cout << it << endl;
    }

    return EXIT_SUCCESS;
}
