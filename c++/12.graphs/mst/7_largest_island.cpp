#include <bits/stdc++.h> 
using namespace std;
class DisjointSet {

public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n);
        // step 1 : make the connected components
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    vector<int> delRow = {-1,0,1,0};
                    vector<int> delCol = {0,1,0,-1};
                    for(int k=0;k<4;k++)
                    {
                        int newr =  i+delRow[k];
                        int newc = j+delCol[k];
                        if(newr>=0 && newr<n && newc>=0 && newc<n && grid[newr][newc]==1)
                        {
                            ds.unionBySize(newr*n+newc,i*n+j);
                        }
                    }
                }
            }
        }
        // step 2 try converting all the 0s to 1
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)continue;
                set<int> s;
                vector<int> delRow = {-1,0,1,0};
                vector<int> delCol = {0,1,0,-1};   
                for(int k=0;k<4;k++)
                {
                    int newr = i+delRow[k];
                    int newc = j+delCol[k];
                    if(newr>=0 && newr<n && newc>=0 && newc <n && grid[newr][newc]==1)
                    {
                        s.insert(ds.findUPar(newr*n+newc));
                    }
                }
                int temp=1;
                for(auto m:s)
                {
                    temp+= ds.size[m];
                }
                ans=max(ans,temp);
            }
        }
        // handling case if the whole grid is of 1's
        for(int i=0;i<n*n;i++)
        {
            ans=max(ans,ds.size[ds.findUPar(i)]);
        }
        return ans;
    }
};