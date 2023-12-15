// floor of an element in a sorted array
// arr = {1,2,3,4,8,10,10,12,19}
// floor of 5 in above array will be 4 (greatest element smaller than 5)
// sorted array so we use binary search
#include <bits/stdc++.h> 
using namespace std;
int main(){
    vector<int>arr={1,2,3,4,8,10,10,12,19};
    int key=20;
    int start=0;
    int end=arr.size()-1;
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
            end=mid-1;
        }
        else
        {
            ans=arr[mid];
            start=mid+1;
        }
    }
    cout<<arr[end];// cout<<ans also works
return 0;
}