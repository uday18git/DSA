// problem : you are given n files with their computation times in an array
//  operation: choose/take any two files, add their computation times and append it to the list of computation times. {cost=Sum of computation time}
//  do this until we are left with only we one file in the array
//  we have to do this operation such that we get minimum cost finally
//  mostly sorting is done in greedy
//  same as the connect ropes with minimum cost question
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    priority_queue<int,vector<int>,greater<int>> min_h;
    for(int i=0;i<n;i++)
    {
        min_h.push(v[i]);
    }
    int ans=0;
    while(min_h.size()>1)
    {
        int num1=min_h.top();
        min_h.pop();
        int num2=min_h.top();
        min_h.pop();
        ans+=(num1+num2);
        min_h.push(num1+num2);

    }
    // ans = min_h.top();
    cout<<ans;

    return 0;
}