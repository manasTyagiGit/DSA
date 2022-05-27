#include <bits/stdc++.h>
using namespace std;

vector <int> checkSubstring (string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();

    int a = 256;        // number of characters in our charset
    int q = 101;        // the prime number we divide the true hash value with

    int hashWindow = 0, hashS2 = 0;
    int i, j;
    int base = 1;

    vector <int> indices;

    for (i = 0; i < m - 1; i++)
    {
        base = (base * a) % q;
    }
    for (i = 0; i < m; i++)
    {
        hashWindow = ((a * hashWindow)  + s1[i]) % q;
        hashS2     = ((a * hashS2)  + s2[i]) % q;
    }

    for (i = 0; i <= n - m; i++)
    { 
        if (hashWindow == hashS2)
        {  
            bool flag = true;
            j = 0;

            while (j < m)
            {
                if (s1[i + j] != s2[j])
                {
                    flag = false;
                    break;
                }                 
                j = j + 1;                                             
            } 
            if (flag)   indices.push_back (i);                      
        }
 
        if (i <= (n - m))
        {
            hashWindow = (a * (hashWindow - s1[i] * base) + s1[i + m]) % q;
            if (hashWindow < 0)
            {
                hashWindow = hashWindow + q;
            }
        }
    }
    return indices;
}

int main (void)
{
    string s1, s2;
    cin >> s1 >> s2;

    vector <int> indices = checkSubstring (s1, s2);

    if (indices.size() > 0)
    {
        for (int i = 0; i < indices.size(); i++)     cout << indices[i] << " ";
    }

    else
    {
        cout << "NOT FOUND ANYWHERE";
    }
    cout << endl;
    return EXIT_SUCCESS;
}

