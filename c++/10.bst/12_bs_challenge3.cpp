// PAINTERS PARTITION PROBLEM //
#include "bits/stdc++.h"
using namespace std;
// n is the number of boards,m is the number of painters
// A painter paints 1 unit of board in 1 unit of time and each painter will paint consecutive 
// boards find the minimum time that will be required to paint all the boards,
// so we have to find the minimum possible maximum partition, so if  that is minimum then 
bool isPossible(int arr[],int n,int m,int min)
{
    int paintersRequired=1,sum=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>min)
        {
            return false;
        }
        if(arr[i]+sum>min)
        {
            paintersRequired++;
            sum=arr[i];
            if(paintersRequired>m)
            {
                return false;
            }
        }
        else
        {
            sum+=arr[i];
        }
    }
    return true;
}
int paintersPartition(int arr[],int n,int m)
{

    if(n<m)return -1;
    int sum=0;
    int ans=INT_MAX;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    int left=0,right=sum;// left=arr[n-1] also u can take more efficient
    while(left<right)
    {
        int mid=(left+right)/2;
        if(isPossible(arr,n,m,mid))
        {
            ans=min(mid,ans);
            right=mid-1;
        }
        else
        {
            left=mid+1;
        }
    }
    return ans;
}

int main()
{
    int arr[] = {10, 20, 30, 40};
    int m = 2;
    int n = 4;
    cout << "minimum allocated maximum boards length for a painter : " << paintersPartition(arr, n, m) << endl; //answer 60
    return 0;
}


bool isPossible(int arr[], int boards, int  painters, int mid)
{
    int sum = 0, paintersRequired = 1;
    for (int i = 0; i < boards; i++)
    {
        if (arr[i] > mid)
        {
            return false;
        }
        else if (arr[i] + sum > mid)
        {
            sum = arr[i];
            paintersRequired++;
            if (paintersRequired > painters)
            {
                return false;
            }
        }
        else
        {
            sum += arr[i];
        }
    }
    return true;
}
int paintersPartition(int arr[], int n, int m)
{
    if (n < m)
        return -1;
    int sum = 0;
    
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    int start = arr[n - 1], end = sum,ans = INT_MAX;;
    while (start <= end)
    {

        int mid = start + (end - start) / 2;
        if (isPossible(arr, n, m, mid))
        {
            ans = min(mid, ans);
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}
int main()
{
    int arr[] = {10, 20, 30, 40};
    int m = 2;
    int n = 4;
    cout << "minimum allocated maximum boards length for a painter : " << paintersPartition(arr, n, m) << endl;
    return 0;
}
