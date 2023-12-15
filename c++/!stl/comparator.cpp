#include <bits/stdc++.h>
using namespace std;
// int main()
// {
//     int n;
//     cin>>n;
//     vector<int> v(n);
//     for(int i=0;i<n;i++)cin>>v[i];
//     sort(v.begin(),v.end(),greater<int>()); //to sort in descending order
//     for(int i=0;i<n;i++)cout<<v[i]<<" ";
//     return 0;
// }
bool comp(pair<int,int>a,pair<int,int>b)
{
    return a.second<b.second; // this comparator will sort according to the second 
}
int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({x,y});
    }
    sort(v.begin(), v.end(),comp); 
    for (int i = 0; i < n; i++)
        cout << v[i].first << " "<<v[i].second<<endl;
    return 0;
    
}