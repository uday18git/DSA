// we have to get the minimum number of partitions we should make so that all the partitions are palindrome's
// recursive code
#include <bits/stdc++.h> 
using namespace std;
bool isPalindrome(string str)
{
    int left = 0;
    int right = str.length() - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}
// int solve(string s,int i,int j)
// {
//     if(i>=j) // because empty string is palindrome and single char is also palindrome
//     {
//         return 0;
//     }
//     if(isPalindrome(s.substr(i,j-i+1)))
//     {
//         return 0;
//     }
//     int minPartitions = s.length()-1;
//     for(int k=i;k<j;k++)
//     {
//         int partitions = solve(s,i,k)+solve(s,k+1,j)+1;
//         minPartitions=min(partitions,minPartitions);
//     }
//     return minPartitions;

// }
// int main(){
//     string s = "abaa";
//     cout<<solve(s,0,s.length());
// return 0;
// }

// // top down , memoization approach


int solve(string s,int i,int j,vector<vector<int>>&dp)
{
    if(i>=j) // because empty string is palindrome and single char is also palindrome
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    if(isPalindrome(s.substr(i,j-i+1)))
    {
        return 0;
    }
    int minPartitions = s.length()-1;
    for(int k=i;k<j;k++)
    {
        int partitions = solve(s,i,k,dp)+solve(s,k+1,j,dp)+1; // here we are calling the solve functions without checking whether they are already there 
        minPartitions=min(partitions,minPartitions);
    }
    return dp[i][j] = minPartitions;

}
int main(){
    string s = "nitik";
    int n=s.length();
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1)); // make this using constraints given
    cout<<solve(s,0,s.length(),dp);
return 0;
}

// optimized memoization
// more optimzed because we are checking even before making the recursive call

int solve(string s,int i,int j,vector<vector<int>>&dp)
{
    if(i>=j) // because empty string is palindrome and single char is also palindrome
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    if(isPalindrome(s.substr(i,j-i+1)))
    {
        return 0;
    }
    int minPartitions = s.length()-1;
    for(int k=i;k<j;k++)
    {
        int left,right;
        if(dp[i][k]!=-1)
        {
            left=dp[i][k];
        }
        else
        {
            left=solve(s,i,k,dp);
            dp[i][k]=left;
        }
        if(dp[k+1][j]!=-1)
        {
            right=dp[k+1][j];
        }
        else
        {
            right = solve(s,k+1,j,dp);
            dp[k+1][j]=right;
        }
        int partitions=1+left+right;

        minPartitions=min(partitions,minPartitions);
    }
    return dp[i][j] = minPartitions;

}
int main(){
    string s = "riti";//expected ans 1
    int n=s.length();
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1)); // make this using constraints given
    cout<<solve(s,0,s.length(),dp);
return 0;
}