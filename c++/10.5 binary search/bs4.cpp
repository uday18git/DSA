// number of times a sorted array is rotated
// nothing but index of minimum number
#include <bits/stdc++.h> 
using namespace std;
int main(){
    vector<int> arr = {11,12,15,18,2,5,6,8};
    int start=0;
    int end=arr.size()-1;
    int n=arr.size();
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]<=arr[(mid-1+n)%n] && arr[mid]<=arr[(mid+1)%n])
        {
            cout<<mid;
            break;
        }
        else if(arr[start]<=arr[end]){
	            cout<<start;
                break;
	        }
        else if(arr[start]<=arr[mid])
        {
            start=mid+1;
        }
        else if(arr[mid]<=arr[end])
        {
            end=mid-1;   
        }

    }   

return 0;
}

