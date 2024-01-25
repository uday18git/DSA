// any graph that does not contain a odd length cycle can be bipartite
// even length cycle can be bipartite
#include <bits/stdc++.h> 
using namespace std;

class Solution {
private:
    bool dfs(int i,int col,int n,vector<int>&color,vector<vector<int>>graph)
    {
        color[i]=col;
        for(int j=0;j<graph[i].size();j++)
        {
            if(color[graph[i][j]]==-1)
            {

                if(dfs(graph[i][j],!col,n,color,graph)==false) return false;
            }
            else if(color[graph[i][j]]==col)
            {
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n=graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                if(dfs(i,0,n,color,graph)==false) return false;
            }
            
        }
        return true;
        
    }
};