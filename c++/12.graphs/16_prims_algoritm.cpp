// idea
// select an arbitrary vertex s to start the tree from
// while (there are still nontree vertices)
// Select the edge of minimum weight between a tree and nontree vertex.
// Add the selected edge and vertex to the tree

// Prim's algorithm is a greedy algorithm used to find a minimum spanning tree in a connected weighted graph. Here's an outline of the algorithm:
#include <bits/stdc++.h>
using namespace std;
int n, m;
const int N = 1e5 + 3;
const int INF = 1e9;
int cost = 0;
vector<bool> vis(N);
vector<int> parent(N), dist(N);
vector<vector<int>> adj[N];
void primsMST(int source)
{
    for (int i = 0; i < n; i++)
    {
        dist[i] = INF;
    }
    dist[source] = 0;
    set<vector<int>> s;
    s.insert({0, source});
    while (!s.empty())
    {
        auto x = *(s.begin());
        s.erase(x);
        vis[x[1]]=true;
        int u=x[1];
        int v=parent[x[1]];
        int w=x[0];
        cout<<u<<" "<<v<<" "<<w<<endl;
        cost+=w;
        for(auto it:adj[x[1]])
        {
            if(vis[it[0]])
            {
                continue;
            }
            if(dist[it[0]]>it[1])
            {
                s.erase({dist[it[0]],it[0]});
                dist[it[0]]=it[1];
                s.insert({dist[it[0]],it[0]});
                parent[it[0]]=x[1];
            }
        }
    }
}
int main()
{

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    primsMST(0);
    cout << cost;

    return 0;
}
//test case
// 4 5
// 0 1 10
// 1 2 15
// 0 2 5
// 3 1 2
// 3 2 40
// 0 0 0
// 2 0 5
// 1 0 10
// 3 1 2
// 17