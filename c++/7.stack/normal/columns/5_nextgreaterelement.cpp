#include <bits/stdc++.h> 
using namespace std;
// for previous ones we are iterating from start and for the next ones, here we are iterating from the last

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
#define vi vector<int>
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vi ans(n,0);
        
        stack<int> s;
        for(int i=2*n-1;i>=0;i--)
        {
            while(!s.empty() && nums[i%n]>=s.top())
            {
                s.pop();
            }
            if(i<n)
            {
                if(!s.empty())
                {
                    ans[i] = s.top();
                }
                else
                {
                    ans[i] = -1;
                }
            }
            s.push(nums[i%n]);
        }
        return ans;

    }
};