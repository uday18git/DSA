// arr[] = {1,1,1,3,2,2,4}
//  we have to give k most frequent numbers so in this case if k is 2 ans is {1,2}
//  frequency and hash related
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int k=4;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> min_h;
    vector<int> arr={1,4,4,3,3,3,4,9,9,9,9,10,10};
    unordered_map<int,int>mp;
    for(int i=0;i<arr.size();i++)
    {
        mp[arr[i]]++;
    }
    //first is the number itself
    //second is the frequency
    // we are sorting based on frequency
    for(auto i=mp.begin();i!=mp.end();i++)
    {
        min_h.push({i->second,i->first});//converting map into pair and pushing it
        if(min_h.size()>k)
        {
            min_h.pop();
        }
    }
    while(min_h.size()>0)
    {
        cout<<min_h.top().second<<" ";
        min_h.pop();
    }
    // cout<<mp.size()<<endl;
    return 0;
}