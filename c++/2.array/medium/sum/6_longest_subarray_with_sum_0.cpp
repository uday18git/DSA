#include <vector>
#include <bits/stdc++.h>
using namespace std;
// if same sum is repeating two times in a array that means in between them there was a 0 subarray in between
int getLongestZeroSumSubarrayLength(vector<int> &arr)
{
    // Write your code here.
    unordered_map<int, int> mp;
    int n = arr.size();
    int ans = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            ans = max(ans, 1);
        if (sum == 0)
            ans = max(ans, i + 1);
        sum += arr[i];
        if (mp.find(sum) != mp.end())
        {
            ans = max(ans, i - mp[sum]);
        }
        else
        {
            mp[sum] = i;
        }
    }
    return ans;
}