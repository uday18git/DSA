// normal dijkstras ntg 
#include <bits/stdc++.h> 
using namespace std;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        // making the adjacency list
        for(int i=0;i<times.size();i++)
        {
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        vector<int> time(n+1,INT_MAX);
        time[k]=0;
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int t = it.first;
            int node = it.second;
            // if (time[node] < t) continue;
            for(auto i:adj[node])
            {
                int adjNode = i.first;
                int ti = i.second;
                if(time[adjNode]>t+ti)
                {
                    time[adjNode] = t+ti;
                    pq.push({time[adjNode],adjNode});
                }
            }
        }
        int maxTime = *max_element(time.begin()+1,time.end());
        return maxTime == INT_MAX?-1 : maxTime;


    }
};