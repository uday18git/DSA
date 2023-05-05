#include <bits/stdc++.h>
using namespace std;
int main()
{
    cout << "enter the size of array"
         << " ";
    int n;
    cin >> n;
    cout << "Enter the k value ";
    int k;
    cin >> k;
    vector<int> v(n);
    cout << "Enter the k sorted array" << endl;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    priority_queue<int,vector<int>,greater<int>> min_h; //we need smallest element in k numbers so we will use min heap
    for(int i=0;i<n;i++)
    {
        min_h.push(v[i]);
        if(min_h.size()>k)
        {
            cout<<min_h.top()<<" ";
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