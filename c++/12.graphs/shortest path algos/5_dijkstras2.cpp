// dijstras using set
// set stores unique values , stores everything in ascending order
// when checking for lesser values in some node, if there exisits already something instead of infinity
// then it indicates there is tht value in the set , so we can erase the value , in pqs u cannot ERASE the value 
// it minorly improves the complexity 
#include<bits/stdc++.h>
using namespace std;
vector<int> dijkstra(int s,int v,vector<vector<int>>adj[])
{
    set<pair<int,int>> st;
    vector<int> dist(v,INT_MAX);
    st.insert({0,s});
    dist[s]=0;
    while(!st.empty())
    {
        auto it = *(st.begin());
        int node = it.second;
        int dis = it.first;
        st.erase(it);
        for(auto it:adj[node])
        {
            int adjNode = it[0];
            int edgN = it[1];
            if(dis+edgN <dist[adjNode])
            {
                if(dist[adjNode]!=INT_MAX)
                {
                    st.erase({dist[adjNode],adjNode});
                }
                dist[adjNode] = dis+edgN;
                st.insert({dist[adjNode],adjNode});
            }
        }
        return dist;
    }

}