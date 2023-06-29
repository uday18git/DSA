// if there is a back edge , there is a cycle
// keep on traversing the graph
// if you found an edge pointing to an already visited node(except the parent node), a cycle is found
#include <bits/stdc++.h>
using namespace std;
//the iscycle performs a dfs traversal
            //start // adjacency list       
bool iscycle(int src,vector<vector<int>> &adj,vector<bool> &visited,int parent)
{
    visited[src]=true;
    for(auto it:adj[src])
    {
        if(it!=parent) // to avoid infinite loop with parent
        {
            if(visited[it]) // if it is visited then return true , if not visited and check again ...
                return true;
            if(!visited[it] and iscycle(it,adj,visited,src))
            {
                    return true;
            }
        }
    }
    return false;
}
int main()
{
    int n,m;cin>>n>>m;
    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++)
    {
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool cycle = false;
    vector<bool> visited(n,false);
    for(int i=0;i<n;i++)
    {
        if(!visited[i] and iscycle(i,adj,visited,-1))
        {
            cycle = true;
        }
    }
    if(cycle)
    {
        cout<<"cycle is present"<<endl;
    }
    else
    {
        cout<<"cycle is not present"<<endl;
    }
    return 0;
}
// test case
// 4 3
// 0 1
// 1 2
// 2 0
// cycle is present 