// minimum multiplications to reach end [mod = 100000]

// start=3     end=30 
// arr[] = {2,5,7}
// 3 * 2  -> 6 * 5 -> 30

// start=7  end=66175
// arr[] = {3,4,65}
// 7*3 -> 21*3 -> 63 * 65 -> 4095*65 -> 266175 % 100000 -> 66175 so reached

#include <bits/stdc++.h> 
using namespace std;

int minimumOperations(int n, int start, int end, vector<int> &a)
{
    // Write your code here
    queue<pair<int,int>> q;
    vector<int> dis(999,INT_MAX);
    dis[start]=0;
    q.push({0,start});
    while(!q.empty())
    {
        auto it = q.front();
        q.pop();
        int d = it.first;
        int node = it.second;
        if(node==end)return d;
        for(int i=0;i<n;i++)
        {
            int n = (a[i]*node)% (int(1e3));
            if(dis[n]>d+1)
            {
                dis[n]=dis[node]+1;
                q.push({dis[n],n});
            }
        }
    }
    return -1;
}