// search in a nearly sorted array
// heree ,  a element that has to be in the ith position , can be in i+1 or i-1th position
#include <bits/stdc++.h> 
using namespace std;
int main(){
    vector<int> arr={5,10,30,20,40};
    int key=20;
    int start=0,end=arr.size()-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]==key)
        {
            cout<<mid;
            break;
        }
        if(arr[mid-1]==key)
        {
            cout<<mid-1;
            break;
        }
        if(arr[mid+1]==key)
        {
            cout<<mid+1;
            break;
        }
        else if(arr[mid]>key)
        {
            end=mid-2;// because its a nearly
        }
        else 
        {
            start=mid+2;
        }
    }
return 0;
}