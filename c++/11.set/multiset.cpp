#include "bits/stdc++.h"
// #include <set>
// multiple same elements are possible
using namespace std;
int main()
{
    multiset<int> s;//multi set stores in ascending order
    multiset<int,greater<int>> s1;//stores in descending order
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(3);
    s.insert(3);
    // set<int,greater<int>> s; // stores integers in descending order
    // s.insert(1);
    // s.insert(2);
    // s.insert(3);
    // s.insert(3);
    // s.insert(3);

   
    // s.erase(3);all 3 will be deleted
    s.erase(s.lower_bound(2));//one 3 will be erased
    //s.upper_bound deletes the next element of 2
    //s.lower_bound deletes the element only
     for(auto i:s)
        cout<<i<<" ";
}