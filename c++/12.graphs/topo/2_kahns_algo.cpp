// dfs using bfs
// called kahns algo
// only possible in dag
// why ?? 
// Topological ordering is a way of ordering the vertices of a directed graph such that for every directed edge (u, v), vertex u comes before vertex v in the ordering. This ordering is only possible in directed acyclic graphs (DAGs), and there are fundamental reasons for this restriction:
// 1. **Cyclic Dependencies:** In a directed graph with cycles, 
// there are at least two vertices that are part of a cycle, and it's impossible
//  to establish a strict ordering between them. This is because in a cycle, you can keep going around indefinitely without reaching a clear starting or stopping point, making it impossible to define a linear order.
// 2. **Ambiguity in Dependencies:** In a directed acyclic graph, each vertex has a clear "before" and "after" relationship with its adjacent vertices. However, in a graph with cycles, there may be ambiguous dependencies. For example, if there's a cycle A -> B -> C -> A, it's not clear whether A should come before B or B before A in the ordering.
// 3. **Algorithmic Purpose:** Topological ordering is often used in algorithms such as scheduling tasks or resolving dependencies. In the presence of cycles, there may be circular dependencies that cannot be resolved, making it challenging to determine a valid topological ordering.
// In summary, topological ordering relies on a well-defined partial order of the vertices, and cycles introduce ambiguity and make it impossible to establish such an order. Therefore, topological ordering is only applicable and meaningful in directed acyclic graphs (DAGs).
// definition of topo ordering -> if there exists a directed edge between u to v then u appears before v in the ordering

// using bfs how u will do means
// first store all in the indegrees in an array, then whose is 0 put them into queue
// remove the first one 
#include <bits/stdc++.h>
using namespace std;
// O(v+e) is the time complexity
class Solution{
    public:
    vector<int> topoSort(int V,vector<int> adj[])
    {
        vector<int> ans;
        vector<int> indegree(V,0);
        for(int i=0;i<V;i++)
        {
            for(auto it: adj[i])
            {
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it : adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                {
                    q.push(it);
                }
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}