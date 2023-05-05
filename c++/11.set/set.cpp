#include "bits/stdc++.h"
#include <set>
//ordered set --> unique elements
//implemented as balanced bst
//random access is not possible , you cannot get i'th element
using namespace std;
int main()
{
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(3);
    s.insert(3);
    set<int,greater<int>> s1; //stores integers in descending order
    for(auto i:s)
        cout<<i<<" ";
    cout<<"\n";
    for(auto i=s.begin();i!=s.end();i++)
        cout<<*i<<" ";
    cout<<endl;    
    for(auto i=s.rbegin();i!=s.rend();i++)//reverse print
        cout<<*i<<" ";
    cout<<endl;    
    cout<<s.size();
    s.erase(s.begin());
    s.erase(2);
    return 0;
}