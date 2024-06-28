#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            if(obstacleGrid[0][i])
            {
                break;
            }
            else
            {
                dp[0][i]=1;
            }
        }
        for(int i=0;i<m;i++)
        {
            if(obstacleGrid[i][0])
            {
                break;
            }
            else
            {
                dp[i][0]=1;
            }
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(obstacleGrid[i][j])
                {
                    dp[i][j] = 0;
                }
                else
                {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};


// memoization

class Solution {
public:
    int solve(int m,int n,vector<vector<int>>& obstacleGrid, vector<vector<int>> &dp)
    {
        if(m<0 || n<0 || obstacleGrid[m][n])return 0;
        if(m==0 && n==0)return 1;
        if(dp[m][n]!=-1)return dp[m][n];
        int top = solve(m-1,n,obstacleGrid,dp);
        int left = solve(m,n-1,obstacleGrid,dp);
        return dp[m][n] = top+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,obstacleGrid,dp);
    }
};
// plain recursion
class Solution {
public:
    int solve(int m,int n,vector<vector<int>>& obstacleGrid)
    {
        if(m<0 || n<0 || obstacleGrid[m][n])return 0;
        if(m==0 && n==0)return 1;
        int top = solve(m-1,n,obstacleGrid);
        int left = solve(m,n-1,obstacleGrid);
        return top+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        return solve(m-1,n-1,obstacleGrid);
    }
};