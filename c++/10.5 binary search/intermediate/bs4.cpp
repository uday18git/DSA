// number of times a sorted array is rotated
// nothing but index of minimum number

// when mid is calculated , one side of mid is sorted and another side is unsorted
// and special quality of the minimum number is that it is smaller than both the neighbours
// we can use this property to find the minimum number
// we putted mod n to avoid negative index and overflow 
// (mid-1 + n)%n and (mid+1)%n are previous and next elements of mid respectively
// we will find the minimum element in the unsorted part
// when array is sorted arr[start]<=arr[end] then start is the answer
// we can identify the unsorted part , arr[start]<=arr[mid] then left part is sorted and
// right part is unsorted , so we will search in right part
// start=mid+1 we will do
// else if arr[mid]<=arr[end] then right part is sorted and left part is unsorted , so we will search in left part
// end=mid-1 we will do
#include <bits/stdc++.h> 
using namespace std;
int main(){
    vector<int> arr ={4,5,6,7,0,1,2}; //{11,12,15,18,2,5,6,8};
    int start=0;
    int end=arr.size()-1;
    int n=arr.size();
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        // if(arr[mid]<=arr[(mid-1+n)%n] && arr[mid]<=arr[(mid+1)%n])
        if((n==0 || arr[mid-1]>=arr[mid]) && (mid==n-1 || arr[mid]<=arr[mid+1]))
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

