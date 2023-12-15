// #include "bits/stdc++.h"
// using namespace std;
// int main()
// // we are using multiset and u can also use max heap , its same brute force, deque is used for max optimization
// {   //=============== O(NLOGN) APPROACH ==============//
//     int n,k;cin>>n>>k;//n is the size of array k is window size
//     vector<int> a(n);
//     for(auto &i: a)
//         cin>>i;
//     multiset<int,greater<int>> s;//stores in descending orrder
//     vector<int> ans;
//     for(int i=0;i<k;i++)
//     {
//         s.insert(a[i]);
//     }// s will store in descending order so highest value will be at s.begin()
//     ans.push_back(*s.begin());//s.begin gives pointer not value so * we putted
//     for(int i=k;i<n;i++)
//     {
//         s.erase(s.lower_bound(a[i-k])); // as the window moves forward we have to remove the element from the set also , and lower bound because if u dont then all the elements equal to a[i-k] will be erased
//         s.insert(a[i]);
//         ans.push_back(*s.begin());
//     }
//     for(int i=0;i<ans.size();i++)
//     {
//         cout<<ans[i]<<" ";
//     }
//     // WE NEED TO ITERATE THROUGH FIRST K ELEMENTS SEPERATELY BECAUSE NO ELEMENTS ARE CURRENTLY THERE IN S SO FIRST WE ADD SOME ELEMENTS THEN DO THINGS
    
// }
//=======================O(N)=========================//
// using dq
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> ans;
        for(int i=0;i<k;i++) // inserting first 3 elements
        {
            while(!q.empty() && nums[q.back()]<nums[i])  // in non decreasing order
            {
                q.pop_back();
            }
            q.push_back(i);
        }
        ans.push_back(nums[q.front()]); // max element for first 3 will be in the front , because we maintained like that
        for(int i=k;i<nums.size();i++) // same for rest of elements
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