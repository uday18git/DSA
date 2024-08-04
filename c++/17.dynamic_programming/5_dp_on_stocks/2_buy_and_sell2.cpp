#include <bits/stdc++.h> 
using namespace std;

// using recursion
// class Solution {
// public:
//     int solve(int i,int buy,vector<int>prices)
//     {
//         if(i==prices.size())return 0;
//         if(dp[i][buy]!=-1)return dp[i][buy];
//         if(buy)
//         {
//             return dp[i][buy] = max(-prices[i]+solve(i+1,0,prices,dp),solve(i+1,1,prices,dp));
//         }
//         else
//         {
//             return dp[i][buy] = max(prices[i]+solve(i+1,1,prices,dp),solve(i+1,0,prices,dp));
//         }
//     }
//     int maxProfit(vector<int>& prices) {
//         int n=prices.size();
//         vector<vector<int>>dp(n+1,vector<int>(2,-1));
//         return solve(0,1,prices,dp);
//     }
// };
// using recursion and memoization the code failed 

// this code passed the tabulation one 
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n=prices.size();
//         vector<vector<int>>dp(n+1,vector<int>(2,0));
//         dp[n][0] = dp[n][1]=0;
//         for(int i=n-1;i>=0;i--)
//         {
//             for(int buy=0;buy<=1;buy++)
//             {
//                 long profit=0;
//                 if(buy)
//                 {
//                     profit = max(-prices[i]+dp[i+1][0],
//                     dp[i+1][1]);
//                 }
//                 else
//                 {
//                     profit = max(prices[i]+dp[i+1][1],
//                     dp[i+1][0]);
//                 }
//                 dp[i][buy] = profit;
//             }
//         }
//         return dp[0][1];
//     }
// };

// most optimized approach
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<long> ahead(2,0),cur(2,0);
        // vector<vector<int>>dp(n+1,vector<int>(2,0));
        ahead[0] = ahead[1]=0;
        for(int i=n-1;i>=0;i--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                long profit=0;
                if(buy)
                {
                    profit = max(-prices[i]+ahead[0],
                    ahead[1]);
                }
                else
                {
                    profit = max(prices[i]+ahead[1],
                    ahead[0]);
                }
                cur[buy] = profit;
                ahead=cur;
            }
        }
        return ahead[1];
    }
};

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n=prices.size();
//         int ans=0;
//         for(int i=0;i<n-1;i++)
//         {
//             if(prices[i+1]>prices[i])
//             {
//                 ans+=(prices[i+1]-prices[i]);
//             }
//         }
//         return ans;
//     }
// };


