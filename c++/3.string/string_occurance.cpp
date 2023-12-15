// example
// string s= "na";
// string t="apna collegena";
// string s is found in t
// at index 2
// at index 12

// substr(pos,len) function
#include <bits/stdc++.h> 
using namespace std;
int main(){
    string s="na";
    string t="apna collegena";
    int S=s.size();
    int T=t.size();
    for(int i=0;i<T-S+1;i++)
    {
        if(t.substr(i,S)==s)
        {
            cout<<"Found at"<<i<<endl;
        }
    }
return 0;

}
// O(st)