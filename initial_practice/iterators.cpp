// Iterators work by pointing to the memory of a container, and there are
// lots of pre-defined iterators that can be used by us, similar to a pointer

#include <bits/stdc++.h>
using namespace std;

int main(void) 
{
    vector <int> v = {1, 2, 3, 4, 5};
    vector <int> :: iterator it1 = v.begin();

    cout << *(it1) << endl;               // prints the 0th index value

    // Some iterators are::

    vector <int> :: iterator it2 = v.end() - 1;   // just after last element

    cout << *(it2) << endl;

    int it3 = v.back();

    cout << it3 << endl;

    return EXIT_SUCCESS;
}