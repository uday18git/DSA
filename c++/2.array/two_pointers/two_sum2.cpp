#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0;
        int r=numbers.size()-1;
        while(l<r)
        {
            int curr = numbers[l]+numbers[r];
            if(curr==target)
            {
                return {l+1,r+1};
            }
            else if(curr>target)
            {
                r--;
            }
            else
            {
                l++;
            }
        }   
        return {-1,-1};
    }
};

int main()
{
    Solution s;
    vector<int> v = {2,7,11,15};
    vector<int> ans = s.twoSum(v,9);
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
}