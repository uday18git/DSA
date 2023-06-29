// bipartite graph imp!!!!
// its vertices can be divided into two disjiont and independent set U and V such that every edge connects a vertex in U to one in V;
// The graph does not contain any odd length cycles
// The graph is 2 colorable
// weird questions will come on this

// Traverse the graph
// if the current node is of red color, paint its neighbours as blue
// If you are able to color the graph successfully , then the graph is bipartite
#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> vis;
vector<vector<int>> adj;
vector<int> col;
bool bipartite=true;
void color(int idx, int clr)
{
    if(col[idx]!=-1 && clr!=col[idx])
    {
        bipartite=false;
        return;
    }
    col[idx]=clr;
    if(vis[idx])
    {
        return;
    }
    vis[idx]=true;
    for(auto i:adj[idx]){
        color(i,clr xor 1);
    }
}
int main()
{
    cin>>n>>m;
    vis=vector<int> (n);
    adj=vector<vector<int>>(n);
    col = vector<int> (n,-1); //let 0 be red color and 1 be blue
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
            color(i,0);
        }    
    }
    if(bipartite)
    {
        cout<<"Graph is bipartite"<<endl;
    }
    else
    {
        cout<<"Graph is not bipartite"<<endl;
    }
    return 0;
}
// test case
// 3 3
// 0 1
// 1 2
// 2 0