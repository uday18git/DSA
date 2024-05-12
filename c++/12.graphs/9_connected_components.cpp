// if a graph has 4 portions which are not connected
// and we apply a traversal algorithm it will not traverse because its not connected
// so we will keep a visited array 
// this is the logic of why we use visited array

// connected component is a subgraph in which any two vertices are connected to each other by paths, 
// and which is connected to no additional vertices in the supergraph
// idea
// visit the nodes in a depth first fashion
// if the node is not visited, visit that node and its neighbour recursively
// each time a unvisited node is found , a new component will be found
// question -> find the number of connected components in a graph and its size
#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<bool> vis;
vector<vector<int>> adj;
vector<int> components;
int get_comp(int idx)
{
    if(vis[idx])
        return 0;
    vis[idx] = true;
    int ans = 1;
    for(auto i:adj[idx])
    {
        if(!vis[i])
        {
            ans+=get_comp(i);
            vis[i]=true;
        }
    }
    return ans;
}
int32_t main()
{
    cin>>n>>m;
    adj = vector<vector<int>> (n); 
    vis = vector<bool> (n); 
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            components.push_back(get_comp(i));//get comp returns the size of the component
        }
    }
    for(auto i: components){
        cout<<i<<" ";
    }
    return 0;
}
// test case
// 5 3
// 0 1
// 2 3
// 0 4