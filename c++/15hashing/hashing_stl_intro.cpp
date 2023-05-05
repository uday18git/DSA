// maps and unordered maps
//               maps                 unordered maps
// insertion -> O(LOG(N))                  O(1)
// accessing -> O(LOG(N))                  O(1)
// implementing: red black trees        hash tables(basically array of buckets)
//        map<int,int> mp;          unordered_map<int,int> ump
//        ascending order                   no order
#include <bits/stdc++.h>
using namespace std;
int main()
{
    map<int,int> m; //key->value
    m[8]=2;
    cout<<m[8]<<endl;

    return 0;
}