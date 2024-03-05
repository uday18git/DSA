//coin change problem I we have to find the number of ways to make a given sum using given coins
// similar to the count number of subset sum problem, and unbounded knapsack version of it
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> coins = {1,2,3};
    int sum=5;
    int n=coins.size();
    vector<vector<int>> dp(n+1,vector<int>(sum+1));
    for(int i =0;i<sum+1;i++)
    {
        dp[0][i] = 0;
    }
    
    for(int i =0;i<n+1;i++)
    {
        dp[i][0] = 1;
    }
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(coins[i-1]<=j)
            {
                dp[i][j]=dp[i][j-coins[i-1]]+dp[i-1][j];
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[n][sum];//expected 5

    return 0;
}
