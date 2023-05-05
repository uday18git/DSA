// BRUTE FORCE APPROACH TO ADD 2 ARRAYS AT A TIME AND CREATE A NEW ARRAY, BUT WE CAN DO OPTIMISED
// BRUTE FORCE  -> TAKE 2 ARRAYS AND MERGE THEM REPEAT THIS PROCESS UNTILL WE ARE LEFT WITH 1 ARRAY
// EFFICIENT SOLN -> USING MIN HEAP
// 1. CREATe A MIN HEAP OF PAIRS pair-> {value,array number}
// 2. INSERT {first element ,array number }of all the sorted arrays into min heap
#include <bits/stdc++.h>
#define pii pair<int,int>
#define vii vector<pii> 
using namespace std;
int main()
{
    int k;
    cout<<"Enter the total number of arrays"<<endl;
    cin>>k;
    vector<vector<int>> a(k);
    for(int i=0;i<k;i++)
    {
        int size;
        cout<<"Enter the size of "<<i+1<<"th array"<<endl;
        cin>>size;
        a[i]=vector<int>(size);
        cout<<"enter the "<<i+1<<"th array"<<endl;
        for(int j=0;j<size;j++)
        {
            
            cin>>a[i][j];
        }
    }
    vector<int> idx(k,0);// vector of k size initialized with all zeros .. stores index number of the element of array currently stored in the min heap
    // index in this array denotes the number of array and value denotes the index of element stored in minheap
    priority_queue<pii,vii,greater<pii>> pq;
    for(int i=0;i<k;i++)
    {
        pii p;
        p.first = a[i][0];
        p.second = i;

        pq.push(p);//pushing all the first elements
    }
    vector<int> ans;
    while(!pq.empty())
    {
        pii x = pq.top();
        pq.pop();
        ans.push_back(x.first);
        if(idx[x.second]+1<a[x.second].size())
        {
            pii p;
            p.first = a[x.second][idx[x.second]+1];
            p.second= x.second;
            pq.push(p);
        }
        idx[x.second]+=1;
    }
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
// ASKED IN CODING INTERVIEWS MANY TIMES