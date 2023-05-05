// very important problem for greedy
// problem -> you are given n activities with their start and finish time. select the maximum number of activities that can be performed by a single person
// , assuming that a person can only work on a single activity at a time.
// sample test case
// 3
// 10 20
// 12 15
// 20 30
// output -> 2
// constraints
// 1<=n<=10^5
// 1<=start,end<=10^9
// start <= end
// if you are at the ith activity
// what should be your next step?
// take the next activity which ends first
// sort the activities wrt end times
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    vector<vector<int>> v;
    for(int i=0;i<n;i++)
    {
        int start,end;
        cin>>start>>end;
        v.push_back({start,end});
    }
    sort(v.begin(),v.end(),[&](vector<int> &a,vector<int> &b){
        return a[1]<b[1]; //compares end times and sorts accordingly
    });
    int ans=1;
    int end=v[0][1];
    for(int i=1;i<n;i++)
    {
        if(v[i][0]>=end)
        {
            ans++;
            end = v[i][0];
        }
    }
    cout<<ans<<" ";
    return 0;
}