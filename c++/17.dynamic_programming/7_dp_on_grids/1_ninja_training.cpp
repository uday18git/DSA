#include<bits/stdc++.h>
using namespace std;
// memoization approach partially accepted
int f(int n,int last,vector<vector<int>>points,vector<vector<int>>&dp)
{
    
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
    if(dp[n][last]!=-1)return dp[n][last];
    int maxi=0;
    for(int i=0;i<3;i++)
    {
        if(i!=last)
        {
            maxi = max(maxi,points[n][i]+f(n-1,i,points,dp));
        }
    }
    return dp[n][last]=maxi;

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



// memoized and recursive of the reverse approach like we are going from 0 to n in this appraoch , memoized of this passed all the test cases
// // lets try recursion
int solve(vector<vector<int>>&points, int last,int i)
{
    if(i==points.size())return 0;
    int ans=0;
    for(int k=0;k<3;k++)
    {
        if(k!=last)
        {
            int take = points[i][k]+solve(points,k,i+1);
            ans=max(take,ans);
        }
    }
    return ans;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    return solve(points,-1,0);
}
// time complexity O(3^n) 
//  space complexity recursion stack that is O(n)


// memoized
int solve(vector<vector<int>> &points,int last, int idx,vector<vector<int>>&dp)
{
    if(idx==points.size())return 0;
    if(dp[idx][last+1]!=-1)return dp[idx][last+1];
    int ans=0;
    for(int i=0;i<3;i++)
    {
        if(i!=last)
        {
            int take = points[idx][i] + solve(points,i,idx+1,dp);
            ans=max(take,ans);
        }
    }
    return dp[idx][last+1] = ans;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n+1,vector<int>(4,-1));
    return solve(points,-1,0,dp);   
}

// memoized time complexity is the time that it takes to fill up the dp array ,so its the same as the tabulation approach


// Each cell dp[i][last+1] in the dp array signifies the maximum points that can be obtained 
// starting from day i onward, given that the activity performed on the previous day (i-1) was last.

// i represents the current day.
// last represents the activity performed on the previous day, where -1 means no activity
// was performed the previous day (i.e., it's the starting state).
// By storing these values, the memoization avoids recalculating results for the same subproblems, improving efficiency.