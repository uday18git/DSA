// arr = {1,1,2,3}
// sum = 1
// we have to assign signs(+/-) to each of the elements so that sum of the array should be
#include <bits/stdc++.h>
#include <vector>
using namespace std;
int main()
{

    vector<int> arr = {1, 1, 2, 3}; // ques
    int n = arr.size();
    int diff = 1; // ques
    int sum = 0;
    // expected answer 3
    for (const int &i : arr)
    {
        sum += i;
    }
    int s1 = (diff + sum) / 2;
    vector<vector<int>> dp(n + 1, vector<int>(s1 + 1));
    for (int i = 0; i < n + 1; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 0; i < s1 + 1; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < s1 + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[n][s1] << endl;

    return 0;
}

// solves edge cases on leet code

// class Solution {
// public:
//     int findTargetSumWays(vector<int>& nums, int target) {
//         int sum=0;
//         int n=nums.size();

//         for(int i:nums)
//         {
//             sum+=i;
//         }
//         if(sum < target) return 0;
//         if((sum+target)<0 || ((sum+target) % 2) != 0) return 0;
//         int s1 = (target+sum)/2;
//         vector<vector<int>> dp(n+1,vector<int>(s1+1,0));
//         for(int i=0;i<s1+1;i++)
//         {
//             dp[i][0] = 1;
//         }
//         for(int i=1;i<n+1;i++)
//         {
//             for(int j=1;j<s1+1;j++)
//             {
//                 if(nums[i-1]<=j)
//                 {
//                     dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
//                 }
//                 else
//                 {
//                     dp[i][j] = dp[i-1][j];
//                 }
//             }
//         }
//         return dp[n][s1];
//     }
// };

class Solution
{
public:
    int findTargetSumWays(vector<int> &a, int target)
    {

        // Edge case when only one element is present in array
        if (a.size() == 1)
        {

            if (abs(a[0]) == abs(target))
                return 1;
            else
                return 0;
        }

        // We will solve problem considering there is no zeroes in the input array, and we will deal with it in the last

        // To count the number of zeroes
        int z = 0;

        for (int i = 0; i < a.size(); i++)
            if (a[i] == 0)
                z++;

        int asum = accumulate(a.begin(), a.end(), 0);// sums the array , 0 is the initial value of sum

        // Because the sum of a subset can't be in decimals
        if ((asum + target) % 2 == 1)
            return 0;

        // This is the given sum, of which we have to find the number of count of subsets with sum equal to given sum
        int t = (asum + target) / 2;

        // Since we are dealing with only positive integers, so sum of a subset can't be negative
        if (t < 0)
            return 0;

        // DP Array
        int dp[a.size() + 1][t + 1];

        // Initialising DP Array
        for (int i = 0; i <= a.size(); i++)
        {
            for (int j = 0; j <= t; j++)
            {

                dp[i][j] = 0;

                if (i == 0)
                    dp[i][j] = 0;

                if (j == 0)
                    dp[i][j] = 1;
            }
        }

        for (int i = 1; i <= a.size(); i++)
        {
            for (int j = 1; j <= t; j++)
            {

                if (a[i - 1] == 0)
                    dp[i][j] = dp[i - 1][j];

                else if (a[i - 1] > j)
                    dp[i][j] = dp[i - 1][j];

                else
                    dp[i][j] = dp[i - 1][j - a[i - 1]] + dp[i - 1][j];
            }
        }

        // Each zero can be put in either of the partitions, so 2^z ways to do this
        return pow(2, z) * dp[a.size()][t];
    }
};