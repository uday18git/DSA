// so basically in dfs dfs(int v) 
// we are making v as visited and printing it ...
// each v we are marking it as visited and printing it
// and for each of its neighbouring nodes we are calling dfs again
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+2;
bool visited[N];
vector<int> adj[N];
void dfs(int v)
{
    //for preorder 
    cout<<v<<endl;
    visited[v]=1;
    // vector<int> :: iterator it;
    for(auto it=adj[v].begin();it!=adj[v].end();it++)
    {
        if(!visited[*it]) // it gives a pointer so dereferencing it
        {
            dfs(*it);
        }
    }
    // for postorder put print statement here
    // cout<<v<<endl;
// testcase
// 7 7
// 1 2
// 1 3
// 2 4
// 2 5
// 2 6
// 2 7
// 7 3
// preorder 1 2 4 5 6 7 3
// postorder 4 5 6 3 7 2 1
}
int main()
{
    int n,m;
    cin>>n>>m; //number of nodes and edges
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
    }
    int x,y;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int num;
    cout<<"Enter the number you want to start the dfs: ";
    cin>>num;
    dfs(num);


    return 0;
}


// sc -> o(n) + o(n) + o(n) = o(n)
// tc -> O(2*e) + O(n)


void dfs(int v)
{
    visited[v]=1;
    cout<<v<<endl;
    for(auto it:adj[v])
    {
        if(!visited[it])
        {
            dfs(it);
        }
    }
}
