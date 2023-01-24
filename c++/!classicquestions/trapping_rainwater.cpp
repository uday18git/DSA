#include <bits/stdc++.h>
using namespace std;
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
int main()
{
    int trapped=0;
    vector<int> ans;
    vector<int> v = {3,1,2,4,0,1,3,2};
    vector<int> maxleft = max_left(v);
    vector<int> maxright = max_right(v);
    ans.push_back(0);
    for(int i=1;i<maxright.size()-1;i++)
    {
        // cout<<maxright[maxright.size()-i-1]<<" ";
        ans.push_back(min(maxleft[i],maxright[maxright.size()-i-1])-v[i]);

    }
    ans.push_back(0);
    for(int i=0;i<maxright.size();i++)
    {
        if(ans[i]>0)
        {
            trapped+=ans[i];
        }
        // cout<<maxright[maxright.size()-i-1]<<" ";
        // ans.push_back(min(maxleft[i],maxright[i])-v[i]);
        cout<<ans[i];


    }
    cout<<endl;
    cout<<trapped<<endl;
    return 0;
}