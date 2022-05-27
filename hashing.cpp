#include <bits/stdc++.h>
using namespace std;

int pseudoHash (char a)
{
    if (a == '0')   return 0;
    return 1;
}

int trueHash (string p, int a)
{
    int hashValue = 0;
    int size = p.size();

    for (int i = 0; i < size; i++)
    {
        hashValue += (pow (a, size - (i + 1)) * pseudoHash (p[i])); 
    }

    return hashValue % 83;              // M = 83, a large prime, not near or equal to 2^i - 1, i is in Z+ 
}

int main (void)
{
    string p = "1010101";
    string m = "101";

    int a = 2;
    int indexP = trueHash (p, a);
    int indexM = trueHash (m, a);

    cout << indexP << "\t" << indexM << endl;
    return EXIT_SUCCESS;
}