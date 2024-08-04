// cycle detection in a undirected graph using bfs
// first create a adj list using the given graph
// if u start with two different paths , and end up at same node
// then there is a cycle
// if some one is already visited and it is not the parent of the current node
// then there is a cycle 
#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
        bool isCycle(int v,vector<int> adj[])
        {
            int vis[100];
            queue<pair<int,int>> q;
            q.push({v,-1});
            vis[v]=1;
            while(!q.empty())
            {
                auto curr = q.front();
                q.pop();
                int node = curr.first;
                int parent = curr.second;
                for(int i:adj[node])
                {
                    if(!vis[i])
                    { 
                        q.push({i,node}); 
                        vis[i] = 1;
                    }
                    else if (parent!=i)
                    {
                        return true;
                    }
                }
            }
            return false;
        }
};
// it can be a multiple components graph so
// above function you have to write seperately and call it from main function
// for(int i=0;i<V;i++)
// {
//     if(!vis[i])
//     {
//         if(isCycle(i,bla bla)==true)
//         {
//             return true;

//         }
//     }
//  return false;
// }

// same tc as bfs algorithm
// tc -> O(N+2E)



#include <bits/stdc++.h> 
using namespace std;
int main(){

return 0;
}