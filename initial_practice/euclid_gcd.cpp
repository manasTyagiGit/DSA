#include <bits/stdc++.h>
using namespace std;

int euclid1 (int u, int v)
{
    int temp = 0;

    while (v != 0)
    {
        temp = u % v;
        u = v;
        v = temp;
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