#include <bits/stdc++.h>
using namespace std;

// This is another ADT which uses FIrst in First out order of entry/operations

void print (queue <int> q)
{
    while (!q.empty()) {
        cout << q.front() << "\t";
        q.pop();
    }

    cout << endl;
}

int main (void)
{
    queue <int> q;

    q.emplace (1);
    q.push (2);
    q.push (3);

    q.back() += 5;

    print (q);

    q.front() += -1;
    print (q);
    return EXIT_SUCCESS;
}