#include <bits/stdc++.h>
using namespace std;

int main(void) 
{
    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // Erase method

    v.erase (v.begin() + 2);            // erases value at index 2    

    v.erase (v.begin() + 2, v.begin() + 5);     //erases from 2 to 4

    // Insert method

    v.insert (v.begin() + 2, 34);           // inserts 34 at index = 2

    v.insert (v.begin() + 3, 3, 69);        // inserts 69, 3 times, from index = 3 to 3+3-1 = 5

    vector <int> x = {9, 8, 9};

    v.insert (v.begin() + 1, x.begin(), x.end());       // inserts another vector x in v, at index = 1   

    for (auto it : v)
    {
        cout << it << "\t";
    }

    // Other methods::

    cout << "\nSize of vector v == " << v.size() << endl;
    v.pop_back();
    cout << "Size of vector v == " << v.size() << endl;
    cout << "Is vector v empty ? " << (bool)v.empty() << endl;    // 0 is non empty

    v.swap(x);          // swap v, with x vector

    for (auto it : v)
    {
        cout << it << "\t";
    }

    v.clear();              // clear all of v, empty it

    cout << "Size of vector v == " << v.size() << endl;
    cout << "Is vector v empty ? " << (bool)v.empty() << endl;

    cout << endl;
    return EXIT_SUCCESS;
}
