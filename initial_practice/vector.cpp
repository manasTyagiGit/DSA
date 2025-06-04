#include <bits/stdc++.h>
using namespace std;

// Maintained as an SLL, and akin to dynamically-sized array

int main (void)
{
    vector <int> v1; 
    v1.push_back (0);
    v1.emplace_back (1);        //faster, but same usage

    cout << v1[0] << " " << v1[1] << endl;

    vector <pair <int, int>> vector_pair;
    vector_pair.push_back ({1, 2});
    vector_pair.emplace_back (3, 4);            //slight difference here, otherwise error

    cout << vector_pair[0].first << vector_pair[0].second 
    << " " << vector_pair[1].first << vector_pair[1].second << endl;

    vector <int> v2 (10, 100);          //10 = size, 100 = value at all indices

    for (int i = 0; i < 10; i++){
        cout << v2[i] << "\t";
    }
    cout << endl;

    vector <int> v3 (7);                // 7 = size, all entries = 0

    for (int i = 0; i < 7; i++){
        cout << v3.at(i) << "\t";
    }

    vector <int> v4 (v2);               // copies contents from v2 to v4, but different reference

    cout << endl;
    return EXIT_SUCCESS;
}