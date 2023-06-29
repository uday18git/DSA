// There are N friends numbered from 0 to N-1. You have to choose 2 person such that they are not related to each other . You are given information in the form of M pairs(X,Y) i.e there is an link between friend X and Y.
// Find out the number of ways in which 2 persons from different groups can be chosen
// Idea
// Find the components and thier sizes
// At ith component, choose one person from it and other person from the rest of the groups

#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<bool> vis;
vector<vector<int>> adj;
vector<int> components;//stores size of components
int get_comp(int idx)
{
    vis[idx]=true;
    int ans=1;
    for(auto i:adj[idx])
    {
        if(!vis[i])
        {
            ans+=get_comp(i);
            vis[i]=true;
        }
    }
    return ans;

}
int main()
{
    cin>>n>>m;
    adj = vector<vector<int>> (n); 
    vis = vector<bool> (n); 
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            components.push_back(get_comp(i));
        }
    }
    // to find out the number of ways to choose 2 persons such that they are not related with each other 
    long long int ways=0;
    for(int i=0;i<components.size();i++)
    {
        for(int j=i+1;j<components.size();j++)
        {
            ways+= components[i]*components[j];
        }
    }
    cout<<"my ans"<<endl;
    cout<<ways<<endl;
    ways=0;
    //shorter way
    for(auto i:components)
    {
        ways+= i*(n-i);
    }
    cout<<"ac ans"<<endl;
    cout<<ways/2; // /2 to avoid over counting
    return 0;
}
// test case
// 5 3
// 0 1
// 2 3
// 0 4
// ans 6