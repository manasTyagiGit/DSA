#include <bits/stdc++.h>
using namespace std;

int euclid1 (int u, int v)
{
    int temp = 0;

    while (v != 0)
    {
        temp = u % v;       // calculate the reaminder
        u = v;              // make u the bigger number, for ease of operations
        v = temp;           // use the remainder as the other number, i.e, 'v'
    }

    return u;
}

int euclid2 (int u, int v)
{
    while (u > 0 && v > 0)
    {
        if (u > v)          u = u % v;
        else                v = v % u;
    }

    if (u == 0)             return v;
    return u;
}

int main (void)
{
    int u, v;

    cin >> u >> v;

    int gcd = euclid1 (u, v);
    int hcf = euclid2 (u, v);
    cout << "GCD of " << u << " and " << v << " is : " << gcd << endl;
    cout << "HCF of " << u << " and " << v << " is : " << hcf << endl;
    return EXIT_SUCCESS;
}