// there is another more efficient soln using combinations

// m+n-2 directions to be chosen
// we have to place n-1 right paths or m-1 bottom paths

class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = m+n-2;
        int r = m-1;
        double res=1;
        for(int i=1;i<=r;i++)
        {
            res= res*(N-r+i)/i;
        }
        return int(res);

    }
    
};





// class Solution {
// public:
//     int countPaths(int i,int j,int m,int n,vector<vector<int>> &dp)
//     {
//         if(i==(m-1) && j==(n-1))return 1;
//         if(i>=m || j>=n)return 0;
//         if(dp[i][j]!=-1)
//         {
//             return dp[i][j];
//         }
//         else return dp[i][j] = countPaths(i,j+1,m,n,dp) + countPaths(i+1,j,m,n,dp);
//     }

//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m,vector<int>(n,-1));
//         return countPaths(0,0,m,n,dp);

//     }


// };

// tc - O(n*m)
// sc - O(n*m)



// exponential answer , time limit exceeded
// class Solution {
// public:
//     int countPaths(int i,int j,int m,int n)
//     {
//         if(i==(m-1) && j==(n-1))return 1;
//         if(i>=m || j>=n)return 0;
//         else return countPaths(i,j+1,m,n) + countPaths(i+1,j,m,n);
//     }
//     int uniquePaths(int m, int n) {
//         return countPaths(0,0,m,n);
        
//     }
// };