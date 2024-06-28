#include <bits/stdc++.h>
using namespace std;
// memoized

class Solution
{
public:
    int unique(int m, int n, vector<vector<int>> &dp)
    {
        if (m == 0 && n == 0)
            return 1;
        if (m < 0 || n < 0)
            return 0;
        if (dp[m][n] != -1)
            return dp[m][n];
        int left = unique(m - 1, n, dp);
        int up = unique(m, n - 1, dp);
        return dp[m][n] = left + up;
    }
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return unique(m - 1, n - 1, dp);
    }
};

// another way of doing , reverse..........
class Solution {
public:
    int solve(int i,int j,int m,int n)
    {
        if(i==m-1 && j==n-1)return 1;
        if(i>=m || j>=n)return 0;
        int down = solve(i+1,j,m,n);
        int right = solve(i,j+1,m,n);
        return down+right;
    }
    int uniquePaths(int m, int n) {
        return solve(0,0,m,n);
    }
};

// tabulation

class Solution {
public:
    int unique(int m,int n,vector<vector<int>>&dp)
    {
        if(m==0 && n==0)return 1;
        if(m<0 || n<0)return 0;
        if(dp[m][n]!=-1)return dp[m][n];
        int left= unique(m-1,n,dp);
        int up= unique(m,n-1,dp);
        return dp[m][n] = left+up;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        // dp[0][0]=1;
        for (int i = 0; i < m; i++) {
            dp[i][0] = 1;  // Only one way to reach cells in the leftmost column (moving down)
        }
        for (int j = 0; j < n; j++) {
            dp[0][j] = 1;  // Only one way to reach cells in the topmost row (moving right)
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];

        // return unique(m-1,n-1,dp);

    }
};