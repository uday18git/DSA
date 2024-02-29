class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long long,long long>> adj[n];
        for(long long i=0;i<roads.size();i++)
        {
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});

        }
        long long  mode = (long long)(1e18+7);
        vector<long long> ways(n,0);
        vector<long long> dis(n,INT_MAX);
        ways[0]=1;
        dis[0]=0;
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>pq;
        pq.push({0,0});
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            long long node = it.second;
            long long d = it.first;
            for(auto i:adj[node])
            {
                long long adjNode = i.first;
                long long edW = i.second;
                
                if((edW + d)%mode < dis[adjNode])
                {
                    dis[adjNode] = (edW + d)%mode;
                    pq.push({dis[adjNode],adjNode});
                    ways[adjNode] = ways[node];
                }
                else if(edW+d == dis[adjNode])
                {
                    ways[adjNode]= (ways[adjNode] + ways[node])%mode;
                    // no need to push into queue because already a instance of tht will be in the queue
                }
            }

        }
        long long ans = (ways[n-1]) % mode;
        return ans;

    }
};

