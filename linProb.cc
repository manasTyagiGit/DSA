#include <bits/stdc++.h>
using namespace std;

int pseudoHash (char a)
{
    if (a == '0')   return 0;
    return 1;
}

int trueHash (string p, int a, int M)
{
    int hashValue = 0;
    int size = p.size();

    for (int i = 0; i < size; i++)
    {
        hashValue += (pow (a, size - (i + 1)) * pseudoHash (p[i])); 
    }

    return hashValue % M;              // M = 83, a large prime, not near or equal to 2^i - 1, i is in Z+     
}

void fitIntoHash (string* arr, int index, int size, string x)
{
    if (arr[index].empty())
    {
        arr[index] = x;
    }

    else
    {
        fitIntoHash (arr, index + 1, size, x);
    }   
}

void printHashVals (string* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << i << " :: "<< arr[i] << " " << endl;
    }
}

int main (void)
{
    string p = "1010101";
    string m = "101";
    int M = 83;

    int a = 2;
    int indexP = trueHash (p, a, M);
    int indexM = trueHash (m, a, M);
    
    string arr[M];    

    fitIntoHash (arr, indexP, M, p);
    fitIntoHash (arr, indexM, M, m);

    printHashVals (arr, M);
    
    return EXIT_SUCCESS;
}