#include <bits/stdc++.h> 
using namespace std;
// for previous ones we are iterating from start and for the next ones we are iterating from the last

// approach variant 1-> normal array
// start traversing from last
// compare current element with stacks top
// if it is greater then it is its next greater element
// if it is smaller then keep popping until its smaller
// this works because the elements being popped cannot be greater for any because as the current element is greater than them right 
// if the stacks not empty then modify the nge[i] as st.top();
// done
int main(){

return 0;
}

// variant 2 -> circular array
// so we traverse from 2n-1 to 0 we are duplicating the array and putting it at the back
// and use i%n no need to actually put back the array

// this is other variant
// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         int n=nums2.size();
//         int m=nums1.size();
//         vector<int> ans(m,-1);
//         // vector<int> nge(n,-1);
//         // map will be better
//         unordered_map<int,int>numberToGreater;
//         stack<int> s;
//         for(int i=0;i<n;i++)
//         {
//             while(!s.empty() && s.top()<nums2[i])
//             {
//                 s.pop();
//             }
//             if(!s.empty())numberToGreater[nums2[i]]=s.top();
//             s.push(nums2[i]);
//         }
//         for(int i=0;i<m;i++)
//         {
//             const auto it = numberToGreater.find(nums1[i]);
//             if(it != numberToGreater.end())
//             {
//                 ans[i]=numberToGreater[nums1[i]];
//             }
//         }
//         return ans;
//         // now nge is filled
        
//     }
// };