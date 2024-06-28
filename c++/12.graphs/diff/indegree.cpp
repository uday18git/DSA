
// https://leetcode.com/problems/maximum-total-importance-of-roads/
#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long ans=0;
        int m = roads.size();
        vector<int> indegree(n,0);
        for(int i=0;i<m;i++)
        {
            indegree[roads[i][0]]++;
            indegree[roads[i][1]]++;
        }
        sort(indegree.begin(),indegree.end(),greater<int>());
        int x=n;
        for(int i=0;i<n;i++)
        {
            ans+=static_cast<long long>(indegree[i])*(x--);
        }
        return ans;
    }
};