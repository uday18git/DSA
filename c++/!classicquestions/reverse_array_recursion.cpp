#include <bits/stdc++.h> 
using namespace std;
void insert(vector<int>&arr,int temp)
{
    if(arr.size()==0)
    {
        arr.push_back(temp);
        return;
    }
    int x = arr.back();
    arr.pop_back();
    insert(arr,temp);
    arr.push_back(x);
}
void solve(vector<int>&arr)
{
    if(arr.size()==1)
    {
        return;
    }
    int temp = arr.back();
    arr.pop_back();
    solve(arr);
    insert(arr,temp);
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