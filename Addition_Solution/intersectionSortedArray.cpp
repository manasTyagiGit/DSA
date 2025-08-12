#include <bits/stdc++.h>
using namespace std;

void print (vector <int> arr)
{
    for (auto it : arr)
    {
        cout << it << "\t";

    }

    cout << endl;
}

vector <int> find_inter (vector<int>& num1, vector<int>& num2)
{
    vector <int> ret;
    int size1 = num1.size();
    int size2 = num2.size();

    int i = 0;
    int j = 0;

    vector<int> visited (size2, 0);    

    for (i = 0; i < size1; i++)
    {
        for (j = 0; j < size2; j++){
            if (num1[i] == num2[j] && visited[j] == 0)
            {
                ret.push_back (num1[i]);
                visited[j] = 1;
                break;                
            }
            if (num2[j] > num1[i])      break;
        }
    }

    return ret;
}

vector<int> find_inter_optimized (vector<int>& num1, vector <int>& num2)
{
    vector<int> ret;

    /**
     * This opitmized runs on a two pointer approach based on the fact
     * that the two input vectors/arrays are sorted,
     * so we can compare their true value/altitude with each
     * other, just like in merge sort
     */

    int i = 0;
    int j = 0;

    int size1 = num1.size();
    int size2 = num2.size();

    while (i < size1 && j < size2)
    {
        if (num1[i] == num2[j])
        {
            ret.emplace_back (num1[i]);     // matches
            i++;
            j++;
        }

        else if (num1[i] < num2[j])         // num1 < num2 at i, j
            i++;
        
        else                                // num2 < num1 at i, j
            j++;

    }

    return ret;
}

int main (void)
{
    vector <int> num1 = {21, 31, 42, 54, 71, 71, 81};
    vector <int> num2 = {11, 21, 31, 41, 41, 41, 56, 71, 71, 81, 96, 101};

    cout << "Answer should be :: 21, 31, 71, 71, 81" << endl; 

    vector <int> inter_res = find_inter (num1, num2);

    //vector<int> inter_res = find_inter_optimized (num1, num2);

    print (inter_res);

    return EXIT_SUCCESS;
}