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

int main (void)
{
    vector <int> num1 = {1, 2, 2, 3, 4, 4, 5, 7};
    vector <int> num2 = {2, 3, 4, 6, 7, 8};

    cout << "Answer should be :: 2, 3, 4, 7" << endl; 

    vector <int> inter_res = find_inter (num1, num2);

    print (inter_res);

    return EXIT_SUCCESS;
}