#include <bits/stdc++.h> 
using namespace std;

class DisjointSet{
    public:
        vector<int> rank, parent;
        DisjointSet(int n)
        {
            rank.resize(n+1,0);
            parent.resize(n+1);
            for(int i=0;i<=n;i++)
            {
                parent[i]=i;
            }
        }
        int findUPar(int u)
        {
            if(parent[u]==u)
            {
                return u;
            }
            return parent[u] = findUPar(parent[u]);
        }
        void unionByRank(int u,int v)
        {
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);
            if(ulp_v == ulp_u)return ;
            if(rank[ulp_v] > rank[ulp_u])
            {
                parent[ulp_u] = ulp_v;
            }
            else if(rank[ulp_u]>rank[ulp_v])
            {
                parent[ulp_v] = ulp_u;
            }
            else
            {
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int maxRow =0 ; // we are finding out the max row where there is a stone
        int maxCol =0 ; // as we are not given the size of the grid , we are only given a matrix which has stone's row and column
        for(auto it:stones)
        {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        DisjointSet ds(maxRow + maxCol + 1);
        unordered_map<int,int> stoneNodes; //  this to store the nodes (rows or columns which have atleast one stone in them)
        for(auto it:stones)
        {
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1;
            ds.unionByRank(nodeRow,nodeCol);
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1; // marking in the map that there is atleast one stone in this row / col

        }
        int cnt = 0;
        for(auto it: stoneNodes)
        {
            if(ds.findUPar(it.first) == it.first)
            {
                cnt++;
            }
        }
        return n-cnt;


    }
};