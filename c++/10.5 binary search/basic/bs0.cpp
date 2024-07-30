#include "bits/stdc++.h"
using namespace std;
int main()
{
    const int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int key,mid;
    cin>>key;
    int s=0,e=n-1;
    while(s<=e)
    {
        mid = e+ (s-e)/2; // fancy version of writing this s+(e-s)/2; to avoid integer overflow
        if(a[mid]==key)
        {
            cout<<mid<<endl;
            break;
        }
        else if(a[mid]>key)
        {
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }
    }

return 0;
}
