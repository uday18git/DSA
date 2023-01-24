#include<iostream>
#include<climits>
#include<vector>
//iterate through all the sub arrays and find sum of all and find max sum.
using namespace std;
//BRUTE FORCE
// int main(){
// int n;
// int m = INT_MIN;
// cin>>n;
// int arr[n];
// for(int i=0;i<n;i++)
// {
//     cin>>arr[i];
// }
// for(int i=0;i<n;i++)
// {
//     int sum=0;
//     for(int j=i;j<n;j++)
//     {
//         sum+=arr[j];
        
//         m = max(sum,m);
//     }
// }
// cout<<m<<endl;
// return 0;
// }

//OPTIMISED CUMULATIVE SUM APPROACH
// int main()
// {
//     int n;
//     cin>>n;
//     int a[n];
//     for(int i=0;i<n;i++)
//     {
//         cin>>a[i];
//     }
//     int sum[n];
//     sum[0]=0;
//     for(int j=0;j<=n;j++)
//     {
//         sum[j+1]=sum[j]+a[j];
//     }
//     int ans = INT_MIN;
//     for(int i=1;i<=n;i++)
//     {
//         int temp=0;
//         for(int j=0;j<i;j++)
//         {
//             temp = sum[i]-sum[j];
//             ans = max(ans,temp);
//         }
//     }cout<<ans<<endl;

// }
// KEDANE'S ALGORITHM
// int main()
// {
//     int n;
//     cin>>n;
//     int a[n];
//     for(int i=0;i<n;i++)
//     {
//         cin>>a[i];
//     }
//     int currSum=0;
//     int maxSum=INT_MIN;
//     for(int i=0;i<n;i++)
//     {
//         currSum+=a[i];
//         if(currSum<0)
//         {
//             currSum=0;
//         }
//         maxSum=max(maxSum,currSum);
//     }
//     cout<<maxSum;
// }
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN;
        int currentsum = 0;
        for(int i=0;i<nums.size();i++)
        {
            currentsum = max(nums[i],currentsum+nums[i]);
            
            max_sum=max(max_sum,currentsum);
        }
        return max_sum;
    }
};