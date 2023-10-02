// we have to print the lcs string
#include <bits/stdc++.h> 
using namespace std;
int main(){
    string x="abcdaf",y="acbcf",s;
    int n=x.size(),m=y.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<m+1;j++)
        {
            if(x[i-1]==y[j-1])
            {
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int i=n,j=m;
    while(i>0 && j>0)
    {
        if(x[i-1]==y[j-1])
        {
            s.push_back(x[i-1]);
            i--;
            j--;
        }
        else
        {
            if(dp[i-1][j]>dp[i][j-1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }
    reverse(s.begin(),s.end());
    cout<<s<<endl;

return 0;
}