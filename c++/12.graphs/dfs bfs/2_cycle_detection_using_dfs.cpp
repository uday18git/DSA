// cycle detection in using dfs

// on the same path , node has to be visited again then only we can say that it is cycle has detected
// we will have a extra array , path visited


#include <bits/stdc++.h> 
using namespace std;

const int N = 1e5+2;
int visited[N];
bool dfs_detect(int v,int parent,vector<int> adj[],vector<int> &visited)
{
    visited[v] = true;
    for(int i:adj[v])
    {
        if(!visited[i])
        {
            if(dfs_detect(i,v,adj,visited))return true;   //  if one call returns a true then all should return false
        }
        else if(i!=parent)
        {
            return true;
        }
    }
    return false;

}

int main(){


return 0;
}