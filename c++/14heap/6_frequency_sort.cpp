// given an array sort based on frequency 
// arr[] = {1,1,1,3,2,2,4}
// {1,1,1,2,2,3,4}
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {1,1,1,3,2,2,4};
    priority_queue <pair<int,int>> max_h;
    unordered_map<int,int> mp;
    for(int i=0;i<arr.size();i++)
    {
        mp[arr[i]]++;
    }
    for(auto i=mp.begin();i!=mp.end();i++)
    {
        max_h.push({i->second,i->first});
    }
    vector<int> ans;
    while(max_h.size()>0)
    {
        for(int j=0;j<max_h.top().first;j++)
        {
            ans.push_back(max_h.top().second);
            
        }
        max_h.pop();
    }
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}