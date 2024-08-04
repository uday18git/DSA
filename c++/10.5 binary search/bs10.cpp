#include <iostream>
#include<vector>
using namespace std;
int main() {
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16} ;
    // consider this as a infinite array 
    // we have to apply binary search on a infinite array
    int start=0;
    int end=1 ;
    int key=11;
    while(key>arr[end] ) // will give segmentation fault if the array is not actually infinite length
    {
        start=end;
        end=end*2;
    }
    while(start<=end)
    {
        int mid=start + (end-start)/2;
        if(arr[mid]==key)
        {
            cout<<mid;
            break;
        }
        else if(arr[mid]>key)
        {
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }
    return 0;
}