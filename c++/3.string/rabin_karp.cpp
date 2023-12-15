// solves same problem as kmp
// p^i * hash[i...j] = hash[0..j] - hash[0..i-1]
// j-i+1 = S
// S is the size of our needle (needle haystack logic)/ pattern which we have to find
// so if(hash[i..j]==hash(s))
//    occurance is found at index i
//    hash[i..j] = (1/p^i)*(hash[0..j] - hash[0..i-1])
//    p^i * hash(s) must be equal to 
//                hash[0..j] - hash[0..i-1]
#include <bits/stdc++.h> 
using namespace std;
int p=31;
const int N = 1e5+7,m=1e9+7;
vector<long long> powers(N);
int32_t main(){
    string s= "na";
    string t="apnacollegena";
    int T = t.size(),S=s.size();
    powers[0]=1;
    for(int i=1;i<N;i++)
    {
        powers[i]=(powers[i-1]*p)%m;
    }
    vector<long long> h(T+1,0); // h[i] stores hash of the substring s[0..i]      
    for(int i=0;i<T;i++) // fills h
    {
        h[i+1] = (h[i]+(t[i]-'a'+1)*powers[i])%m;
    }
    long long h_s=0;
    for(int i=0;i<S;i++) // finds the hash of the string we are finding
    {
        h_s=(h_s+(s[i]-'a'+1)*powers[i])%m;
    }
    for(int i=0;i+S-1<T;i++) // finds the hash of the string we are finding in the h array
    {
        long long cur_h = (h[i+S]-h[i] +m)%m;// +m %m to keep it positive
        if(cur_h == (h_s*powers[i])%m) 
        {
            cout<<"found at "<<i<<endl;
        }
    }
return 0;
}