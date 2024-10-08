// //problem, place elements to maximize the minimum distance
// //given is an array with n elements that represents n positions along a straight line. Find 
// // K elements such that the minimum distance between any 2 elements is the maximum possible.
// // APPROACH 1 BRUTE FORCE
// // FIND ALL POSSIBLE SUBSETS OF SIZE K AND COMPARE THE MINIMUM DISTANCE BETWEEN ALL OF THEM.
// // APPROACH 2 BINARY SEARCH
// // STEP 1 -> SORT THE ARRAY
// // STEP 2 -> PICK THE MIDDLE ELEMENT AS RESULT AND CHECK FOR FEASIBILITY.
// // STEP 3 -> IF FEASIBLE SEARCH THE RIGHT HALF OF THE ARRAY (FOR LARGER MINIMUM DISTANCE), ELSE SEARCH THE LEFT HALF

// // EXAMPLE {1,2,5,7,11,12} K=3 , ANSWER WILL BE 1,7,12 , so here minimum distance is 5 among the 3 elements

#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
// // logic of this function is start from arr[0] then if(arr[i]-pos >=mid)(the current difference value)then pos=arr[i] then elements++ , if (elements>=k)return true
// // else return false
// bool isFeasible(int arr[],int mid,int n,int k)
// {
//     int pos=arr[0],elements=1;
//     for(int i=1;i<n;i++)
//     {
//         if(arr[i]-pos >=mid)
//         {
//             pos=arr[i];
//             elements++;
//             if(elements>=k)
//             {
//                 return true;
//             }
//         }
//     }
//     return false;
// }
// int largestMinDistance(int arr[],int n,int k)
// {
//     sort(arr,arr+n);
//     int result = -1;
//     int left = 1,right=arr[n-1]; // we are finding the largestMinDistance using binary search here so low value will be 1
//     while(left<right)
//     {
//         int mid = (right+left)/2;
//         if(isFeasible(arr,mid,n,k))
//         {
//             result = max(result,mid);
//             left = mid+1;//because it is feasible and now we shd search a larger value
//         }
//         else
//         {
//             right=mid-1;
//         }
//     }
//     return result;
// }
// int main()
// {
//     int arr[] = {1,2,8,4,9};
//     int n=5;
//     int k=3;
//     cout<<largestMinDistance(arr,n,k)<<endl; //answer 3
//     return 0;
// }


bool isFeasible(vector<int> arr,int mid,int n,int k)
{
    int curr=arr[0];
    int elements=1;
    for(int i=1;i<n;i++)
    {
        if(arr[i]-curr>=mid)
        {
            curr=arr[i];
            elements++;
            if(elements>=k)
            {
                return true;
            }
        }
    }
    return false;


}

int largestMinDistance(vector<int> arr,int n,int k)
{
    int result=-1;
    sort(arr.begin(),arr.end());
    int start=0,end=arr[n-1];
    while(start<=end)
    {
        int mid = start+(end-start)/2;
        if(isFeasible(arr,mid,n,k))
        {
            result=max(result,mid);
            start=mid+1;
        }
        else
        {
            end=mid-1;
        }
    }
    return result;

}

int main()
{
    vector<int> arr = {1,2,8,4,9};
    int n=5;
    int k=3;
    cout<<largestMinDistance(arr,n,k)<<endl; //answer 3
    return 0;
}


// https://leetcode.com/problems/magnetic-force-between-two-balls/



class Solution {
public:
    bool isPossible(vector<int>&position,int &m,int ans)
    {
        int n=position.size();
        int prevIdx=0;
        int ballsPlaced=1;
        for(int i=1;i<n;i++)
        {
            if(position[i]-position[prevIdx] >=ans)
            {
                ballsPlaced++;
                prevIdx=i;
            }
        }
        return ballsPlaced>=m;
    }
    int maxDistance(vector<int>& position, int m) { //m is number of balls to put
        int low =1;
        sort(position.begin(),position.end());
        int n=position.size();
        int high=position[n-1]-position[0];
        int ans=0;
        while(low<=high)
        {
            int mid = high+(low-high)/2;
            if(isPossible(position,m,mid))
            {
                ans=max(mid,ans);
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        // n is the number of empty baskets
        return ans;
    }
};