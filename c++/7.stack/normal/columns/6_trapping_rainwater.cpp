#include <bits/stdc++.h> 
using namespace std;

// THIS TRAPPING RAINWATER SOLUTION , YOU HAVE USED STACK REDUNDANTLY , IT CAN BE SIMPLY DONE EASILY 
// THIS WAS BECAUSE OF THE INFLUENCE OF THE PREVIOUS PROBLEM
class Solution {
public:
    vector<int> max_left(vector<int> v)
    {
        vector<int> ans;
        ans.push_back(-1);
        stack<int> s;
        for(int i=0;i<v.size();i++)
        {
            if(s.empty())
            {
                s.push(v[i]);
            }
            else if(v[i]<=s.top())
            {
                ans.push_back(s.top());
            }
            else
            {
                ans.push_back(s.top());
                s.pop();
                s.push(v[i]);
            }
        }
        return ans;
    }
    vector<int> max_right(vector<int> v)
    {
        vector<int> ans;
        ans.push_back(-1);
        stack<int> s;
        for(int i=v.size()-1;i>=0;i--)
        {
            if(s.empty())
            {
                s.push(v[i]);
            }
            else if(v[i]<=s.top())
            {
                ans.push_back(s.top());
            }
            else
            {
                ans.push_back(s.top());
                s.pop();
                s.push(v[i]);
            }
        }
    
        return ans;
    }
    int trap(vector<int>& height) {
        int trapped=0;
        vector<int> ans;
        vector<int> maxleft = max_left(height);
        vector<int> maxright = max_right(height);
        ans.push_back(0);
        for(int i=1;i<maxright.size()-1;i++)
        {
            ans.push_back(min(maxleft[i],maxright[maxright.size()-i-1])-height[i]);
        }
        ans.push_back(0);
        for(int i=0;i<maxright.size();i++)
        {
            if(ans[i]>0)
            {
                trapped+=ans[i];
            }
        }
        return trapped;
    }
};

// MORE OPTIMIZED BRUTE FORCE 
// ACTUALLY ITS NOT REALLY NEXT GREATER , IT IS GREATER TILL NOW, AND GREATER FROM NOW
// IF WE WANT NEXT GREATER / PREV GREATER WE SHOULD STACK 
#define vi vector<int>
class Solution {
public:
    vi prev(vi h)
    {
        int n=h.size();
        vi ans;
        ans.push_back(-1);
        int curr_max=h[0];
        for(int i=1;i<n;i++)
        {
            ans.push_back(curr_max);
            if(curr_max<h[i])
            {
                curr_max = h[i];
            }
        }
        return ans;
    }
    vi next(vi h)
    {
        int n=h.size();
        vi ans(n,-1);
        
        int curr_max=h[n-1];

        for(int i=n-2;i>=0;i--)
        {
            ans[i] = curr_max;
            if(curr_max<h[i])
            {
                curr_max = h[i];
            }
        }
        return ans;

    }
    int trap(vector<int>& height) {
        vi prev_max,next_max;
        prev_max = prev(height);
        next_max = next(height);
        int ans=0;
        int n=height.size();
        for(int i=0;i<n;i++)
        {
            int curr = min(prev_max[i],next_max[i]) - height[i] ;
            if(curr>0)
            {
                ans+=curr;
            }
        }
        return ans;

    }
};