// you have to find nodes which will eventually end up touching the terminal nodes
// you have to find topo only but you have to reverse all the edges 
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> graphRev(n);
        for(int i=0;i<n;i++)
        {
            for(auto j=0;j<graph[i].size();j++)
            {
                graphRev[graph[i][j]].push_back(i);
            }
        }
        vector<int> indegree(n,0);
        // maintaining indegree array
        for(int i=0;i<n;i++)
        {
            for(int it:graphRev[i])
            {
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(int i:graphRev[node])
            {
                indegree[i]--;
                if(indegree[i]==0)q.push(i);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};