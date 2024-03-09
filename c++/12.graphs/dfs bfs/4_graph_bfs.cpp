// superb see video to learn
// bfs(int v) we are printing and marking v as visited 
// push it to the q
// then while q is not empty
// pop elements and for there adjacent element add them to q and cout them and mark them as visited
// here 2 times visited is coming inside and outside
// in dfs only outside 



#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+2;
bool visited[N];
vector<int> adj[N]; // array of vectors
queue<int> q;
void bfs(int v)// traversal starts at v , every node is explored one by one
{
    cout<<v<<" ";
    visited[v]=1;
    q.push(v);
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        // vector<int> :: iterator it;
        // for(auto it:adj[node]) // you have to remove the stars below and it will work
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

// TC -> O(N) + O(2E)
// because the while loop runs till queue is empty
// and the for loop inside runs for all the degrees of a node
// and total degrees in a graph is 2*e ukr



int N = 1e5+2;
vector<int> adj[N];
bool visited[N];
void bfs(int v)
{
    visited[v] = true;
    cout<<v<<" ";
    q.push(v);
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(auto it=adj[node].begin();it!=adj[node].end();++it)
        {
            if(!visited[*it])
            {
                q.push(*it);
                visited[*it]=true;
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
    int x,y;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x); // undirected graph
        }
    }

    cout<<"Enter the node you want to start bfs from: "<<endl;
    int b;
    cin>>b;
    cout<<"bfs of the graph is"<<endl ;
    bfs(b);
    return 0;
}