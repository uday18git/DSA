//CAN K SIZE SUBARRAY IN THE ARRAY FORM A NUMBER DIVISIBLE BY 3
// 8 23 45 12 56 4
// IF K IS 3 
// IN THE ARRAY ANSWER WILL BE 12564
// FACT=> ADDITION OF NUMBERS OF A NUMBER DIVISIBLE BY 3 IS ALSO DIVISIBLE BY 3
#include <bits/stdc++.h> 
using namespace std;
int main(){
    int n,k;cin>>n>>k;//n is the size of array k is window size
    vector<int> a(n);
    for(auto &i: a)
        cin>>i;
    int sum=0;
    int ans=0;
    for(int i=0;i<k;i++)
    {
        int m = a[i];
        while(m)
        {
            int rem = m%10;
            sum+=rem;
            m/=10;
        }
        if(sum%3==0)ans=1;
    }
    for(int i=k;i<n;i++)
    {
        int m = a[i];
        sum-=m;
        while(m)
        {
            int rem = m%10;
            sum+=rem;
            m/=10;
        }
        if(sum%3==0)ans=1;
    }

return 0;
}