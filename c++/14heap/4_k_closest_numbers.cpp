// problem statement --> k closest
//  given arr[] : 5 6 7 8 9
//  x = smtg k = smtg , we have to find k values which are closest to x
//  we have to max heap
//  we always pop the useless
//  when we passs pair<int,int> in a heap sorting is done on first int automatically
// we store the differnce of arr numbers and x in first int of pair and actual number in the second int of pair
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x;
    printf("Enter x value");
    cin>>x;
    printf("Enter k value");
    int k;
    cin>>k;
    priority_queue<pair<int,int>> max_h;
    vector<int> v={5,6,7,8,9};
    for(int i=0;i<5;i++)
    {
        max_h.push(make_pair(abs(v[i]-x),v[i]));
        if(max_h.size()>k)
        {
            max_h.pop();
        }
    }
    while(max_h.size()>0)
    {
        cout<<max_h.top().second<<" ";
        max_h.pop();
    }


    return 0;
}
// we have to identify on which key we should apply the sorting
