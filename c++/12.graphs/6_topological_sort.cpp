// topological sort
// A topological ordering is an ordering of the nodes in a directed graph where for each directed edge from node A to node B, node A appears before node B in the ordering.
// note : Topological ordering are not unique
// Not every graph has topological sort
// A graph has a valid topological sort if and only if it is a DAG(directed acyclic graph) does not contain directed cycles
// if cycle is there not possible
// see book
// algorithm
// while(all nodes are not visited)
// nodes with zero indegree can be added to the output array
// all the nodes which are connected to the nodes with zero indegree are decremented by 1
// psuedocode
// make adjecency list
// maintain indegree array
// make queue
// push all nodes with zero indegree in the queue
// while(queue is not empty)
// pop the node from the queue
// and minus the indegree of all the nodes which are connected to the popped node
// if the indegree of that node becomes zero then push it in the queue
// print the popped node
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int cnt=0;
    vector<vector<int>> adj_list(n);
    vector<int> indeg(n,0);
    for(int i=0;i<m;i++)
    {
        int u,v;cin>>u>>v;
        adj_list[u].push_back(v);
        indeg[v]++;
    }
    queue<int> pq;
    for(int i=0;i<n;i++)
    {
        if(indeg[i]==0){
            pq.push(i);
        }
    }
    while(!pq.empty())
    {
        cnt++;
        int x=pq.front();
        pq.pop();
        cout<<x<<" ";
        for(auto it: adj_list[x])
        {
            indeg[it]--;
            if(indeg[it]==0)
            {
                pq.push(it);
            }
        }
        
    }
    cout<<endl<<cnt;
    return 0;
    // so if complete answer does not come , it means that there is a cycle in the given graph
}