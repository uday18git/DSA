class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        if (n == 0)
            return 0; // Edge case: No stocks to trade.

        vector<long> ahead(2, 0); // To track maximum profit one step ahead
        vector<long> cur(2, 0);   // To track current maximum profit

        // Initialize both ahead[0] and ahead[1] to 0 as the base condition
        ahead[0] = ahead[1] = 0;

        long profit;

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                if (buy == 0)
                { // We can buy the stock
                    profit = max(0 + ahead[0], -prices[ind] + ahead[1]);
                }

                if (buy == 1)
                { // We can sell the stock
                    profit = max(0 + ahead[1], prices[ind] - fee + ahead[0]);
                }
                cur[buy] = profit;
            }

            ahead = cur;
        }
        return cur[0]; // Return the maximum profit for buying.
    }
};

// class Solution {
// public:

//     int solve(int i,int buy,vector<int>prices,int fee,vector<vector<int>> &dp)
//     {
//         if(i==prices.size())return 0;
//         if(dp[i][buy]!=-1)return dp[i][buy];
//         if(buy)
//         {
//             return dp[i][buy] = max(-prices[i]+solve(i+1,0,prices,fee,dp),solve(i+1,1,prices,fee,dp));
//         }
//         else
//         {
//             return dp[i][buy] = max(-fee+prices[i]+solve(i+1,1,prices,fee,dp),solve(i+1,0,prices,fee,dp));
//         }
//     }

//     int maxProfit(vector<int>& prices, int fee) {
//         int n=prices.size();
//         vector<vector<int>> dp(n,vector<int>(2,-1));
//         return solve(0,1,prices,fee,dp);
//     }
// };