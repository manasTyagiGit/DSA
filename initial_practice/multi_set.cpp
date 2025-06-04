#include <bits/stdc++.h>
using namespace std;

// A multiset can contain duplicates, but follows a sorted order

void print (multiset <int> s)
{
    for (auto x : s)
    {
        cout << x << "\t";
    }

    cout << endl;
}


int main (void)
{
    multiset <int> s;

    s.emplace (1);
    s.emplace (1);
    s.insert (5);
    s.insert (0);
    s.insert(-1);
    s.insert(-2);
    s.emplace (12);
    s.emplace (1);
    s.emplace (5);

    print (s);              // {0, 1, 5, 12}

    auto it2 = s.find(1);
    auto it1 = s.find(2);

    cout << *(it2) << "\t" << *(it1) << endl;

    s.erase(5);
    s.erase(it2);

    print (s);

    cout << s.count(1) << "\t" << s.count (12) << endl;

    return EXIT_SUCCESS;
}