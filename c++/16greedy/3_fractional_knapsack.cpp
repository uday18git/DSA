// We are given n items with {weight,value} of each item and
//  the capacity of knapsack is W. We need put these items in knapsack such that final value of items in knapsack is maximum.
//  value ->  21 24 12 40 30
//  weight -> 7  4  6  5  6
//  ill take whose value/weight is maximum
//  v/w    -> 3 6 2 8 5
//  capacity -> 20
//  sorted -> value ->  40 24 
//            weight -> 5  4
#include <bits/stdc++.h>
using namespace std;
bool compare(pair<int,int> p1,pair<int,int>p2)
{
    double  v1= (double)p1.first/p1.second;
    double  v2= (double)p2.first/p2.second;
    return v1>v2;
}
int main()
{
    int n;cin>>n;
    
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i].first>>a[i].second;
    }
    int w;cin>>w;
    sort(a.begin(),a.end(),compare);// it will sort so that compare is always true
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(w>=a[i].second)// normal case
        {
            ans+=a[i].first;
            w-=a[i].second;
            continue;
        }
        double vw = (double)a[i].first/a[i].second;
        ans+=vw*w;
        w=0;
        break;
    }
    cout<<ans<<endl;
    return 0;
}