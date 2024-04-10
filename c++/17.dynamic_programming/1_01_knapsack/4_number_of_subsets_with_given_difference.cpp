// number of subsets with given difference 
// same as count number of subsets with given sum
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> arr = {1,1,2,3};//ques
    int n=arr.size();
    int diff = 1;//ques
    int sum=0;
    //expected answer 3
    for(const int &i:arr)
    {
        sum+=i;
    }
    int s1 = (diff+sum)/2;
    vector<vector<int>> dp(n+1,vector<int>(s1+1));
    for(int i=0;i<n+1;i++)
    {
        dp[0][i]=0;
    }
    for(int i=0;i<s1+1;i++)
    {
        dp[i][0]=1;
    }
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<s1+1;j++)
        {
            if(arr[i-1]<=j)
            {
                dp[i][j] = dp[i-1][j-arr[i-1]]+dp[i-1][j];
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout<<dp[n][s1]<<endl;
    return 0;
}