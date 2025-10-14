#include <bits/stdc++.h>
using namespace std;

void printvec (vector<int> v)
{
    cout << "[";
    for (auto it: v)
    {
        cout << it << " ";
    }

    cout << "], ";
}

void print (vector<vector<int>> v)
{
    for (auto vec : v){
        printvec (vec);        
    }
    cout << endl;
}

vector <vector<int>> better_solution (vector <int> arr, int target)             // fails on 291st out of 294 test case (El Pain)
{
    set <vector<int>> result;
    int sz = arr.size();

    for (int i = 0; i < sz; i++)
    {
        for (int j = i + 1; j < sz; j++)
        {
            set <int> hashset;
            for (int k = j + 1; k < sz; k++)
            {
                long long int sum = arr[i] + arr[j];
                sum += arr[k];

                long long int fourth = target - (sum);

                if (hashset.find (fourth) != hashset.end())         // found
                {
                    long long fin_sum = arr[i] + arr[j] + arr[k] + fourth;

                    if (target == fin_sum)
                    {
                        vector <int> vec = {arr[i], arr[j], arr[k], (int)fourth};                    

                        sort (vec.begin(), vec.end());
                        result.insert (vec);
                    }                    
                }

                hashset.insert (arr[k]);
            }
        }
    }

    vector<vector<int>> res (result.begin(), result.end());

    return res;
}

vector <vector <int>> best_solution (vector <int> arr, int target)
{
    vector <vector <int>> result;

    sort (arr.begin(), arr.end());

    int sz = arr.size();

    for (int i = 0; i < sz; i++)
    {
        if (i > 0 && arr[i - 1] == arr[i])                  continue;

        for (int j = i + 1; j < sz; j++)
        {
            if (j > (i + 1)  && arr[j] == arr[j - 1])       continue;

            int k = j + 1;                              // low
            int l = sz - 1;                             // high

            while (k < l)
            {
                long long int sum = arr[k] + arr[l];
                sum += arr[i];
                sum += arr[j];

                if (sum == target)
                {
                    vector <int> vec = {arr[i], arr[j], arr[k], arr[l]};

                    result.emplace_back (vec);

                    l--;
                    k++;

                    while (k < l && arr[k] == arr[k - 1])       k++;
                    while (k < l && arr[l] == arr[l + 1])       l--;
                }

                else if (sum > target) 
                {
                    l--;
                }

                else
                {
                    k++;
                }
            }
        }
    }



    return result;
}


int main (void)
{
    cout << "Enter size of array : n, then the array with space, then the target k" << endl;
    int n;

    cin >> n;

    vector <int> arr (n, 0);

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        arr[i] = a;
    }

    int target;

    cin >> target;

    vector<vector <int>> result = best_solution (arr, target);

    print (result);


    return EXIT_SUCCESS;
}