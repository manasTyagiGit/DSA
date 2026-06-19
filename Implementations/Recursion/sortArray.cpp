#include <bits/stdc++.h>
using namespace std;

void print(vector<int> arr){

    int len = arr.size();

    for (int i = 0; i < len - 1; i++){
        cout << arr[i] << ", ";
    }

    cout << arr[len - 1] << endl;
}

void insert (vector<int>& arr, int last){
    if (arr.empty()){
        arr.emplace_back(last);
        return;
    }

    else if(arr[arr.size() - 1] <= last){
        arr.emplace_back(last);
        return;
    }

    int temp = arr[arr.size() - 1];
    arr.pop_back();

    insert(arr, last);

    arr.emplace_back(temp);
}

void sort(vector<int>& arr){
    if(arr.empty() || arr.size() == 1)         return;

    int last = arr[arr.size() - 1];
    arr.pop_back();

    sort(arr);
    insert(arr, last);
}

int main (void){
    int n;
    cin >> n;

    vector<int> arr;
    int key = 0;

    while (n--){
        cin >> key;
        arr.emplace_back(key);
    }

    sort (arr);

    print (arr);

    return EXIT_SUCCESS;
}