#include "bits/stdc++.h"
using namespace std;
// TO FIND OUT PEAK ELEMENT .. PEAK ELEMENT MEANS IT SHOULD BE GREATER THAN PREVIOUS AND NEXT ELEMENT
// STRATEGY
// COMPUTE MID , SEE IF ARR[MID]> ARR[MID+1] && ARR[MID]>ARR[MID-1],,,,,,,, ELSE IF ARR[MID-1]>ARR[MID] CHECK LEFT BECAUSE THAT CAN BE A PEAK RIGHT
int findPeakElement(int arr[],int low,int high,int n)
{
    int mid= high+(low-high)/2;
    if((mid==0 || arr[mid]>arr[mid-1]) && (mid==n-1 || arr[mid]>arr[mid+1]))return mid;
    else if(mid>0 && arr[mid] < arr[mid-1])return findPeakElement(arr,low,mid-1,n);//MID>0 TO MAKE SURE THAT MID-1 IS NON NEGATIVE
    else return findPeakElement(arr,mid+1,high,n);
}
int main()
{
    int arr[] = {0,6,8,5,7,9};
    int n=6;
    cout<<"Peak element index : "<<findPeakElement(arr,0,n-1,n)<<endl;
    return 0;
}