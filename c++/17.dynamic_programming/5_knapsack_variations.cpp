// variations of knapsack
// Subset sum problem
// Equal sum partition
// count of subset sum
// minimum subset sum diff
// target sum
// # of subset in given difference
// identification
// if there are given some - - - - - - - items(for which there is a choice of taking or not taking) and a max weight of W or smtg like this
// subset sum problem
// arr[] = 2,3,7,8,10
// sum = 11
// so here we can see that for all elements we can take or not take like that
#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int sum=11;
    vector<int> arr = {2,3,7,8,10};
    int n=arr.size();
    vector<vector<bool>> dp(n+1,vector<bool>(sum+1));
    for(int i=0;i<n+1;i++)
    {
        //initialisation
        for(int j=0;j<sum+1;j++)
        {
            if(i==0)
            {
                dp[i][j]=false;
            }
            if(j==0)
            {
                dp[i][j]=true;
            }
        }
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
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout<<dp[4][11];


    return 0;
}

// equal sum partition
// an array will be given {1,5,11,1}
// we have to return true or false whether this array can be divided into two subsets where sum of both subsets are same
int main()
{
    vector<int> arr = {2,5,11,5};
    int sum=0;
    bool ans;
    int n = arr.size();
    for(int i=0;i<arr.size();i++)
    {
        sum+=arr[i];
    }
    if(sum%2!=0)
    {
        ans=false;
    }   
    else
    {
        vector<vector<bool>> dp(n+1,vector<bool>(sum/2 + 1));
        sum/=2;
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<sum+1;j++)
            {
                if(i==0)
                {
                    dp[i][j] = false;
                }
                if(j==0)
                {
                    dp[i][j]=true;
                }
            }
        }
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<sum+1;j++)
            {
                if(arr[i-1]<=j) // if the element is less than the required sum then only there is a possiblity to add it right
                {
                    dp[i][j]= dp[i-1][j-arr[i-1]] || dp[i-1][j];
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        ans = dp[n][sum];


    }
    cout<<ans;
}

// count of subsets with a given sum
// arr[] = {2,3,5,8,10}
int main()
{
    vector<int> arr = {2,3,5,8,10};
    int sum = 10;
    int n=arr.size();
    vector<vector<int>> dp(n+1,vector<int> (sum+1));
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(i==0)
            {
                dp[i][j] = 0;
            }
            if(j==0)
            {
                dp[i][j]=1;
            }
        }
    }
    for(int i=0;i<n+1;i++)
    {
        dp[0][i]=0;
    }
    for(int i=0;i<sum+1;i++)
    {
        dp[i][0]=1;
    }
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(arr[i-1]<=j)
            {
                dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];
            }
            else
            {
                dp[i][j] = dp[i-1][j] ;
            }
        }

    }
    cout<<dp[n][sum]<<endl;

}