#include <bits/stdc++.h>
using namespace std;

// An unordered_set has random order but only unique elements are allowed

void print (unordered_set <int> s)
{
    for (auto x : s)
    {
        cout << x << "\t";
    }
    cout << "Hey it ends here";
    cout << endl;
}


int main (void)
{
    unordered_set <int> s;

    s.emplace (1);    
    s.insert (5);
    s.insert (0);    
    s.emplace (12);  

    cout << "Before print";
    print (s);              // {0, 1, 5, 12}
    cout << "After print";
    cout << "it2 call";
    auto it2 = s.find(1);
    cout << "it1 call";
    auto it1 = s.find(5);

    cout << *(it2) << "\t" << *(it1) << endl;

    s.erase(5);
    s.erase(it2);

    print (s);

    cout << s.count(1) << "\t" << s.count (12) << endl;

    return EXIT_SUCCESS;
}