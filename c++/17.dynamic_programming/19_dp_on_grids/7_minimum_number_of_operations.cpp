// weekly contest 394
// minimum number of operations to satisfy conditions
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>>dp;
    int solve(int j,int keep,vector<vector<int>>&grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        if(j>=m)return 0;
        if(dp[j][keep]!=-1)return dp[j][keep];
        int minAns = INT_MAX,cost=0;
        for(int i=0;i<n;i++)
        {
            cost+=(grid[i][j]!=keep);
        }
        for(int option=0;option<=9;option++)
        {
            if(option==keep)continue;
            minAns=min(minAns,cost+solve(j+1,option,grid));
        }
        return dp[j][keep]=minAns;
    }

    int minimumOperations(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int minAns=INT_MAX;
        dp = vector<vector<int>>(m,vector<int>(10,-1));
        for(int i=0;i<=9;i++) // this value i am keeping on that column
        {
            minAns= min(minAns,solve(0,i,grid)); 
        }
        return minAns;
    }
};