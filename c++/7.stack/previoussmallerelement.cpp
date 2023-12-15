//=========NORMAL VERSION WHICH GIVES ARRAY WITH THE ACTUAL ELEMENTS NOT INDICES =========//
//steps
// traverse from the start
// see if stack is empty put -1 for that because there is no prev smaller element for it
// compare curr element with stacks top , if its less we found our prev smaller element
// if its greater then keep popping until its lesser or empty

#include <iostream>
#include <stack>
#include <vector>
using namespace std;
vector<int> prevSmaller(vector<int> v)
{
    vector<int> ans; // using a different array to avoid inconvenience

    stack<int> s1;
    // s1.push(-1);
    s1.push(v[0]);
    // cout<<-1<<" ";
    for (int i = 0; i < v.size(); i++) // for next least element just run the loop in reverse and create a new array to store and avoid the reverse print of the sequence
    {

        while (!(s1.empty()) && (s1.top() >= v[i])) // for nearest previous greater element > sign , for nearest previous smaller element < sign
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
        s1.push(v[i]);

    }
    return ans;
}
int main()
{
    vector<int> v1;
    v1 = prevSmaller({4, 10, 5, 18, 3, 12, 7});
    // ans for this is -1 4 4 5 -1 3 3
    // v1 = prevSmaller({3,1,2,4});
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }

    return 0;
}

// variant of this is previous greater element same approach 
// for previous ones we are iterating from start and for the next ones we are iterating from the last
