#include <bits/stdc++.h>
using namespace std;
// const int N = 1e7+2;
// #define ll long long int
// ll dp[N];
// ll fib(ll n)
// {
//     if(n==0)
//         return 0;
//     if(n==1)
//         return 0;
//     if(n==2)
//         return 1;
//     if(dp[n]!=-1)     // we are seeing whether we have computed it already, we will not if we have , this is dp (learning from past yk)
//         return dp[n];
//     dp[n]=fib(n-1)+fib(n-2);
//     return dp[n];
// }
// int main()
// {
//     ll n ;cin>>n;
//     for(ll i=0;i<N;i++)
//     {
//         dp[i]=-1;
//     }
//     cout<<fib(n)<<endl;
//     return 0;
// }
// the above is memoization
// below is tabulation
signed main()
{
    int n;
    cin>>n;
    
    vector<int> dp(n+1);
    dp[0]=0;
    dp[1]=0;
    dp[2]=1;
    for(int i=3;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    cout<<dp[n];
}
