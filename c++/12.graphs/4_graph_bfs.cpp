#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+2;
bool visited[N];
vector<int> adj[N]; // array of vectors
queue<int> q;
void bfs(int v)// traversal starts at v , every node is explored one by one
{
    visited[v]=1;
    cout<<v<<" ";
    q.push(v);
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        // vector<int> :: iterator it;
        for(auto it=adj[node].begin();it!=adj[node].end();it++)
        {

            if(!visited[*it]) // *it gives contents of the iterator , it is a pointer so we are dereferencing it
            {
                visited[*it]=1;
                q.push(*it);
                cout<<*it<<" ";
            }
        }
    }
}
int main()
{
    for(int i=0;i<N;i++)
    {
        visited[i]=0;
    }
    int n,m;
    cin>>n>>m;//number of nodes and edges
    int x,y;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);//undirected 
        adj[y].push_back(x);
    }
    cout<<"Enter the node you want to start bfs from: "<<endl;
    int b;
    cin>>b;
    cout<<"bfs of the graph is"<<endl ;
    bfs(b);
   

    return 0;
}