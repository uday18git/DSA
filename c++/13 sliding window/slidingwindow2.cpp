#include <bits/stdc++.h>
using namespace std;
int main()
{   //========== o(n) approach we ill use deque============//
    int n,k;cin>>n>>k;//n is the size of array k is window size
    vector<int> a(n);
    for(auto &i: a)
        cin>>i;
    deque<int> q;
    vector<int> ans;
    for(int i=0;i<k;i++)//we just take k initially because we dont have elements initially in the deque so
    {
        // we have to try to maintain the dq in a decreasing order
        while(!q.empty() && a[q.back()]<a[i])
        {
            q.pop_back();
        }
        q.push_back(i);
    }
    ans.push_back(a[q.front()]);
    for(int i=k;i<n;i++)
    {
        if(q.front() == i-k)
        {
            q.pop_front();
        }
        while(!q.empty() && a[q.back()]<a[i])
        {
            q.pop_back();
        }
        q.push_back(i);
        ans.push_back(a[q.front()]);
    }
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
    
    
    
    
    
    
    
    return 0;

}