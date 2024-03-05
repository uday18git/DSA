#include <bits/stdc++.h>
using namespace std;
// memoization approach partially accepted
int solve(int n, int k, vector<int> height, vector<int> &dp)
{
    if (n == 0)
        return 0;
    if (dp[n] != INT_MAX)
        return dp[n];
    for (int i = 1; i <= k; i++)
    {
        if (n - i >= 0)
        {
            int choice = solve(n - i, k, height, dp) + abs(height[n] - height[n - i]);
            dp[n] = min(choice, dp[n]);
        }
    }
    return dp[n];
}
int minimizeCost(int n, int k, vector<int> &height)
{
    vector<int> dp(n, INT_MAX);
    return solve(n - 1, k, height, dp);
}
// tabulation , best solution
int minimizeCost(int n, int k, vector<int> &height)
{
    // Write your code here.
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                int choice = dp[i - j] + abs(height[i] - height[i - j]);
                dp[i] = min(dp[i], choice);
            }
        }
    }
    return dp[n - 1];
}