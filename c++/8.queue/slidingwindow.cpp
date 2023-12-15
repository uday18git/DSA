//=============SLIDING WINDOW MAXIMUM=============//
//AN ARRAY WILL BE GIVEN AND AN K WILL BE GIVEN AND WE SHD FIND OUT MAXIMUM IN EACH K ELEMENTS;
#include<bits/stdc++.h> 
using namespace std;
void printkMax(int arr[],int n,int k)
{
    deque<int> q(k);
    for(int i=0;i<k;i++)
    {
        while(1){};
    }
}
int main(){
    int n,k;cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

return 0;
}


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> ans;
        for(int i=0;i<k;i++)
        {
            while(!q.empty() && nums[q.back()]<nums[i])
            {
                q.pop_back();
            }
            q.push_back(i);
        }
        ans.push_back(nums[q.front()]);
        for(int i=k;i<nums.size();i++)
        {
            if(q.front()== i-k)q.pop_front();
            while(!q.empty() && nums[q.back()]<nums[i])
            {
                q.pop_back();
            }
            q.push_back(i);
            ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};