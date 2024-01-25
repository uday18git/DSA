// number of provinces
// 

class Solution {
public:
    void dfs(int v,vector<int> adj[],vector<int>&visited)
    {
        visited[v]=1;
        for(int num:adj[v])
        {
            if(!visited[num])
            {
                dfs(num,adj,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1 && i!=j)
                {
                    adj[j].push_back(i);
                    adj[i].push_back(j);
                }
            }
        }
        vector<int>visited(n,0);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                ans++;
                dfs(i,adj,visited);
            }
        }
        return ans;
    }
};

// sc - > adjacency list O(N)visited array + O(N)recursion stack space for skewed graph
// tc - > O(n) + O(n+2e)