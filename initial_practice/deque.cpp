#include <bits/stdc++.h>
using namespace std;

// Another container in C++ STL, with uses similar to List
void print (deque <int> d)
{
    for (auto it: d)
    {
        cout << it << "\t";
    }
    cout << endl;
}


int main (void)
{
    deque <int> dq;

    dq.push_back (1);
    dq.emplace_back (0);

    dq.emplace_front (2);
    dq.push_front (3);

    print (dq);

    cout << (dq.back()) << endl;
    cout << (dq.front()) << endl;

    return EXIT_SUCCESS;

}