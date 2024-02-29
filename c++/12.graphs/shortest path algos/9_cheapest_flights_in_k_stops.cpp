// class Solution {
// public:
//     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
//         vector<pair<int,int>> adj[n];
//         for(int i=0;i<flights.size();i++)
//         {                                // node         price
//             adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
//             // adj[flights[i][1]].push_back({flights[i][0],flights[i][2]});
//         }
//                         //price     node stops
//         priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
//         vector<int> dist(n,INT_MAX);
//         dist[src]=0;
//         pq.push({0,{src,0}});
//         while(!pq.empty())
//         {
//             auto it = pq.top();
//             pq.pop();
//             int p = it.first;
//             int node = it.second.first;
//             int stop = it.second.second;
//             if(stop>k)continue;
//             // if(node==dst && stop<=k)return p;
//             for(auto i:adj[node])
//             {
                
//                 if( dist[node]+i.second<dist[i.first])
//                 {
//                     dist[i.first]=dist[node]+i.second;
//                     pq.push({dist[i.first],{i.first,stop+1}});
//                 }
//             }
//         }
//         if(dist[dst]==INT_MAX)return -1;
//         return dist[dst];
//     }
// };

// if you take price as the first element in the pq , fails test case
// n =
// 4
// flights =
// [[0,1,1],[0,2,5],[1,2,1],[2,3,1]]
// src =
// 0
// dst =
// 3
// k =
// 1

// Use Testcase
// Output
// 3
// Expected
// 6
// because some shits are getting updated which were in the best path before tht path being declared as best
// so we have to take stops as our first elemetn in the pq
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        // here stops are increasing by 1 , so we can take queue instead of pq
        // 1 1 1 1 1 1 2 2 2 2 3 3 3 3 3 
                         // stops   price node
        queue<pair<int,pair<int,int>>> q;
        vector<pair<int,int>> adj[n];
        // making adjacency list
        for(int i=0;i<flights.size();i++)
        {
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        vector<int> price(n,INT_MAX);
        price[src]=0;
        q.push({0,{0,src}});
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int stop = it.first;
            int p = it.second.first;
            int node = it.second.second;
            if(stop>k)continue;
            for(auto i:adj[node])
            {
                int adjNode = i.first;
                int edW = i.second;
                if(p+edW <= price[adjNode] )
                {
                    price[adjNode] = p+edW;
                    q.push({stop+1,{p+edW,adjNode}});

                }
            }
        }
        if(price[dst]==INT_MAX)return -1;
        return price[dst];

    }
};
// time complexity of dijkstras is 