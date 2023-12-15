// find the number of unique strings
#include <bits/stdc++.h>
using namespace std;
// brute force approach
// int main(){
//     vector<string> strings = {"aa","ab","aa","b","cc","aa"}; // expected answer 4
//     int distinct=0;
//     // O(nmlog(n)) where m is the string size, string comparision is taking m time extra
//     sort(strings.begin(),strings.end());
//     for(int i=0;i<strings.size();i++)
//     {
//         if(i==0 || strings[i]!=strings[i-1])
//         {
//             distinct++;
//         }
//     }
//     cout<<distinct<<endl;
// return 0;
// }
// we can use hashing to reduce this time

int p = 31;                         // p is a prime number
const int N = 1e5 + 3, m = 1e9 + 7; // m is a large prime that serves as the modulo to keep the hash within a reasonable range and avoid overflow.
vector<long long> powers(N);

long long calculate_hash(string s)
{
    long long hash = 0;
    for (int i = 0; i < s.size(); i++)
    {
        hash = (hash + (s[i] - 'a' + 1) * powers[i]) % m;
    }
    return hash;
}
// chances of collisions are 1/1e9+7
// different numbers having same hash
// time complexity (nm + nlogn)
int32_t main()
{
    powers[0] = 1;
    for (int i = 1; i < N; i++)
    {
        powers[i] = (powers[i - 1] * p) % m;
    }
    vector<string> strings = {"aa", "ab", "aa", "b", "cc", "aa"}; // expected answer 4
    vector<long long> hashes;
    int distinct = 0;
    for (auto w : strings)
    {
        hashes.push_back(calculate_hash(w));
    }
    sort(hashes.begin(), hashes.end());
    for (int i = 0; i < hashes.size(); i++)
    {
        if (i == 0 || hashes[i] != hashes[i - 1])
        {
            distinct++;
        }
    }
    cout << distinct;
}

// hash = (s[0]×p^0 + s[1]×p^1 +…+ s[n−1]×p^n−1) modm

// For the given vector of strings :

// "aa" hash =(1×p^0 +1× p^1)mod(m)

// The resulting vector hashes would be :
// [hash1, hash2, hash1, hash3, hash4, hash1]
// After sorting the hashes vector, the code counts the number of distinct hash values, giving the final result.
// In this example, the expected answer is 4 because there are four distinct hash values.