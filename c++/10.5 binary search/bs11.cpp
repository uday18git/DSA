#include <iostream>
#include<vector>
using namespace std;
// search for first occurance of 1 in a infinite binary sorted array
// so we have to combine the previous one and first occurance program and search for 1
int main() {
    vector<int> arr={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    int start=0;
    int end=1;
    int key=1;
    int ans;
    while(key<arr[end])
    {
        start=end;
        end*=2;
    }
    start=0;
    end=arr.size()-1;
    while(start<=end)
    {
        int mid=start + (end-start)/2;
        if(arr[mid]==1)
        {
            end=mid-1;
            ans=mid;
        }
        else
        {
            start=mid+1;
        }
    }
    cout<<start;
    return 0;
}