#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int i, int buy, vector<int> prices, vector<vector<int>> &dp)
    {
        if (i >= prices.size())
        {
            return 0;
        }
        if (dp[i][buy] != -1)
            return dp[i][buy];
        if (buy)
        {
            return dp[i][buy] = max(-prices[i] + solve(i + 1, 0, prices, dp), solve(i + 1, 1, prices, dp));
        }
        else
        { // changed from i+1 to i+2 (COOLDOWN)
            return dp[i][buy] = max(prices[i] + solve(i + 2, 1, prices, dp), solve(i + 1, 0, prices, dp));
        }
    }
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        return solve(0, 1, prices, dp);
    }
};