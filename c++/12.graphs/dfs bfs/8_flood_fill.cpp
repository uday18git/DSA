// here time doesnt matter , we just have to flood fill it 
// we are using dfs below , just call dfs on sr sc
// for loop will be over the 4 neighbors in the dfs
#include <bits/stdc++.h> 
using namespace std;
class Solution {
public:
    void dfs(int row, int col,vector<vector<int>>& ans,vector<vector<int>>&image,int newColor,
    int delRow[],int delCol[],int iniColor)
    {
        int n=image.size();
        int m=image[0].size();
        ans[row][col] = newColor;
        for(int i=0;i<4;i++)
        {
            int nrow = row+delRow[i];
            int ncol = col+delCol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==iniColor && ans[nrow][ncol]!=newColor)
            {
                dfs(nrow,ncol,ans,image,newColor,delRow,delCol,iniColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor = image[sr][sc];
        vector<vector<int>> ans = image;
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        dfs(sr,sc,ans,image,color,delRow,delCol,iniColor);
        return ans;
    }
};