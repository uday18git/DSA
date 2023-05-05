// connect ropes to minimize cost
// suppose array is given : {1,2,3,4,5}
// -
// --
// ---
// ----
// -----
// these are ropes of sizes given in the array
// we have to connect these ropes
// we always have to connect the minimum ropes
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int min_cost=0;
    vector<int> arr={1,2,3,4,5}; 
    priority_queue<int,vector<int>,greater<int>> min_h;
    for(int i=0;i<arr.size();i++)
    {
        min_h.push(arr[i]);
    }

    while(min_h.size()!=1)
    {
        int currsum=0;
        currsum+=min_h.top();
        min_h.pop();
        currsum+=min_h.top();
        min_h.pop();
        min_cost+=currsum;
        min_h.push(currsum);

    }
    cout<<min_cost<<endl;
    return 0;
}