// PAINTERS PARTITION PROBLEM //
#include "bits/stdc++.h"
using namespace std;
// n is the number of boards,m is the number of painters
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