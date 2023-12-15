// ceil of a element
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {1, 2, 3, 4, 8, 10, 12, 19};
    int start=0;
    int end=arr.size()-1;
    int key=5;
    int ans;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]==key)
        {
            ans=key;
            break;
        }
        else if(arr[mid]>key)
        {
            ans=arr[mid];
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }
    cout<<ans;
    return 0;
}