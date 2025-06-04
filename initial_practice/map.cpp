#include <bits/stdc++.h>
using namespace std;


// A map stores {key, value} pairs, and non-homogenity is supported
// Keys are unique, and not replaced even if a new entry comes in
// Everything is stored in sorted order of keys and iterator goes over a pair ({key, value})

// A multi_map :: can include a one-to-many mapping, i.e., 1 key can have many values
// An unordered_map :: not in a sorted order of keys, does not allow duplicates, generally faster -> O(1) 

void print (map <int, string> mp)
{
    for (auto it : mp)
    {
        cout << it.first << " :: " << it.second << endl;
    }
    cout << endl;
}

int main (void)
{
    map <int, string> mp;

    mp[2] = "wedgie";               // Always stays here, init
    mp.insert ({3, "Tango"});
    mp.emplace (1, "Chango");
    mp.insert ({2, "Tyagi"});       // nope
    mp.emplace (2, "ramen");        // nope

    print (mp);

    mp[2] = "hong-king";            // Now replaced

    print (mp);

    return EXIT_SUCCESS;
}