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