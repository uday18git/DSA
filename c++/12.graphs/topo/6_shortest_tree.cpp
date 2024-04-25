#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// minimum height tree
// my intial approach i am getting is to do a level order traversal from each node
// and store each of its heights and map of heights and nodes , push back 
// above is O(n**2)
// real answer is to do topological sort , keep on removing the leaf nodes (degree 1)
#define vi vector<int> 
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vi res;
        if(n<=0)
        {
            return res;
        }
        if(n==1)
        {
            res.push_back(0);
            return res;
        }
        vector<int> deg(n,0);
        vector<vector<int>> gr(n);
        for(auto e:edges)
        {
            deg[e[0]]++;
            deg[e[1]]++;
            gr[e[0]].push_back(e[1]);
            gr[e[1]].push_back(e[0]);
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(deg[i]==1)
            {
                q.push(i);
            }
        }
        while(n>2)
        {
            int sz=q.size();
            n-=sz;
            while(sz>0)
            {
                int el = q.front();
                q.pop();
                for(auto ne: gr[el])
                {
                    deg[ne]--;
                    if(deg[ne]==1)
                    {
                        q.push(ne);
                    }
                }
                sz--;
            }
        }
        while(!q.empty())
        {
            int el = q.front();
            q.pop();
            res.push_back(el);
        }
        return res;
    }
};