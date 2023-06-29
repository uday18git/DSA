// SPANNING TREE (all vertices should be there and it should be subgraph )
// Given an undirected and connected graph (A graph is said to be connected if there is atleast one path between every pair of vertices)
// G(V,E), a spanning tree of the graph G is a tree that spans G (that is , it inlcudes every vertex of G) and is a subgraph of G
//(every edge in the tree belong to G).

// The cost of the spanning tree in the sum of the weights of all the edges in the tree
// There can be many spanning trees

// Minimum spanning tree -> The spanning tree which has the least cost among all the spanning trees

// Kruskal  algorithm (Used to find out the minimum spanning tree of a graph)

// we use disjoint set union to do this

// PseudoCode
// 1.Sort the edges based on there weights.
// 2. Iterate in the sorted edges,
//    If inclusion of i'th edge leads to a cycle, then skip this edge
//    Else
//    Include the edge in the MST

// Sorted Edges(w,u,v) : {1,5,8}, {1,8,7}, {2,4,3},{5,1,2},{5,3,5},{6,

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+2;
vector<int> sz(N);
vector<int> parent(N);
void make_set(int v)
{
    parent[v]=v;
    sz[v]=1;
}
int find_set(int v)
{
    if(parent[v]==v)
    {
        return v;
    }
    return parent[v]=find_set(parent[v]);
}
void union_sets(int a,int b)
{
    a=find_set(a);
    b=find_set(b);

    if(a!=b)
    {
        if(sz[a]<sz[b])
        {
            swap(a,b);
        }
        parent[b]=a;
        sz[a]+=sz[b];
    }
}

int main()
{
    for(int i=0;i<N;i++)
    {
        make_set(i);
    }
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>v>>u>>w;
        edges.push_back({w,u,v});
    }
    sort(edges.begin(),edges.end());
    int cost=0;
    for(auto i: edges)
    {
        int w=i[0];
        int u=i[1];
        int v=i[2];
        int x = find_set(u); 
        int y = find_set(v); 
        if(x==y)
        {
            continue; //here cycle is getting created so skip
        }
        else
        {
            cout<<u<<" "<<v<<"\n";
            cost+=w;
            union_sets(u,v);
        }
        cout<<cost;
    }
    return 0;
}

// sample test case
// 8 9
// 1 2 5
// 2 3 6
// 4 3 2
// 1 4 9
// 3 5 5
// 5 6 10
// 6 7 7
// 7 8 1
// 8 5 1