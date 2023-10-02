//problem, place elements to maximize the minimum distance
//given is an array with n elements that represents n positions along a straight line. Find 
// K elements such that the minimum distance between any 2 elements is the maximum possible.
// APPROACH 1 BRUTE FORCE
// FIND ALL POSSIBLE SUBSETS OF SIZE K AND COMPARE THE MINIMUM DISTANCE BETWEEN ALL OF THEM.
// APPROACH 2 BINARY SEARCH
// STEP 1 -> SORT THE ARRAY
// STEP 2 -> PICK THE MIDDLE ELEMENT AS RESULT AND CHECK FOR FEASIBILITY.
// STEP 3 -> IF FEASIBLE SEARCH THE RIGHT HALF OF THE ARRAY
#include <algorithm>
#include <iostream>
using namespace std;
bool isFeasible(int arr[],int mid,int n,int k)
{
    int pos=arr[0],elements=1;
    for(int i=1;i<n;i++)
    {
        if(arr[i]-pos >=mid)
        {
            pos=arr[i];
            elements++;
            if(elements>=k)
            {
                return true;
            }
        }
    }
    return false;
}
int largestMinDistance(int arr[],int n,int k)
{
    sort(arr,arr+n);
    int result = -1;
    int left = 1,right=arr[n-1]; // we are finding the largestMinDistance using binary search here so low value will be 1
    while(left<right)
    {
        int mid = (right+left)/2;
        if(isFeasible(arr,mid,n,k))
        {
            result = max(result,mid);
            left = mid+1;//because it is feasible and now we shd search a larger value
        }
        else
        {
            right=mid-1;
        }
    }
    return result;
}
int main()
{
    int arr[] = {1,2,8,4,9};
    int n=5;
    int k=3;
    cout<<largestMinDistance(arr,n,k)<<endl; //answer 3
    return 0;
}

