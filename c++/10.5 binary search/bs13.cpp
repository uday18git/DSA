// peak element
// we have to give index of peak element
// peak element means it should be greater than both its neighbours
// only one enough
#include <bits/stdc++.h> 
using namespace std;
int main(){
    vector<int> arr={5,10,20,30,10};
    int low=0;
    int high=arr.size()-1;
    int n=arr.size()-1;
    while(low<=high)
    {
        int mid = low+(high-low)/2;
        if(mid>0 && mid <n)
        {
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
            {
                cout<<mid;
                break;
            }
            else if(arr[mid]<arr[mid-1])
            {
                high=mid-1;
            }

            else
            {
                low=mid+1;
            }
        }
        else if(mid==0)
        {
            if(arr[0]>arr[1])
            {
                cout<<0;
                break;
            }else
            {
                cout<<1;
                break;
            }

        }
        else if(mid==n)
        {
            if(arr[mid-1]<arr[mid])
            {
                cout<<mid<<endl;
                break;
            }
            else
            {
                cout<<mid-1;
                break;
            }
        }
    }
return 0;
}