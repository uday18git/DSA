//SEARCH IN SORTED AND ROTATED ARRAY
// arrray will be rotated from a pivot point
// search should be less than O(N)
// original array = [10,20,30,40,50]
// rotated array = [30,40,50,10,20]
// here pivot point is 50 and can be found out by arr[i]>arr[i+1]
// AFTER WE FIND OUT PIVOT POINT WE WILL JUST MAKE THE LEFT PART OF PIVOT THE LEFT HALF AND RIGHT HALF OF THE PIVOT THE RIGHT HALF
// THEN APPLY BINARY SEARCH IN BOTH LEFT AND RIGHT PARTS
#include <iostream>
using namespace std;
int searchInRotatedArray(int arr[],int key,int left,int right)
{
    if(left>right)return -1;
    int mid = (left+right)/2;
    if(arr[mid]==key)return mid;
    //============!!!! = passes testcases lamaoooo !!!!===========//
    if(arr[left]<=arr[mid])//means that mid is in the left or on the pivot because if arr[left]<arr[mid] it means that mid is in right of pivot
    {
        if(key>=arr[left]&& key<=arr[mid])return searchInRotatedArray(arr,key,left,mid-1);//mid-1 because mid condition is checkd above and is false
        else return searchInRotatedArray(arr,key,mid+1,right);
    }
    if(key>=arr[mid]&&key<=arr[right])return searchInRotatedArray(arr,key,mid+1,right);
    return searchInRotatedArray(arr,key,left,mid-1);
}
int main()
{
    int arr[] = {6,7,8,9,10,1,2,5};
    int n=8;
    int key = 81;
    int i = searchInRotatedArray(arr,key,0,n-1);
    if(i==-1)cout<<"Key does not exist"<<endl;
    else cout<<"key exists at"<<i<<endl;
}
