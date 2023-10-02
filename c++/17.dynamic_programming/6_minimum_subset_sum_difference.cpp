// minimum subset sum difference 
// abs(s1-s2) should be minimum
#include <bits/stdc++.h>
using namespace std;
vector<bool> subsetsum(vector<int> arr,int sum )
{
    int n=arr.size();
    vector<vector<bool>> dp(n+1,vector<bool>(sum+1));
    for(int i=0;i<n+1;i++)
    {
        dp[0][i]=false;
    }
    for(int i=0;i<n+1;i++)
    {
        dp[i][0]=true;
    }
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(arr[i-1]<=j)
            {
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n];
    
}
int main(){
    vector<int> arr = {1,2,7};
    int sum=0;
    int s1;
    int ans;
    for(int i=0;i<arr.size();i++)
    {
        sum+=arr[i];
    }
    vector<bool> x = subsetsum(arr,sum);
    for(int i=sum/2;i>=0;i--)
    {
        if(x[i])
        {
            s1=i;
            break;
        }
    }
    cout<<"s1 = "<<s1<<endl;
    ans=abs(sum-(2*s1));//3
    cout<<ans;//4
    // expected answer 
return 0;
}