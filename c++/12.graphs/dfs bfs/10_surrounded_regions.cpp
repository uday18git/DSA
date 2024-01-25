// replace 0's with X's
// logic is that when a group of 0 is not connected to any border
// it is bound to get converted to X
// so start from boundary zeros and mark them that they wont be converted, convert rest of them
#include <bits/stdc++.h> 
using namespace std;
class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>&vis,int delRow[],int delCol[],vector<vector<char>> board,int n,int m)
    {
        vis[i][j] = 1;
        for(int k=0;k<4;k++)
        {
            int nrow=i+delRow[k];
            int ncol=j+delCol[k];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && board[nrow][ncol]=='O')
            {
                dfs(nrow,ncol,vis,delRow,delCol,board,n,m);
            }

        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        // vector<vector<char>> ans(n,vector<char>(m,'X'));
        vector<vector<int>> vis(n,vector<int>(m,0));
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if((i==0 || j==0 || i==n-1 || j==m-1) && !vis[i][j] && board[i][j]=='O')
                {
                    dfs(i,j,vis,delRow,delCol,board,n,m);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
        }
        

    }
};

// tc->O(n*m)
// sc->O(N*M)