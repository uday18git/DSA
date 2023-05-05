//smallest subsequence of sum k
// first of all wat is subarray and wat is subsequence
// subarray -> continous block of elements
//example -> for array {1,1,3,2,8} subarray is {1,3,2,8},{3,2}
// subseqeuence -> for above array subsequence is {3,8},{1,2,8}
// TAKE A MAXHEAP AND INSERT ALL THE ELEMENT
// ARRAY WILL BE IN DECREASING ORDER 
// KEEP POPPING THE ELEMENTS ANS KEEP ADDING THEM TO A VARIABLE SUM AND MAINTAIN COUNT
// WHEN SUM>=K , THEN PRINT THE ANSWER.
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    priority_queue<int,vector<int>>max_h;
    for(int i=0;i<n;i++)
    {
        max_h.push(a[i]);
    }
    int sum=0;
    int count=0;
    while(!max_h.empty())
    {
        sum+=max_h.top();
        max_h.pop();
        count++;
        if(sum>=k)
        {
            break;
        }
    }
    if(sum<k)
    {
        cout<<-1<<endl;
    }
    else
    {
        cout<<count<<endl;
    }
    return 0;
}