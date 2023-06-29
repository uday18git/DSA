// Given a weighted graph , find the single source shortest path from a vertex u to all the vertices in the graph , if the node is unreachable then return -1. in any path from u to v , the weight sould be minimum.
// Note -> The weights of the edge must be positive

// idea
// Assign a distance value to all the vertices in the input graph
// Initialize all distance value as infinity. Assign distance value as 0 for the source vertex
// while set is not empty
// A. Pick a vertex u from set s that has minimum distance value.
// B. Update distance value of all adjacent vertices of u.
#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> dist(n+1,inf);
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w}); // if it was directed then just comment this line over
    }
    int source;
    cin>>source;
    dist[source]=0;
    set<pair<int,int>> s;
    s.insert({0,source});
    while(!s.empty())
    {
        auto x=*(s.begin());
        s.erase(x);
        for(auto it:adj[x.second])
        {
            if(dist[it.first]>dist[x.second]+it.second)
            {
                s.erase({dist[it.first],it.first});
                dist[it.first]=dist[x.second]+it.second;
                s.insert({dist[it.first],it.first});
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(dist[i]<inf)
        {
            cout<<dist[i]<<" ";
        }
        else
        {
            cout<<-1<<" ";
        }
    }

    return 0;
}

// sample test case
// 4 4
// 1 2 24
// 1 4 20
// 3 1 3
// 4 3 12
// 1 
//(where to start from)
//output 0 24 3 15