// -ve cycle dijkstras fails
// so bellman ford
// helps u to detect negative cycle !!!!!!!! cycle with negative weights
// only applicable in directed graph
// if you have undirected graph, change it to directed graph with two side edges with same weights

// (u1,v1,wt1)
// (u2,v2,wt2)
// (u3,v3,wt3)
// (u4,v4,wt4)
// (u5,v5,wt5)
// (u6,v6,wt6)
// (u7,v7,wt7)
// (u8,v8,wt8)
// so on.. given in any order

// relax all the edges n-1 times sequentially
// relax meaning -> if(dist[u]+wt < dist[v])dist[v]=dist[u]+wt         update it

// dist[] = {0,inf,inf,inf . . . .}
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   S: source vertex to start traversing graph with
     *   V: number of vertices
     */
    vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
    {
        vector<int> dist(V, 1e8);
        dist[S] = 0;
        for (int i = 0; i < V - 1; i++)
        {
            for (auto it : edges)
            {
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if (dist[u] != 1e8 && dist[u] + wt < dist[v])
                {
                    dist[v] = dist[u] + wt;
                }
            }
        }
        // Nth relaxation to check negative cycle
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if (dist[u] != 1e8 && dist[u] + wt < dist[v])
            {
                return {-1};
            }
        }

        return dist;
    }
};

int main()
{

    int V = 6;
    vector<vector<int>> edges(7, vector<int>(3));
    edges[0] = {3, 2, 6};
    edges[1] = {5, 3, 1};
    edges[2] = {0, 1, 5};
    edges[3] = {1, 5, -3};
    edges[4] = {1, 2, -2};
    edges[5] = {3, 4, -2};
    edges[6] = {2, 4, 3};

    int S = 0;
    Solution obj;
    vector<int> dist = obj.bellman_ford(V, edges, S);
    for (auto d : dist)
    {
        cout << d << " ";
    }
    cout << endl;

    return 0;
}