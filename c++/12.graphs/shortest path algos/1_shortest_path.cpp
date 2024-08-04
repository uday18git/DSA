#include <bits/stdc++.h> 
using namespace std;
// shortest path in a undirected graph with unit weight
// single source shortest path 
// distance is 
vector<int> shortestPath(int n, vector<vector<int>>&edges, int src) {
    // Write your code here.
    queue<int> q;
    vector<int> adj[n];
    for(auto it:edges)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    vector<int> dist(n,INT_MAX);
    dist[src]=0;
    q.push(src);
    while(!q.empty())
    {
        int node  = q.front();
        q.pop();
        for(int i:adj[node])
        {
            if(dist[node]+1<dist[i])
            {
                dist[i] = dist[node]+1;
                q.push(i);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(dist[i]==INT_MAX)dist[i]=-1;
    }
    return dist;
}
