#include <bits/stdc++.h>
using namespace std;

#define MAX_CHAR 26

int main (void)
{
    string inp;
    cin >> inp;

    int freq[MAX_CHAR] = {0};
    
    int len = size(inp);

    for (int i = 0; i < len; i++)
    {
        freq[inp[i] - 97]++;
    }
    
    int q;

    cin >> q;

    while (q--)
    {
        char c;
        cin >> c;

        cout << c << " : " << freq[c - 97] << endl;
    }
    return EXIT_SUCCESS;
}