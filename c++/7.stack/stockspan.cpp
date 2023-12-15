// stock span problem 
// for each day we have to find out how many days before that had a value lesser or equal than that day
// brute force approach 
// iterate through the array
// for each element go from that element back till 0th index and count 

// optimized approach 
// using stack
#include <bits/stdc++.h> 
using namespace std;
int main(){
    vector<int> stock= {100,80,60,70,60,75,85};
    // expected ans    {1,1,1,2,1,4,6};
    vector<int> ans;
    stack<pair<int,int>>s;
    int n=stock.size();
    for(int i=0;i<n;i++)
    {
        pair<int,int>p={stock[i],1};
        while(!s.empty() && stock[i]>s.top().first)
        {
            p.second+=s.top().second;
            s.pop();
        }
        s.push(p);
        ans.push_back(s.top().second);
    }
    for(auto num:ans)
    {
        cout<<num;
    }
return 0;
}