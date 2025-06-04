#include <bits/stdc++.h>
using namespace std;

// Stack is an Abstract Data Type which uses a L.I.F.O order, i.e., Last In First Out
// It is not a container as it does not expose its members for direct iterations via
// an iterator or a for (auto i: stack)... loop

// The three main operations, s.top(), s.pop(), s.push() takes O(1) time

void print (stack <int> s)
{
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
}

int main (void)
{
    stack <int> s;

    int i = 23;

    s.push(i);
    s.emplace (i + 1);

    print (s);

    cout << s.top() << endl;

    // Other methods are::

    s.emplace (32);

    cout << s.size() << endl;

    cout << s.empty() << endl;
    stack <int> swapper;

    s.swap (swapper);
    cout << "Swapper::" ;
    print (swapper);

    cout << "Size of s :: ";
    cout << s.size() << endl;

    return EXIT_SUCCESS;
}