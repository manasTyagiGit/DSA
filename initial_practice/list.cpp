#include <bits/stdc++.h>
using namespace std;

/**
 * A list provides front and back operations more naturally
 * It is maintained as a Double linked list
 * 
 * Even though insert() operations are faster than a vector, but a vector
 * provides O(1) random access, and is more cache-friendly, so generally
 * a vector is faster than a list in programming
*/

void print (list<int> ls)
{
    for (auto x : ls)
    {
        cout << x << "\t";
    }

    cout << endl;
}

int main (void)
{
    list <int> ls;

    ls.push_back (1);
    ls.emplace_back (0);

    ls.emplace_front (3);
    ls.push_front (2);

    // insert (v.begin() + 0, val) is costlier than the above for a vector

    print (ls);
    
    return EXIT_SUCCESS;
}