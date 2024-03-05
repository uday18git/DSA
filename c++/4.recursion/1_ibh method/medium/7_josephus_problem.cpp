#include <bits/stdc++.h>
using namespace std;
void josephus(vector<int> &arr,int k,int idx,int ans)
{
    if(arr.size()==1)
    {
        cout<<arr[0]<<endl;
        return;
    }
    idx = (idx+k)%arr.size();
    arr.erase(arr.begin()+idx);
    josephus(arr,k,idx,ans);

}
int main()
{
    int n=5;
    int k=2;
    vector<int> arr = {1,2,3,4,5};
    for(int i=0;i<5;i++)
    {
        
        cout<<arr[i]<<" ";
    }
    k--;
    int idx=0;
    int ans=-1;
    josephus(arr,k,idx,ans);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}