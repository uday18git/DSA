// minimum and maximum difference
// problem -> you are given an array,A,of n elements. You have to remove exactly n/2 elements(any) from array A and add it to another array B (initially empty).
// Find the maximum and minimum values of differences between these two arrays.
// Defining the difference between two arrays as: sumation(abs(A[i]-B[i]))
// test case
// input
// 4
// 12 -3 10 0
// output : 5 25
// maximum difference A: -3 0
//                    B: 12 10
// minimum difference A: -3 12
//                    B: 0 10
// constraints
// 1<=n<=10^5
// |Ai|<=10^9 you might use int but the difference might come which you cant store in int 2e9 is integer range
// thought process
// to maximize abs(A[i]-A[j])
// A[i] should be as large as possible
// A[j] should be as small as possible
// to minimize abs(A[i]-A[j])
// A[i] should be as small as possible
// A[j] shoudl be as large as possible
// wont work for minimizing as it is absolute
// so we will have to see that A[i] is as close as possible to A[j]
// maximum diff = after simplifying (A[n-1]+A[n-2].....A[n/2])-(A[0]+A[1]+....A[n/2-1])
// minimum diff = A[1]-A[0]+A[3]-A[2]......
// (sum of odd indices)-(sum of even indices)
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    long long mn=0,mx=0;
    for(int i=0;i<n/2;i++)
    {
        mx+=(v[i+n/2]-v[i]);
        mn+=(v[2*i+1]-v[2*i]);
    }
    cout<<mx<<" "<<mn;    
    return 0;
}