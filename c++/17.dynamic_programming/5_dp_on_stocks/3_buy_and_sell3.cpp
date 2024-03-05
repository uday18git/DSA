// space optimization most optimized code
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> ahead(2, vector<int>(3, 0));
        vector<vector<int>> cur(2, vector<int>(3, 0));
        // vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        // Base case: dp array is already initialized to 0, covering the base case.
        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int cap = 1; cap <= 2; cap++)
                {
                    if (buy == 0)
                    { // We can buy the stock
                        cur[buy][cap] = max(0 + ahead[0][cap],
                                            -prices[ind] + ahead[1][cap]);
                    }

                    if (buy == 1)
                    { // We can sell the stock
                        cur[buy][cap] = max(0 + ahead[1][cap],
                                            prices[ind] + ahead[0][cap - 1]);
                    }
                }
            }
            ahead = cur;
        }

        // The result is stored in dp[0][0][2] which represents maximum profit after the final transaction.
        return ahead[0][2];
    }
};
// tabular passes all test cases
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n=prices.size();
//         vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
//         // Base case: dp array is already initialized to 0, covering the base case.
//         for (int ind = n - 1; ind >= 0; ind--) {
//             for (int buy = 0; buy <= 1; buy++) {
//                 for (int cap = 1; cap <= 2; cap++) {
//                     if (buy == 0) { // We can buy the stock
//                         dp[ind][buy][cap] = max(0 + dp[ind + 1][0][cap],
//                                             -prices[ind] + dp[ind + 1][1][cap]);
//                     }

//                     if (buy == 1) { // We can sell the stock
//                         dp[ind][buy][cap] = max(0 + dp[ind + 1][1][cap],
//                                             prices[ind] + dp[ind + 1][0][cap - 1]);
//                     }
//                 }
//             }
//         }

//         // The result is stored in dp[0][0][2] which represents maximum profit after the final transaction.
//         return dp[0][0][2];
//     }
// };

// memoized
// 3D DP
// passes 202/214
// class Solution {
// public:
//     int solve(int i,int buy,int cap,vector<int>prices,vector<vector<vector<int>>>&dp)
//     {
//         if(cap==0)return 0;
//         if(i==prices.size())return 0;
//         if(dp[i][buy][cap]!=-1)return dp[i][buy][cap];
//         long profit=0;
//         if(buy)
//         {
//             profit= max(-prices[i]+solve(i+1,0,cap,prices,dp) , solve(i+1,1,cap,prices,dp));
//         }
//         else
//         {
//             profit = max(prices[i] + solve(i+1,1,cap-1,prices,dp),solve(i+1,0,cap,prices,dp));
//         }
//         return dp[i][buy][cap] = profit;
//     }
//     int maxProfit(vector<int>& prices) {
//         int n=prices.size();
//         vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));

//         return solve(0,1,2,prices,dp);
//     }
// };

// recursive soln passes 201 / 214 testcases

// class Solution {
// public:
//     int solve(int i,int buy,int cap,vector<int>prices)
//     {
//         if(cap==0)return 0;
//         if(i==prices.size())return 0;
//         long profit=0;
//         if(buy)
//         {
//             profit= max(-prices[i]+solve(i+1,0,cap,prices) , solve(i+1,1,cap,prices));
//         }
//         else
//         {
//             profit = max(prices[i] + solve(i+1,1,cap-1,prices),solve(i+1,0,cap,prices));
//         }
//         return profit;
//     }
//     int maxProfit(vector<int>& prices) {

//         return solve(0,1,2,prices);
//     }
// };

// ANOTHER APPROACH IS THERE WHERE WE TAKE TRANSACTION NUMBER AND KIND OF MERGE THE BUY AND CAP INTO SINGLE VARIABLE
// 1 2 3 4 ... AND IF IT IS ODD THEN IT IS A BUY AND IF IT IS A EVEN THEN IT IS A SELL
