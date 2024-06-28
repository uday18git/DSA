#include <bits/stdc++.h> 
using namespace std;

int solve(vector<vector<int>>&points,int last, int i,vector<vector<int>>&dp)
{
    if(i==points.size())
    {
        return 0;
    }
    if(dp[i][last+1]!=-1)return dp[i][last+1];
    int ans=0;
    for(int k=0;k<3;k++)
    {
        if(k!=last)
        {
            int take = points[i][k] + solve(points,k,i+1,dp);
            ans=max(ans,take);
        }
    }
    return dp[i][last+1]=ans;
}

void ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n,vector<int>(3,-1));
    int lmao = solve(points,-1,0,dp);
    // print the dp array 
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl; 
    cout<<lmao<<endl;
    
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> points(n,vector<int>(3));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>points[i][j];
        }
    }
    ninjaTraining(n,points);
    // print the dp array 

return 0;
}