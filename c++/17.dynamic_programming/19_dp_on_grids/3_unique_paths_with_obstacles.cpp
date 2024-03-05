// accepted on leet code

#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int unique(int m,int n, vector<vector<int>>grid,vector<vector<int>>&dp)
    {
        if(m==0 && n==0)return 1;
        if(m<0 || n<0)return 0;
        // difference that we check for obstacle that is it
        if(grid[m][n]==1)return 0;
        if(dp[m][n]!=-1)return dp[m][n];
        int up = unique(m-1,n,grid,dp);
        int left = unique(m,n-1,grid,dp);
        return dp[m][n] = up+left;

    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]==1)return 0;
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return unique(m-1,n-1,obstacleGrid,dp);
    }
};