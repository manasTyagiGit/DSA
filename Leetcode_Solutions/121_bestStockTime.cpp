#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0;
        int sz = prices.size();

        int lowest = prices[0];       

        for (int i = 1; i < sz; i++)
        {
            //int cur_profit = prices[i] - lowest;

            maxP = max (prices[i] - lowest, maxP);

            lowest = min (lowest, prices[i]);
        }       

        return maxP;
    }
};