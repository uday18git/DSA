#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmaller(vector<int> v)
{
    vector<int> ans;

    stack<int> s1;
    s1.push(v.size()-1);
    for (int i = v.size() - 1; i >= 0; i--)
    {

        while (!(s1.empty()) && !(v[s1.top()] < v[i]))
        {
            s1.pop();
        }
        if (s1.empty())
        {
            ans.push_back(v.size());
        }
        else
        {
            ans.push_back(s1.top());
        }
        s1.push(i);
    }
    return ans;
}
vector<int> prevSmaller(vector<int> v)
{
    vector<int> ans;

    stack<int> s1;
    s1.push(0);
    for (int i = 0; i < v.size(); i++)
    {

        while (!(s1.empty()) && (v[s1.top()] >= v[i]))
        {
            s1.pop();
        }
        if (s1.empty())
        {
            ans.push_back(-1);
        }
        else
        {
            ans.push_back(s1.top());
        }
        s1.push(i);
    }
    return ans;
}
int largestRectangleArea(vector<int> &heights)
{
    vector<int> ns, ps;
    int ans = 0;
    ns = nextSmaller(heights);
    ps = prevSmaller(heights);
    cout<<"ps"<< " ";
    for(int i=0;i<ps.size();i++)
    {

        cout<<ps[i]<<" ";
    }
    cout<<"ns"<< " ";
    for(int i=0;i<ns.size();i++)
    {

        cout<<ns[ns.size()-i-1]<<" ";
    }
    
    for (int i = 0; i < heights.size(); i++)
    {
        ans = max(ans, (ns[ns.size() - i - 1] - ps[i] - 1) * heights[i]);
    }
    return ans;
}
int main()
{
    vector<int> height = {0,9};
    int a = largestRectangleArea(height);
    cout<<a;
    return 0;
}