// dijkstras shortest path
// undirected weighted graph
// from source node to all nodes what is the shortest distance u can reach there
// using pq
// min heap datastructure, shorter will be at the top
// we will store {dist,node}
// make a distance array , put source as 0 and rest as infinity
// put {0,0} is the pq
// then remove it and see where 0 can go
// add those to pq and update distance array if it is better distance




#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &edge, int vertices, int edges, int source)
{
    // 'edge' contains {u, v, distance} vectors.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(vertices, 1e9);
    vector<vector<pair<int, int>>> adj(vertices);

    for (int i = 0; i < edge.size(); i++)
    {
        adj[edge[i][0]].push_back({edge[i][1], edge[i][2]});
        adj[edge[i][1]].push_back({edge[i][0], edge[i][2]});
    }

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty())
    {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : adj[node])
        {
            int adjNode = it.first;
            int edgeWeight = it.second;

            if (dis + edgeWeight < dist[adjNode])
            {
                dist[adjNode] = dis + edgeWeight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    return dist;
}

// why it doesnt work for negative weights , because the while loop which is there will go for a  infinite loop 
// it will go for ever and decrease weights so...
// time complexity -> ELOGV number of edges and number of nodes is V

