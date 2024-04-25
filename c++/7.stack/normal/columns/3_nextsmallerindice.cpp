#include <bits/stdc++.h>
using namespace std;
vector<int> nextSmaller(vector<int> v)
{
    vector<int> ans;

    stack<int> s1;
    // s1.push(-1);
    s1.push(v.back());
    // cout<<-1<<" ";
    for (int i = v.size() - 1; i >= 0; i--) // for next least element just run the loop in reverse and create a new array to store and avoid the reverse print of the sequence
    {

        while (!(s1.empty()) && !(v[s1.top()] < v[i])) // for nearest previous greater element > sign , for nearest previous smaller element < sign
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
int main()
{
    vector<int> v1;
    // v1 = nextSmaller({3,10,5,1,15,10,7,6});
    // v1 = nextSmaller({3, 1, 2, 4});// ans = 1 4 4 4 
    v1 = nextSmaller({0,9});
    for (int i = v1.size() - 1; i >= 0; i--)
    {
        cout << v1[i] << " ";
    }

    return 0;
}