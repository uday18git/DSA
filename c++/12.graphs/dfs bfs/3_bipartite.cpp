// any graph that does not contain a odd length cycle can be bipartite
// even length cycle can be bipartite
#include <bits/stdc++.h> 
using namespace std;
class Solution {
private:
    bool dfs(int i,int col,int n,vector<int>&color,vector<vector<int>>graph)
    {
        color[i]=col; // color the node
        for(int j=0;j<graph[i].size();j++) // check all adjacent of the node
        {
            if(color[graph[i][j]]==-1) // if not yet colored , color it the opposite color , and if that returns fasle , we have to reutnr false
            {
                if(dfs(graph[i][j],!col,n,color,graph)==false) return false; // if any of neighbors gives false then returnn false
            }
            else if(color[graph[i][j]]==col) // if colored and same color then we have to return false
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
            if(color[i]==-1) // the graph may not be connected so 
            {
                if(dfs(i,0,n,color,graph)==false) return false;
            }
        }
        return true;
        
    }
};