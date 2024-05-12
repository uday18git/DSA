#include<bits/stdc++.h>
using namespace std;
void dfs(int i,int j,vector<vector<int>>&vis,int delRow[],int delCol[],int n,int m,int** arr)
{
    vis[i][j]=1;
    for(int k=0;k<8;k++)
    {
        int nrow=i+delRow[k];
        int ncol=j+delCol[k];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && arr[nrow][ncol]==1)
        {
            dfs(nrow,ncol,vis,delRow,delCol,n,m,arr);
        }
    }
}
int distinctIslands(int** arr, int n, int m)
{
    //Write your code here
    int delRow[] = {-1,-1,-1,0,1,1,1,0};
    int delCol[] = {-1,0,1,1,1,0,-1,-1};
    int islands=0;
    vector<vector<int>> vis(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]==1 && vis[i][j]==0 )
            {
                islands++;
                dfs(i,j,vis,delRow,delCol,n,m,arr);
            }
        }
    }
    return islands;
}