// maximum subarray sum
// arr[] = {-2,-3,4,-1,-2,1,5,-3}
#include <bits/stdc++.h> 
using namespace std;


// brute force approach 
// we will try out all the subarrays
// int main(){
//     vector<int> a = {-2,-3,4,-1,-2,1,5,-3};
//     int ans = 0,curr=0;
//     int n = a.size();
//     for(int i=0;i<n;i++)
//     {
//         curr=0;
//         for(int j=i;j<n;j++)
//         {
//             curr+=a[j];
//             ans = max(ans,curr);
//         }
//     }
//     cout<<ans;
// return 0;
// }

// optimal kadanes algo
// int main()
// {
//     vector<int> a = {-2,-3,4,-1,-2,1,5,-3};
//     int curr=0;
//     int ans=INT_MIN;
//     int n=a.size();
//     for(int i=0;i<n;i++)
//     {
//         curr+=a[i];
//         ans=max(ans,curr);
//         if(curr<0)
//         {
//             curr=0;
//         }
//     }
//     cout<<ans; 
//     return 0;
// }


// if we have to print the subarray

int main()
{
    vector<int> a = {-2,-3,4,-1,-2,1,5,-3};
    int curr=0;
    int ans=INT_MIN;
    int start=0;
    int ansstart,ansend;
    int n=a.size();
    vector<int> x =a;
    // for(int num:x)cout<<num;
    for(int i=0;i<n;i++)
    {
        if(curr==0)start=i; // important observation , that whenever currsum=0 then we are starting a new possible ans
        curr+=a[i];
        // ans=max(ans,curr);
        if(curr>ans)
        {
            ans=curr;
            ansstart=start;
            ansend=i;
        }
        if(curr<0)
        {
            curr=0;
        }
    }
    cout<<ans<<endl; 
    for(int i=ansstart;i<=ansend;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}



// we have to take till its not negative


// simple answer

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n= nums.size();
        int currsum=nums[0];
        int ans=nums[0];
        for(int i=1;i<n;i++)
        {
            if(currsum<0)
            {
                currsum=0;
            }
            currsum+=nums[i];
            ans=max(ans,currsum);
        }
        return ans;
    }
};