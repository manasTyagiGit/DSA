#include <bits/stdc++.h>
using namespace std;

void print_all_subsets(string ip, string op){
    if (ip.size() == 0){
        if (op.size() == 0){
            cout << "empty ";
        }

        else{
            cout << op << " ";
        }

        return;
    }

    string op1 = op;    // not taking the element at decision
    string op2 = op;    // taking the element at decision
    op2.push_back(ip[0]);

    ip.erase(ip.begin() + 0);

    print_all_subsets(ip, op1);
    print_all_subsets(ip, op2);
}

int main (void){
    string n;
    cout << "enter your string :: " ;
    cin >> n;

    cout << "All subsets of " << n << " are :: ";
    print_all_subsets (n, "");

    return EXIT_SUCCESS;
}