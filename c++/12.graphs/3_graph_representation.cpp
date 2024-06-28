#include <bits/stdc++.h>
using namespace std;
// adjacency matrix
const int N = 1e5+2;
vector<int> adj[N]; //adjacency list
int main()
{
    int n,m;
    cin>>n>>m;//number of nodes and edges
    vector<vector<int>> adjm(n+1,vector<int>(n+1,0));//initialised with zeros
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        adjm[x][y]=1;
        adjm[y][x]=1;
    }
    cout<<"Adjacency matrix of above graph is given by: "<<endl;
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            cout<<adjm[i][j]<<" ";
        }
        cout<<endl;
    }
    // we will get a matrix diagonally symmetrical
    // adjacency list
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);//undirected
        adj[y].push_back(x);
    }
    cout<<"Adjacency list of the graph is: "<<endl;
    for(int i=1;i<n+1;i++)
    {
        cout<<i<<" -> ";
        // for(int x:adj[i])
        for(int j=0;j<adj[i].size();j++)
            cout<<adj[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}