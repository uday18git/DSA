#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> dif(n,vector<int>(m,INT_MAX));
        dif[0][0]=0;
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int x = it.second.first;
            int y = it.second.second;
            int abs1 = it.first;
            if(x==n-1 && y==m-1)return abs1;
            for(int i=0;i<4;i++)
            {
                int tempx = x+delRow[i];
                int tempy = y+delCol[i];
               
                if(tempx>=0 && tempy>=0 && tempx<n && tempy<m && dif[tempx][tempy]>max(abs(heights[x][y] - heights[tempx][tempy]),dif[x][y])) // didnt understand last && condition completely
                {
                    int curr = abs(heights[x][y] - heights[tempx][tempy]);
                    dif[tempx][tempy] = max(curr,dif[x][y]);
                    pq.push({dif[tempx][tempy],{tempx,tempy}});
                }
            }
        }
        return 0;
    }
};

// ELOGV