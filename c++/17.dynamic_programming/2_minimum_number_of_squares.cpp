// given a number tell minimum number of squares whose sum equals to the given number
// take 26 -> 4^2 + 3^2 + 1
// also  -> 25+ 1 right so answer is 2
// f(x) = min(f(x- i*i) +1)
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+2,MOD = 1e9;
// without memoization
// int minSquare(int n)
// {
//     if(n==0 || n==1 || n==2 || n==3 )
//         return n;
//     int ans=MOD;
//     for(int i=1;i*i<=n;i++)
//     {
//         ans=min(ans,minSquare(n-(i*i))+1);
//     }
//     return ans;
// }
// using memoization
// vector<int> dp(N,MOD);
// int minSquare(int n)
// {
//     if(n==0 || n==1 || n==2 || n==3 )
//         return n;

//     if(dp[n]!=MOD)
//     {
//         return dp[n];
//     }
//     for(int i=1;i*i<=n;i++)
//     {
//         dp[n]=min(dp[n],minSquare(n-(i*i))+1);
//     }
//     return dp[n];
// }
// int main()
// {
//     int n;cin>>n;
//     cout<<minSquare(n)<<endl;
//     return 0;
// }
// using bottom up
int main()
{
    int n;cin>>n;
    vector<int> dp(n+1,MOD);
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    dp[3]=3;
    for(int i=1;i*i<=n;i++)
    {
        for(int j=0;i*i+j<=n;j++)
        {
            dp[i*i+j]=min(dp[i*i+j],1+dp[j]);
        }
    }
    cout<<dp[n]<<endl;
}