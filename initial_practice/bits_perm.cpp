#include <bits/stdc++.h>
using namespace std;


int main (void)
{
    int x = 213112;
    int cnt = __builtin_popcount(x);

    cout << "Number of bits set to 1 in binary of " << x << " are : " << cnt << endl;

    string s = "1234";              // always use a sorted string here, else it might not give correct output

    do {
        cout << s << endl;
    }
    while (next_permutation(s.begin(), s.end()));

    return EXIT_SUCCESS;
}