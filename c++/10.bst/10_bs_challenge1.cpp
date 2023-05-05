//problem
//given is an array with n elements that represents n positions along a straight line. Find K elements such that the minimum 
// distance between any 2 elements is the maximum possible.
// APPROACH 1 BRUTE FORCE
// FIND ALL POSSIBLE SUBSETS OF SIZE K AND COMPARE THE MINIMUM DISTANCE BETWEEN ALL OF THEM.
// APPROACH 2 BINARY SEARCH
// STEP 1 -> SORT THE ARRAY
// STEP 2 -> PICK THE MIDDLE ELEMENT AS RESULT AND CHECK FOR FEASIBILITY.
// STEP 3 -> IF FEASIBLE SEARCH THE RIGHT HALF OF THE ARRAY 
#include "bits/stdc++.h"
using namespace std;           //n is the length of the array //k is subset length which we need.
bool isFeasible(int mid,int arr[],int n,int k)
{
    //can k possible values be there in our n size array
    int pos = arr[0],elements = 1;//how many elements exist with minimum distance smtg
    for(int i=1;i<n;i++)
    {
        if(arr[i]-pos >=mid){
            pos = arr[i];
            elements++;
            if(elements==k)
            {
                return true;
            }

        }
    }
    return false;
}
int largestMinDistance(int arr[],int n,int k)
{
    sort(arr,arr+n);//sort our array
    int result = -1;
    int left =arr[0],right = arr[n-1];//range 
    while(left<right)//apply binary search
    {
        int mid = (left+right)/2;
        if(isFeasible(mid,arr,n,k))
        {
            result = max(result,mid);
            left=mid+1;//because it is feasible and now we shd search a larger value
        }
        else
        {
            right = mid;
        }
    }

    return result;
}
int main()
{
    int arr[] = {1,2,8,4,9};
    int n=5;
    int k=3;
    cout<<"Largest minimum distance is"<<largestMinDistance(arr,n,k)<<endl;
    return 0;
}