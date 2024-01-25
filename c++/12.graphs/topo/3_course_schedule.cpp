class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        // making the adjacency list
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        // topo sort using bfs
        vector<int> indegree(numCourses,0);
        // maintaining a indegree array
        for(int i=0;i<numCourses;i++)
        {
            for(int it:adj[i])
            {
                indegree[it]++;
            }
        }
        queue<int> q;
        // pushing all the nodes which have indegree 0
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)q.push(i);
        }
        vector<int> ans;
        // bfs
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(int i:adj[node])
            {
                indegree[i]--;
                if(indegree[i]==0)q.push(i);
            }
        }
        if(ans.size()==numCourses)return true;
        else return false;

    }
};
// return the topo if asked