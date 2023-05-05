#include "bits/stdc++.h"
using namespace std;
int main()
{   //=============== O(NLOGN) APPROACH ==============//
    int n,k;cin>>n>>k;//n is the size of array k is window size
    vector<int> a(n);
    for(auto &i: a)
        cin>>i;
    multiset<int,greater<int>> s;//stores in descending orrder
    vector<int> ans;
    for(int i=0;i<k;i++)
    {
        s.insert(a[i]);
    }// s will store in descending order so highest value will be at s.begin()
    ans.push_back(*s.begin());//s.begin gives pointer not value so * we putted
    for(int i=k;i<n;i++)
    {
        s.erase(s.lower_bound(a[i-k]));
        s.insert(a[i]);
        ans.push_back(*s.begin());
    }
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    // WE NEED TO ITERATE THROUGH FIRST K ELEMENTS SEPERATELY BECAUSE NO ELEMENTS ARE CURRENTLY THERE IN S SO FIRST WE ADD SOME ELEMENTS THEN DO THINGS
    
}