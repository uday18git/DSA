//========== DEQUEUE DOUBLE ENDED QUEUE===========//
// 1. PUSH AND POP FROM END
// 2. INSERT AND DELETE FROM THE START
// 3. HEADER FILE: <DEQUE>
#include<bits/stdc++.h>
using namespace std;
int main()

{
    deque<int> d1;
    d1.push_back(1);
    d1.push_back(3);
    d1.push_front(2);
    d1.push_front(4);
    for(auto i:d1)
    {
        cout<<i<<" ";
    }
    cout<<d1.size()<<endl;
    return 0;
}
