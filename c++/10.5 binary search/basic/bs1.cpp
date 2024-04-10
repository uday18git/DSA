// descending sorted array
#include "bits/stdc++.h"
using namespace std;
int main()
{
    // binary search for descending arrray
    int start=0,end,mid,key;
    cin>>key;
    int a[]={20,17,15,14,13,12,10,9,8,4,3,2,1};
    end = sizeof(a)/sizeof(int)-1;
    while(start<=end)
    {
        mid = start + (end-start)/2;
        if(a[mid]==key)
        {
            cout<<mid<<endl;
            break;
        }
        else if(a[mid]>key)
        {
            start=mid+1; // ulta
        }
        else
        {
            end=mid-1; // ulta
        }
    }
    
return 0;
}



