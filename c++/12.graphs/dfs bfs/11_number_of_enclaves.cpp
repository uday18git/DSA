// same as the surroundings question
// this time lets try to do it with bfs approach
#include <bits/stdc++.h> 
using namespace std;
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int boundaryOnes=0;
        int totalOnes=0;
        queue<pair<int,int>> q;
        // vector<vector<int>> vis(n,vector<int>(m,0)); i can use this but i will modify the given matrix only
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)totalOnes++;
                if((i==0 || j==0 || i==n-1 || j==m-1) && grid[i][j]==1)
                {
                    q.push({i,j});
                    grid[i][j]=0;
                    boundaryOnes++;
                }
            }
        }
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        while(!q.empty())
        {
            auto curr = q.front();
            q.pop();
            int row = curr.first;
            int col = curr.second;
            for(int k=0;k<4;k++)
            {
                int nrow=row+delRow[k];
                int ncol=col+delCol[k];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1)
                {
                    q.push({nrow,ncol});
                    grid[nrow][ncol]=0;
                    boundaryOnes++;
                }

            }
        }
        return totalOnes - boundaryOnes;
    }
};