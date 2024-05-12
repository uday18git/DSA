// question is to find the distance of nearest 0 for all the element and return the distance array
// so first we will traverse the whole matrix and push into the queue the 
// elements that are 0 and ill push it as 0 distance
// and i will mark them as visited
// and then on the queue i will perform bfs and keep pushing them in the
//  queue if they are valid and not visited with the dis

#include <bits/stdc++.h> 
using namespace std;
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!mat[i][j])
                {
                    q.push({{i,j},0});
                    vis[i][j]=1;
                    ans[i][j]=0;
                }
            }
        }
        while(!q.empty())
        {
            auto curr = q.front();
            q.pop();
            int delRow[] = {-1,0,1,0};
            int delCol[] = {0,1,0,-1};
            for(int i=0;i<4;i++)
            {
                int nrow = curr.first.first + delRow[i];
                int ncol = curr.first.second + delCol[i];
                int dis  = curr.second;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol])
                {
                    q.push({{nrow,ncol},dis+1});
                    vis[nrow][ncol]=1;
                    ans[nrow][ncol]=dis+1;
                }
            }
        }
        return ans;
    }
};