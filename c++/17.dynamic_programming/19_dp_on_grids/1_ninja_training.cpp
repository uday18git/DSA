#include<bits/stdc++.h>
using namespace std;
// memoization approach partially accepted
int f(int n,int last,vector<vector<int>>points,vector<vector<int>>&dp)
{
    if(dp[n][last]!=-1)return dp[n][last];
    if(n==0)
    {
        int maxi=0;
        for(int i=0;i<3;i++)
        {
            if(i!=last)
            {
                maxi = max(points[n][i],maxi);
            }
        }
        return dp[n][last]=maxi;
    }
    int maxi=0;
    for(int i=0;i<3;i++)
    {
        if(i!=last)
        {
            maxi = max(maxi,points[n][i]+f(n-1,i,points,dp));
        }
    }
    return dp[n][last]=  maxi;

}


int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>>dp(n,vector<int>(4,-1));
    

    return f(n-1,3,points,dp);
}


// tabulation approach , accepted
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>>dp(n,vector<int>(4,0));

    dp[0][0] = max(points[0][1],points[0][2]);
    dp[0][1] = max(points[0][0],points[0][2]);
    dp[0][2] = max(points[0][1],points[0][0]);
    dp[0][3] = max(points[0][1],max(points[0][0],points[0][2]));

    for(int i=1;i<n;i++)
    {
        for(int last=0;last<=3;last++)
        {
            for(int task=0;task<=2;task++)
            {
                if(task!=last)
                {
                    dp[i][last] = max(dp[i][last],points[i][task] + dp[i-1][task]);
                }
            }
        }
    }
    return dp[n-1][3];
}