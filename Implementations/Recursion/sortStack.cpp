#include <bits/stdc++.h>
using namespace std;

void print (stack<int> s){
    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }
}

void insert (stack<int>& s, int top){
    if(s.empty() || s.top() >= top){
        s.push(top);
        return;
    }

    int temp = s.top();
    s.pop();

    insert(s, top);
    s.push(temp);
}

void sort(stack<int>& s){
    if (s.empty())              return;
    if (s.size() == 1)          return;

    int top = s.top();
    s.pop();

    sort(s);
    insert(s, top);
}


int main(void){
    int n;
    cin >> n;
    int key = 0;

    stack<int> s;

    for (int i = 0; i < n; i++){
        cin >> key;
        s.push(key);
    }

    sort(s);
    print(s);

    return EXIT_SUCCESS;
}