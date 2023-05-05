#include "bits/stdc++.h"
using namespace std;
#include <unordered_set>
//implemented using hashing
//contains unique elements only
//advantage is in time complexities insertion and deletion
int main()
{
    unordered_set<int> s;
    s.insert(1);
    s.insert(3);
    s.insert(2);
    s.insert(5);
    // s.insert(1);
    for(auto i:s)
        cout<<i<<" ";
    s.erase(2);
    s.erase(s.begin());
    return 0;
}