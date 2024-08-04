#include <bits/stdc++.h>
using namespace std;
int main()
{
    map<int,int> mp;
    vector<int> arr={1,8,7,6,1,2,2,2,3,3,3,4,4,4,4,5,5,5,5,5,5,5,5};
    for(int i=0;i<arr.size();i++)
    {
        mp[arr[i]]++;
    }
    cout<<"Frequency of all elements"<<endl;
    // map<int,int> :: iterator it;
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }
    return 0;
}