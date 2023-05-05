// given coordinates either in 2D array or pairs
// find the k closest points to the origin
// we will use min heap
// no need use sqrt
#include <bits/stdc++.h>
using namespace std;
#define ppi pair<int, pair<int, int>>
int main()
{
    priority_queue<ppi, vector<ppi>> max_h;
    vector<vector<int>> v =
        {{1, 2},
         {0, 1},
         {5, 6},
         {1, 1}};
    // cout << v.size() << endl;
    int k = 2;
    for (int i = 0; i < v.size(); i++)
    {
        max_h.push({v[i][0]*v[i][0]+v[i][1]*v[i][1],{v[i][0],v[i][1]}});
        if(max_h.size()>k)
        {
            max_h.pop();
        }
    }
    while(max_h.size()>0)
    {
        cout<<max_h.top().second.first<<" "<<max_h.top().second.second<<endl;
        max_h.pop();
    }
    return 0;
}