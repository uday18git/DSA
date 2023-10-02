// //coin change problem II we have to find the minimum number of coins to make a given sum using given coins
#include<bits/stdc++.h>
using namespace std;
// //memoization top down approach
// int coinChange(vector<int> coins,int sum,int n,vector<vector<int>> &dp)
// {
//     if(n==0 && sum==0)
//     {
//         return 0;
//     }
//     if (n==0)
//     {
//         return INT_MAX-1;
//     }
//     if(sum==0)
//     {
//         return 0;
//     }
//     if(dp[n][sum]!=-1)
//     {
//         return dp[n][sum];
//     }
//     else
//     {
//         if(coins[n-1]<=sum)
//         {
//             return dp[n][sum] = min(coinChange(coins,sum-coins[n-1],n,dp)+1,coinChange(coins,sum,n-1,dp));
//         }
//         else
//         {
//             return dp[n][sum] = coinChange(coins,sum,n-1,dp);
//         }
//     }
// }
// // main function for memoization
// int main(){
//     vector<int> coins = {1,2,5};
//     int sum=11;
//     int n=coins.size();
//     vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
//     cout<<coinChange(coins,sum,n,dp)<<endl;// expected answer 3
// return 0;
// }

//tabular bottom up approach
int main(){
    vector<int> coins = {1,2,5};
    int sum=11;
    int n=coins.size();
    vector<vector<int>> dp(n+1,vector<int>(sum+1));
    for(int i=0;i<sum+1;i++)
    {
        dp[0][i]= INT_MAX-1;// -1 is done to avoid overflow
    }
    for(int i=0;i<n+1;i++)
    {
        dp[i][0]=0;
    }
    dp[0][0]=0; 
    
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(coins[i-1]<=j)
            {
                dp[i][j] = min(dp[i][j-coins[i-1]]+1,dp[i-1][j]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[n][sum]<<endl;// expected answer 2
return 0;
}



// for(int i=1;i<sum+1;i++)
    // {
    //     if(i%coins[0]==0)
    //     {
    //         dp[1][i]=i/coins[0];
    //     }
    //     else
    //     {
    //         dp[1][i]=INT_MAX-1;
    //     }
    // }