// question -> A group of cows grabbed a truck and ventured an on expedition deep into the jungle
// the truck leaks one unit of fuel every unit of distance it travels
// to repair the truck , the cows need to drive the nearest town (no more than 10^6 units distance)
// on this road between the town and the current location , there are N(1<=N<=10^5) fuel stops where the cows can stop to acquire additional fuel (1.....100 units at each stop).
// The cows want to make the minimum possible stops for fuel on the way to the town.
// Capacity of the tank is sufficiently large to hold any amount of fuel.
// Initial units of fuel : P (1<=P<=10^6)
// Initial distance from town : L
// Determine the minimum number of stops to reach the town
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n; //number of stops
        cin>>n;
        vector<pair<int,int>> a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i].first>>a[i].second;
        }
        int l,p;
        cin>>l>>p;

        for(int i=0;i<n;i++)
        {
            a[i].first=l-a[i].first;
        }
        sort(a.begin(),a.end());
        int ans=0;
        int flag=0;
        int curr=p;//current fuel
        priority_queue<int,vector<int>> max_h;
        for(int i=0;i<n;i++)
        {
            if(curr>=l)
                break;
            
            while(curr<a[i].first)
            {
                if(max_h.empty())
                {
                    flag=1;
                    break;
                }
                ans++;//taking what is in top of maxheap
                curr+=max_h.top();
                max_h.pop();
            }
            if(flag)
            {
                break;
            }
            max_h.push(a[i].second);
            
        }
        if(flag)
        {
            cout<<"-1"<<endl;
            continue;
        }
        while(!max_h.empty()&& curr<l)
        {
            curr+=max_h.top();
            max_h.pop();
            ans++;
        }
        if(curr<l)
        {
            cout<<"-1"<<endl;
            continue;
        }
        cout<<ans<<endl;

    }
    return 0;
}