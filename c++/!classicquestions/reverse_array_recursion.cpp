#include<bits/stdc++.h>
using namespace std;



void solve(vector<int>&arr)
{
    if(arr.size()==1)
    {
        return;

    }
    int temp = arr.back();
    arr.pop_back();
    
}
int main()
{
    vector<int> arr = {1,2,3,4,5};
    solve(arr);
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}