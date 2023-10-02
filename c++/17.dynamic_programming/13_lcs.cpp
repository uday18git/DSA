// lcs meaning longest common subsequence -> it is the longest subsequence which is common in both the strings
// return the length of the longest  common subsequence
// recursive code
#include <bits/stdc++.h> 
using namespace std;
int lcs(string x, string y,int n,int m)
{
    if(m==0 || n==0)
    {
        return 0;
    }
    if(x[n-1]==y[m-1])
    {
        return 1+lcs(x,y,n-1,m-1);
    }
    else
    {
        return max(lcs(x,y,n-1,m),lcs(x,y,n,m-1));
    }
}
int main(){
    cout<<lcs("abcdgh","abedfh",6,6)<<endl; // expected answer 4
return 0;
}

// memoized version (top down approach)
int lcs(string x,string y,int n,int m,vector<vector<int>>&dp)
{
    if( n==0 || m==0)
    {
        return 0;
    }
    if(dp[n][m]!=-1)
    {
        return dp[n][m];
    }
    else
    {
        if(x[n-1]==y[m-1])
        {
            return dp[m][n] = 1+ lcs(x,y,n-1,m-1,dp);
        }
        else
        {
            return dp[m][n] = max(lcs(x,y,n,m-1,dp),lcs(x,y,n-1,m,dp));
        }
    }
}
int main()
{
    string x = "abcdgh",y = "abedfh";
    int n=6,m=6;
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    cout<<lcs(x,y,n,m,dp)<<endl; // expected answer 4
    return 0;
}

// bottom up approach
int main()
{
    string x = "abcdgh",y = "abedfh";
    int n=6,m=6;
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<m+1;j++)
        {
            if(x[i-1]==y[j-1])
            {
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<<dp[n][m]<<endl;
}
