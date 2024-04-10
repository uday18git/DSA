// PAINTERS PARTITION PROBLEM //
#include "bits/stdc++.h"
using namespace std;
// n is the number of boards,m is the number of painters
// A painter paints 1 unit of board in 1 unit of time and each painter will paint consecutive boards
// find the minimum time that will be required to paint all the boards,
// so we have to find the minimum possible maximum partition
// this is the difference and we have to modify like our search space becomes different

// bool isPossible(int arr[],int n,int m,int min)
// {
//     int paintersRequired=1,sum=0;
//     for(int i=0;i<n;i++)
//     {
//         if(arr[i]>min)
//         {
//             return false;
//         }
//         if(arr[i]+sum>min)
//         {
//             paintersRequired++;
//             sum=arr[i];
//             if(paintersRequired>m)
//             {
//                 return false;
//             }
//         }
//         else
//         {
//             sum+=arr[i];
//         }
//     }
//     return true;
// }
// int paintersPartition(int arr[],int n,int m)
// {

//     if(n<m)return -1;
//     int sum=0;
//     int ans=INT_MAX;
//     for(int i=0;i<n;i++)
//     {
//         sum+=arr[i];
//     }
//     int left=0,right=sum;// left=arr[n-1] also u can take more efficient
//     while(left<right)
//     {
//         int mid=(left+right)/2;
//         if(isPossible(arr,n,m,mid))
//         {
//             ans=min(mid,ans);
//             right=mid-1;
//         }
//         else
//         {
//             left=mid+1;
//         }
//     }
//     return ans;
// }
// the above solution is the one i thought would be the answer and wrote it but its the wrong answer below is the correct answer
// this is not exactly same as the previous one

int findFeasible(int boards[], int n, int limit)
{
    int sum = 0, painters = 1;
    for (int i = 0; i < n; i++)
    {
        sum += boards[i];
        if (sum > limit)
        {
            sum = boards[i];
            painters++;
        }
    }
    return painters;
}
// n different boards //m painters available
int paintersPartition(int boards[], int n, int m)
{
    int totalLength = 0, k = 0;
    for (int i = 0; i < n; i++)
    {
        k = max(k, boards[i]);
        totalLength += boards[i];
    }
    int low = k, high = totalLength;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int painters = findFeasible(boards, n, mid);
        if (painters <= m)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

int main()
{
    int arr[] = {10, 20, 30, 40};
    int n = 4;
    int m = 2;
    cout << "minimum allocated maximum boards length for a painter : " << paintersPartition(arr, n, m) << endl; // answer 60
    return 0;
}

// KOKO EATING PROBLEM

class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int sum = 0;
        sort(piles.begin(), piles.end());
        int n = piles.size();
        for (int i = 0; i < n; i++)
        {
            sum += piles[i];
        }
        int ans = INT_MAX;
        int start = piles[n - 1], end = sum;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (mid * h >= sum)
            {
                ans = min(ans, mid);
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return ans;
    }
};

// SPLIT ARRAY LARGEST SUM
// SAME CONCEPT AS PAINTERS PARTITION PROBLEM
// minimize the maximum sum
class Solution
{
public:
    bool canSplit(vector<int> nums, int n, int k, int mid)
    {
        int splits = 1;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            if (sum > mid)
            {
                sum = nums[i];
                splits++;
                if (splits > k)
                    return false;
            }
        }
        return true;
    }

    int splitArray(vector<int> &nums, int k)
    {
        int n = nums.size();
        int start = *max_element(nums.begin(), nums.end());
        int end = accumulate(nums.begin(), nums.end(), 0);
        int ans = INT_MAX;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (canSplit(nums, n, k, mid))
            {
                ans = min(ans, mid);
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return ans;
    }
};