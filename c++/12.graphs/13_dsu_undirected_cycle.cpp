// first take any edge.. check parents , if they are from different set then do union else, cycle is found because, take a polygon start from any edge if you traverse all the edges the last edge will be the same sets so there cycle is found

// Pseudocode
// for all edges(u,v) in edges:
//  x=find_set(u);
//  y=find_set(v);
//  if(x==y)
//  {
//        // same set, cycle is found
//      return true
//  }
//  union(u,v)
// return false

#include <bits/stdc++.h>
using namespace std;
const int N=1e5+2;
vector<int> parent(N);
vector<int> sz(N);
void make_set(int v)
{
    parent[v]=v;
    sz[v]=1;
}
int find_set(int v)
{
    if(v==parent[v])
    {
        return v;
    }
    return parent[v]=find_set(parent[v]);
}
void union_sets(int a,int b)// we are using dsu by size/rank.
{
    a = find_set(a);
    b = find_set(b);
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

    int n,m;cin>>n>>m;
    // vector<vector<int>> adj(n);
    vector<vector<int>> edges;
    
    for(int i=0;i<m;i++)
    {
        int u,v;cin>>u>>v;
        edges.push_back({u,v});
        
    }
    bool cycle = false;
    for(auto i:edges)
    {
        int u=i[0];
        int v=i[1];
        int x = find_set(u);
        int y = find_set(v);
        if(x==y)
        {
            cycle = true;
        }
        else
        {
            union_sets(u,v);
        }
    }
    if(cycle)
        cout<<"Cycle is present"<<endl;
    else
        cout<<"No cycle"<<endl;
    return 0;
}