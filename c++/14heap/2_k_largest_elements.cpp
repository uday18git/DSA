#include <bits/stdc++.h> 
using namespace std;
int main(){
    cout<<"Enter the length of array "<<endl;
    int  n,k;
    cin>>n;
    cout<<"Enter the k value "<<endl;
    cin>>k;
    vector<int> v1(n);
    priority_queue<int,vector<int>,greater<int>> min_h;// min heap
    for(int i=0;i<v1.size();i++)
    {
        cin>>v1[i];
    }
    for(int i=0;i<v1.size();i++)
    {
        min_h.push(v1[i]);
        if(min_h.size()>k)
        {
            min_h.pop();
        }
    }
    while(min_h.size()>0)
    {
        cout<<min_h.top()<<" ";
        min_h.pop();
    }
return 0;
}
// FLIPKART