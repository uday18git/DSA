// not accepted runtime error
#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int solve(int m,int n,vector<vector<int>>grid,vector<vector<int>>&dp)
    {
        if(m==0 && n==0)return grid[0][0];
        if(m<0 ||n <0)return 201;
        if(dp[m][n]!=-1)return dp[m][n];
        int up= grid[m][n] + solve(m-1,n,grid,dp);
        int left= grid[m][n] + solve(m,n-1,grid,dp);
        return dp[m][n] = min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,grid,dp);
    }
};


// accepted tabular approach 

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        // Initialize the first row and first column
        dp[0][0] = grid[0][0];
        for (int i = 1; i < m; ++i)
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        for (int j = 1; j < n; ++j)
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        
        // populate the  dp table
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        
        return dp[m - 1][n - 1];
    }
};

// WHEN I DID SECOND TIME

class Solution {
public:

    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        dp[0][0] = grid[0][0];
        // Initialize the first column
        for (int i = 1; i < m; i++) {
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }

        // Initialize the first row
        for (int j = 1; j < n; j++) {
            dp[0][j] = dp[0][j-1] + grid[0][j];
        }

        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                dp[i][j] = grid[i][j] + min(dp[i][j-1],dp[i-1][j]);
            }
        }
        return dp[m-1][n-1];
    }
};
// memoization
// class Solution {
// public:
//     int solve(vector<vector<int>>& grid,int m,int n,vector<vector<int>>&dp)
//     {
//         if(m==0 && n==0)return grid[m][n];
//         if(m<0 || n<0)return 20000;
//         if(dp[m][n]!=-1)return dp[m][n];
//         int up = grid[m][n]+solve(grid,m-1,n,dp);
//         int left = grid[m][n]+solve(grid,m,n-1,dp);
//         return dp[m][n] = min(left,up);
//     }
//     int minPathSum(vector<vector<int>>& grid) {
//         int m=grid.size();
//         int n=grid[0].size();
//         vector<vector<int>>dp(m,vector<int>(n,-1));
//         return solve(grid,m-1,n-1,dp);
//     }
// };


// class Solution {
// public:
//     int solve(vector<vector<int>>& grid,int m,int n)
//     {
//         if(m==0 && n==0)return grid[m][n];
//         if(m<0 || n<0)return 201;
//         int up = grid[m][n]+solve(grid,m-1,n);
//         int left = grid[m][n]+solve(grid,m,n-1);
//         return min(left,up);
//     }
//     int minPathSum(vector<vector<int>>& grid) {
//         int m=grid.size();
//         int n=grid[0].size();
//         return solve(grid,m-1,n-1);
//     }
// };