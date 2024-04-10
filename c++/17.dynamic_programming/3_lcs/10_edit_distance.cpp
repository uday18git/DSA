// top down approach
// class Solution {
// public:
//     int solve(string word1,string word2,int i,int j,vector<vector<int>>&dp)
//     {
//         if(i-1 < 0)return   j; //  if i has gone left then we have to delete the rest in j
//         if(j-1 < 0)return i; // if j has gone left then we have to delete the rest in i
//         if(dp[i][j]!=-1)return dp[i][j];
//         if(word1[i-1] == word2[j-1])
//         {
//             return dp[i][j] = solve(word1,word2,i-1,j-1,dp);
//         }
//         return dp[i][j] = min(solve(word1,word2,i-1,j,dp)+1,min(solve(word1,word2,i-1,j-1,dp)+1,solve(word1,word2,i,j-1,dp)+1));
//     }
//     int minDistance(string word1, string word2) {
//         int n=word1.size();
//         int m=word2.size();
//         vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 if(i==0 || j==0)dp[i][j]=0;
//             }
//         }

//         return solve(word1,word2,n,m,dp);
//     }
// };



// class Solution {
// public:
//     int solve(string word1,string word2,int i,int j)
//     {
//         if(i-1 < 0)return j; //  if i has gone left then we have to delete the rest in j
//         if(j-1 < 0)return i; // if j has gone left then we have to delete the rest in i
//         if(word1[i-1] == word2[j-1])
//         {
//             return 0 + solve(word1,word2,i-1,j-1);
//         }
//         return min(solve(word1,word2,i-1,j)+1,min(solve(word1,word2,i-1,j-1)+1,solve(word1,word2,i,j-1)+1));
//     }
//     int minDistance(string word1, string word2) {
//         int n=word1.size();
//         int m=word2.size();
//         return solve(word1,word2,n,m);
//     }
// };