// wherever shortes path is there you should think of dijkstras algorithm
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1)return -1;
        queue<pair<int,pair<int,int>>> q;
        int n=grid.size();
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        dist[0][0]=0;
        q.push({0,{0,0}});
        vector<int> delRow = {-1,-1,0,1,1,1,0,-1};
        vector<int> delCol = {0,1,1,1,0,-1,-1,-1};
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int x = it.second.first;
            int y = it.second.second;
            if(x==n-1 && y==n-1)return dis+1;
           
            
            for(int i=0;i<8;i++)
            {
                int tempx = x+delRow[i];
                int tempy = y+delCol[i];
                if(tempx>=0 && tempy>=0 && tempx<n && tempy<n && grid[tempx][tempy]==0 && dis+1 < dist[tempx][tempy])
                {
                    q.push({dis+1,{x+delRow[i],y+delCol[i]}});
                    dist[x+delRow[i]][y+delCol[i]]=dis+1;
                }
            }
        }
        return -1;
    }
};

