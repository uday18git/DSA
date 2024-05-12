// after one bfs for loop of four directions , one unit of time elapses
// so keep track of time elapsed
// and if we do dfs , it will go one by one so time will be very high
// minimum time is required so we go for bfs because it will spread to 4 cells at once
#include <bits/stdc++.h> 
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cntFresh=0;
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));// 0 means not visited
        // 2 means rotten , and again no need to rotten it ....
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                if(grid[i][j]==1)
                {
                    cntFresh++;
                }
            }
        }
        vector<int> delRow = {-1,0,+1,0};
        vector<int> delCol = {0,1,0,-1};
        int ans=0;
        while(!q.empty())
        {
            auto curr = q.front();
            q.pop();
            int i = curr.first.first;
            int j = curr.first.second;
            int t = curr.second;
            ans=max(t,ans);
            for(int k=0;k<4;k++) // important to not put i here
            {
                int deli = i+delRow[k];
                int delc = j+delCol[k];
                if(deli>=0 && delc>=0 && deli<n && delc<m && grid[deli][delc]==1 && vis[deli][delc]==0)
                {
                    cntFresh--;
                    q.push({{deli,delc},t+1});
                    vis[deli][delc]=2;
                }
            }
        }
        if(cntFresh!=0)return -1;
        else return ans;
    }
};


// class Solution {
// public:
//     int orangesRotting(vector<vector<int>>& grid) {
//         int n=grid.size();
//         int m=grid[0].size();
//         int cntFresh=0;
//         queue<pair<pair<int,int>,int>>q;
//         int vis[n][m];
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 if(grid[i][j]==2)
//                 {
//                     q.push({{i,j},0});
//                     vis[i][j]=2;   
//                 }
//                 else
//                 {
//                     vis[i][j]=0;
//                 }
//                 if(grid[i][j]==1)cntFresh++;
//             }
//         }
//         int tm=0,cnt=0;
//         int drow[] = {-1,0,1,0};
//         int dcol[] = {0,1,0,-1};
//         while(!q.empty())
//         {
//             int r=q.front().first.first;
//             int c=q.front().first.second;
//             int t=q.front().second;
//             tm =  max(tm,t);
//             q.pop();
//             for(int i=0;i<4;i++)
//             {
//                 int nrow = r+drow[i];
//                 int ncol = c+dcol[i];
//                 if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && grid[nrow][ncol]==1)
//                 {
//                     q.push({{nrow,ncol},t+1});
//                     vis[nrow][ncol]=2;
//                     cnt++;
//                 }
//             }
//         }
//         if(cntFresh!=cnt)return -1;
//         return tm;

//     }
// };
// class Solution {
// public:
//     void dfs(int i,int j,vector<vector<int>>&vis,int delRow[],int delCol[],vector<vector<char>> board,int n,int m)
//     {
//         vis[i][j] = 1;
//         for(int k=0;k<4;k++)
//         {
//             int nrow=i+delRow[k];
//             int ncol=j+delCol[k];
//             if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && board[nrow][ncol]=='O')
//             {
//                 dfs(nrow,ncol,vis,delRow,delCol,board,n,m);
//             }

//         }
//     }
//     void solve(vector<vector<char>>& board) {
//         int n=board.size();
//         int m=board[0].size();
//         // vector<vector<char>> ans(n,vector<char>(m,'X'));
//         vector<vector<int>> vis(n,vector<int>(m,0));
//         int delRow[] = {-1,0,1,0};
//         int delCol[] = {0,1,0,-1};
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 if((i==0 || j==0 || i==n-1 || j==m-1) && !vis[i][j] && board[i][j]=='O')
//                 {
//                     dfs(i,j,vis,delRow,delCol,board,n,m);
//                 }
//             }
//         }
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 if(!vis[i][j] && board[i][j] == 'O')
//                 {
//                     board[i][j] = 'X';
//                 }
//             }
//         }
        

//     }
// };