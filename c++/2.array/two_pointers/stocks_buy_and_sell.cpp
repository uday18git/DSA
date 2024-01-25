// best time to buy and sell stocks
#include <bits/stdc++.h> 
using namespace std;


// int main(){
//     vector<int> a = {7,1,5,3,6,4};
//     int start=0,end,ans=INT_MIN;
//     int n=a.size();
//     for(end=0;end<n;end++)
//     {
//         if(a[end]<a[start])
//         {
//             start=end;
//         }
//         ans=max(ans,a[end] - a[start]);
//     }
//     cout<<ans;
// return 0;
// }

// check the above soln

// dp soln
int main()
{
    vector<int> a = {7,1,5,3,6,4};
    int mini=a[0],profit=0;
    int curr=0;
    for(int i=1;i<a.size();i++)
    {
        curr=a[i]-mini;
        profit = max(profit,curr);
        mini = min(a[i],mini); // remembering the past
    }
    cout<<profit;
    return 0;
}