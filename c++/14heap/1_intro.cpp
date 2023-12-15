//INTRODUCTION --> IF THERE IS K AND SMALLEST/LARGEST IN A QUESTION .. 100% HEAP QUESTION
// kth smallest element
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main(){
    priority_queue<int> max_h;
    // simply priority queue means the top element will be the highest
    
    int n,k;
    printf("Enter k value");
    cin>>k;
    printf("Enter the length of array");
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    for(int i=0;i<n;i++)
    {
        max_h.push(v[i]);
        if(max_h.size()>k)
        {
            max_h.pop();
        }
    }
    // cout<<"yes"<<endl;
    cout<<max_h.top()<<endl;




return 0;
}           